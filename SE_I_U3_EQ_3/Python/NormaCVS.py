import csv

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
    # Normaliza los datos
    datos_norm = []
    for fila in lector_csv:
        fila_norm = [(float(valor) - float(min(fila))) / (float(max(fila)) - float(min(fila))) for valor in fila]
        datos_norm.append(fila_norm)

# Crea un nuevo archivo CSV con los datos normalizados
with open('archivos/mi_archivo_norm.csv', 'w', newline='') as archivo_norm: #Cambiar el nombre del archivo para guardar ya normalizado
    escritor_norm = csv.writer(archivo_norm)
    escritor_norm.writerow(encabezados)
    for fila in datos_norm:
        escritor_norm.writerow(fila)
