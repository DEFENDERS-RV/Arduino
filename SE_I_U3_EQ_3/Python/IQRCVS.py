import csv
import statistics

with open('archivos/mi_archivo_excel.xlsx', 'r') as archivo_excel: #Cambiar el nombre del archivo a trabajar
    lector_excel = csv.reader(archivo_excel, delimiter='\t')
    with open('archivos/mi_archivo_csv.csv', 'w', newline='') as archivo_csv:
        escritor_csv = csv.writer(archivo_csv)
        for fila in lector_excel:
            escritor_csv.writerow(fila)

with open('archivos/mi_archivo_csv.csv', 'r') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)
    encabezados = next(lector_csv)
    datos = []
    for fila in lector_csv:
        datos.append([float(valor) for valor in fila])

datos_estandarizados = []
for fila in datos:
    media = statistics.mean(fila)
    desviacion_estandar = statistics.stdev(fila)
    fila_estandarizada = [(valor - media) / desviacion_estandar for valor in fila]
    datos_estandarizados.append(fila_estandarizada)

with open('archivos/mi_archivo_estandarizado.csv', 'w', newline='') as archivo_estandarizado:
    escritor_estandarizado = csv.writer(archivo_estandarizado)
    escritor_estandarizado.writerow(encabezados)
    for fila in datos_estandarizados:
        escritor_estandarizado.writerow(fila)

rango_intercuartil = []
for columna in zip(*datos):
    quartil_1, mediana, quartil_3 = statistics.quantiles(columna, n=4)
    rango_intercuartil.append(quartil_3 - quartil_1)

limites_inferiores = [q1 - 1.5 * iqr for q1, iqr in zip(statistics.quantiles(columna, n=4)[::2], rango_intercuartil)]
limites_superiores = [q3 + 1.5 * iqr for q3, iqr in zip(statistics.quantiles(columna, n=4)[2::2], rango_intercuartil)]

datos_sin_atipicos = []
for fila in datos:
    fila_sin_atipicos = []
    for valor, limite_inferior, limite_superior in zip(fila, limites_inferiores, limites_superiores):
        if valor < limite_inferior or valor > limite_superior:
            fila_sin_atipicos.append(limite_inferior if valor < limite_inferior else limite_superior)
        else:
            fila_sin_atipicos.append(valor)
    datos_sin_atipicos.append(fila_sin_atipicos)
