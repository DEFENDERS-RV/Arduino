import sys

import serial as conectaX #para trabajar con Arduino

from PyQt5 import uic, QtWidgets , QtCore

qtCreatorFile = "P_11_GUI_Python_Arduino.ui"  # Nombre del archivo aquí.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        #self.txt_puerto.settext("")

        # Área de los Signals
        self.arduino = None
        #control led = control dde actuadores...
        self.btn_accion.cliked.connect(self.accion)

        self.btn_accion.cliked.connect(self.control_led)
        self.btn_control_led.setText("ENVIAR")
        self.segundoPlano = QtCore.QTimer()
        self.segundoPlano.timeout.connect(self.control)




    # Área de los Slots
    def control_led(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                #1.- Leer desde el arduino la informacion de los sensores
                #2.- Procesar los datos para tomar una decision
                a = 1
                b = 10
                c = 220
                #3.- Enviar la descion tomada a arduino ....

                #PWM = [0-255]
                actuador1 = str(1)
                actuador2 = str(10)
                actuador3 = str(220)

                actuador1 = "0" * (3-len(actuador1)) + actuador1
                actuador2 = "0" * (3 - len(actuador2)) + actuador2
                actuador3 = "0" * (3 - len(actuador3)) + actuador3


                cadena = "E" + str(actuador1) + "R" +\
                               str(actuador2) + "R" + str(actuador3) + "J"

                print(cadena)
                # ER10R220J pasara de esto ---> E001R010R220J
                self.arduino.write(cadena.encode())



    def control(self):
        try:
            # estamos leyendo pero puede que no haya nada.
            if self.arduino.inWaiting(): #Seiral.avaible() > 0
                valor = self.arduino.readline().decode() #arduino le esta mandando informacion , pero no a la misma velocidad que python
                valor = valor.replace("\r" , "")
                valor = valor.replace("\n" , "")
                if valor!= "":
                    print(valor)
                    self.lw_datos.addItem(valor) #str
                    #currentRow ...
                    self.lw_datos.setCurrentRow(self.lw_datos.count()-1) #str
                    print(valor)#imprime a consola

                    if valor[0] == "E" and valor [-1] == "J":
                        pass


                    #self.lw_datos.addItem(valor)
                    #self.lw_datos.currentRow(self.lw_datos.count()-1)
        except Exception as error:
            print(error)


    def accion(self):
        try:
            if self.arduino == None:
                puerto = self.txt_puerto.text()
                self.arduino = conectaX.Serial(puerto , baudrate = 9600 , timeout = 1)
                self.btn_accion.setText("DESCONECTAR")
                self.btn_accion.setText("Conectado")
                self.segundoPlano.start(100)
            elif self.arduino.isOpen():
                self.segundoPlano.stop()
                self.arduino.close()
                self.btn_accion.setText("CONECTAR")
                self.txt_estado.setText("DESCONECTADO")
            else:
                self.arduino.open()
                self.btn_accion.setText("CONECTAR")
                self.btn_accion.setText("DESCONECTAR")
                #SSself.segundoPlano.start(100)
        except Exception as error:
            print(error)



if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())

