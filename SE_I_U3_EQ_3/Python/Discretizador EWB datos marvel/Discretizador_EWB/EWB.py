import csv

archivo = open("marvel_completa.csv")
#archivo = open("wine.csv")
contenido = archivo.readlines()
#############################################################################################
instancia = []
for i in contenido:
    instancia.append(i.split(","))
encabezados = instancia[0]
del instancia[0]  ##encabezados
#############################################################################################
###GRUPOS A GENERAR
v_K = 6    # Pagina de referencia comparativa ->>>>  https://orange.readthedocs.io/en/latest/reference/rst/Orange.feature.discretization.html#Orange.feature.discretization.Discretization
#############################################################################################
intervalos = []
for index_atributo in range(len(instancia[0])-1): #por cada atributo a excepcion de la clase
    auxiliar = []
    for index_registro in range(len(instancia)):
        auxiliar.append(float(instancia[index_registro][index_atributo]))
    v_max = max(auxiliar)
    v_min = min(auxiliar)
    v_width = round((v_max-v_min)/v_K,4)
    ######################################################################
    print("Atributo analizado:" , encabezados[index_atributo])
    print("min: ", v_min)
    print("max: ", v_max)    
    print("width: ", v_width)
    ######################################################################    
    control  = round(v_min+v_width,4)
    temp = ["<" + str(control)]
    for j in range(1,v_K-1):
        s = "[" + str(control) + ", " #izquierda
        control = round(control+v_width,4)
        s += str(control) + ")" #derecha
        temp.append(s)
    temp.append(">=" + str(control))
    intervalos.append(temp)
    auxiliar.clear()
#############################################################################################
for i in intervalos:
    print(i)
with open('resultados.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for i in instancia:
        grupo = []
        for index_valor in range(len(i)-1): #por cada valor de la instancia a excepción de la clase
            valor = float(i[index_valor])
            if valor < 20.83:
                grupo.append("V1")
            elif valor < 36.66:
                grupo.append("V2")
            elif valor < 52.5:
                grupo.append("V3")
            elif valor < 68.33:
                grupo.append("V4")
            elif valor < 84.16:
                grupo.append("V5")
            else:
                grupo.append("V6")
        grupo.append(i[-1])
        writer.writerow(grupo)