import serial as s

arduino = None

arduino = s.Serial("COM6", baudrate=9600, timeout=1)

lista = []
totlecturas = 30
i = 0
while i < totlecturas:
    cadena = arduino.readline()
    #print(cadena)  ## imprime como.... b'419\r\n'
    cadena = cadena.decode()
    #print(cadena)  ## imprime como...419 con saltos de linea entre impresion
    cadena = cadena.replace("\n","")
    cadena = cadena.replace("\r", "")
    #print(cadena)  ##<<----
    if cadena!="":
        lista.append(cadena)
        i+=1

lista = list(map(int, lista))
print(lista)

archivo = open("../Archivos/P_4_SendDP_ValMayor.cvs", "w")

for lectura in lista:#
    #print(lectura)
    archivo.write(str(lectura) + ",")


archivo.flush()
archivo.close()