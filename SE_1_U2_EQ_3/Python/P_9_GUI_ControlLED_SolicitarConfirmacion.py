import sys
import serial as conectaX

from PyQt5 import uic, QtWidgets, QtCore

qtCreatorFile = "P_8_GUI_ControlLED_confirmacion.ui"  # Nombre del archivo aquí.

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

        self.btn_control_led.clicked.connect(self.control_led)

        self.segundoPlane = QtCore.QTimer()
        self.segundoPlane.timeout.connect(self.control)

    # Área de los Slots
    def control_led(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                texto = self.btn_control_led.text()
                if texto == "PRENDER":
                    self.btn_control_led.setText("APAGAR")
                    action = "1".encode()
                    self.arduino.write(action)
                else:
                    self.btn_control_led.setText("PRENDER")
                    self.arduino.write("0".encode())


    def control(self):
        try:
            if self.arduino.inWaiting(): #Serial.available()>0
                valor = self.arduino.readline().decode()
                valor = valor.replace("\r","")
                valor = valor.replace("\n","")
                if valor != "": #Solo agregamos cadenas que no esten vacias
                    print(valor) #consola
                    self.lw_datos.addItem(valor) #string
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
