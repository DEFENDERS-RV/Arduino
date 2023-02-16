import sys

import serial as conectaX #para trabajar con Arduino

from PyQt5 import uic, QtWidgets , QtCore

qtCreatorFile = "P_6_GUI_Python_Arduino.ui"  # Nombre del archivo aquí.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        self.txt_puerto.settext("")

        # Área de los Signals
        self.arduino = None
        self.btn_accion.cliked.connect(self.accion)
        self.segundoPlano = QtCore.QTimer()
        self.segundoPlano.timeout.connect(self.control)




    # Área de los Slots

    def control(self):
        try:
            valor = self.arduino.readline().decode()
            valor = valor.replace("\r" , "")
            valor = valor.replace("\n" , "")
            print(valor)
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
                self.segundoPlano.start(100)
        except Exception as error:
            print(error)



if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())

