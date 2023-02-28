import sys
import serial as conectaX

from PyQt5 import uic, QtWidgets, QtCore

qtCreatorFile = "P_10hastaXX_SerializacioSensores.ui"  # Nombre del archivo aquí.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        # Área de los Signals
        self.txt_puerto.setText("COM6")
        self.arduino = None
        self.btn_accion.clicked.connect(self.accion)

        #control_led = control de actuadores...
        self.btn_control_led.clicked.connect(self.control_led)
        self.btn_control_led.setText("ENVIAR")

        self.segundoPlane = QtCore.QTimer()
        self.segundoPlane.timeout.connect(self.control)

    # Área de los Slots
    def control_led(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                #1. Leer desde el arduino la informacion de los sensores (programa 10)

                #2. Procesar los datos para tomar una decision

                #3. Enviar la decision tomada a arduino...
                a = 1
                b = 10
                c = 220
                #PWM = [0 - 255]
                actuador1 = str(a)
                actuador2 = str(b)
                actuador3 = str(c)

                actuador1 = "0" * (3-len(actuador1)) + actuador1
                actuador2 = "0" * (3-len(actuador2)) + actuador2
                actuador3 = "0" * (3-len(actuador3)) + actuador3

                cadena = "E" + actuador1 + "R" + \
                    actuador2 + "R" + actuador3 + "J"
                print(cadena)
                # E1R10R220J --> E001R010R220J

                self.arduino.write(cadena.encode())

    def control(self):
        try:
            if self.arduino.inWaiting(): #Serial.available()>0
                valor = self.arduino.readline().decode()
                valor = valor.replace("\r","")
                valor = valor.replace("\n","")
                if valor != "": #Solo agregamos cadenas que no esten vacias
                    print(valor) #consola

                    if valor[0] == "E" and valor[-1] == "C": #Cambiar a J o C
                        #valor.split()
                        subCadena = valor[1:len(valor)-1]
                        datos = subCadena.split("R")
                        cadena = datos[0] + " A " + datos[1] + " A " + datos[2]
                        #pass

                    self.lw_datos.addItem(cadena) #string
                    self.lw_datos.setCurrentRow(self.lw_datos.count()-1)
        except Exception as error:
            print(error)

    def accion(self):
        try:
            if self.arduino == None:
                puerto = self.txt_puerto.text()
                self.arduino = conectaX.Serial(puerto, baudrate=9600, timeout=1)
                self.btn_accion.setText("DESCONECTAR")
                self.txt_estado.setText("CONECTADO")
                self.segundoPlane.start(10)
            elif self.arduino.isOpen():
                self.segundoPlane.stop()
                self.arduino.close()
                self.btn_accion.setText("CONECTAR")
                self.txt_estado.setText("DESCONECTADO")
            else:
                self.arduino.open()
                self.btn_accion.setText("DESCONECTAR")
                self.txt_estado.setText("CONECTADO")
                self.segundoPlane.start(10)
        except Exception as error:
            print(error)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())
