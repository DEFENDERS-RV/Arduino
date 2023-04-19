import csv
import math

# Lee el archivo Excel
with open('archivos/mi_archivo_excel.xlsx', 'r') as archivo_excel: #Cambiar el nombre del archivo a trabajar
    lector_excel = csv.reader(archivo_excel, delimiter='\t')
    # Convierte el archivo Excel a CSV y guarda los resultados en un nuevo archivo
    with open('archivos/mi_archivo_csv.csv', 'w', newline='') as archivo_csv:
        escritor_csv = csv.writer(archivo_csv)
        for fila in lector_excel:
            escritor_csv.writerow(fila)

# Lee el archivo CSV
with open('archivos/mi_archivo_csv.csv', 'r') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)
    encabezados = next(lector_csv)
    datos = []
    for fila in lector_csv:
        datos.append([float(valor) for valor in fila])

# Calcula la media y la desviación estándar de cada columna
medias = [sum(columna)/len(columna) for columna in zip(*datos)]
desviaciones_estandar = [math.sqrt(sum((valor - media) ** 2 for valor in columna) / len(columna)) for media, columna in zip(medias, zip(*datos))]

# Estandariza los datos
datos_estandarizados = []
for fila in datos:
    fila_estandarizada = [(valor - media) / desviacion_estandar for valor, media, desviacion_estandar in zip(fila, medias, desviaciones_estandar)]
    datos_estandarizados.append(fila_estandarizada)

# Crea un nuevo archivo CSV con los datos estandarizados
with open('archivos/mi_archivo_estandarizado.csv', 'w', newline='') as archivo_estandarizado: #Cambiar el nombre del archivo para guardar ya estandarizados
    escritor_estandarizado = csv.writer(archivo_estandarizado)
    escritor_estandarizado.writerow(encabezados)
    for fila in datos_estandarizados:
        escritor_estandarizado.writerow(fila)
