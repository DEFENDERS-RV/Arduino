
import serial as s   #pyserial

arduino = None 

arduino = s.Serial("COM5", baudrate=9600, timeout=1)


while True:
    cadena = arduino.readline()
    #print(cadena)  ## imprime como.... b'419\r\n'
    cadena = cadena.decode()
    #print(cadena)  ## imprime como...419 con saltos de linea entre impresion
    cadena = cadena.replace("\n","")
    cadena = cadena.replace("\r", "")
    print(cadena * 3 )  ##<<----
