int potenciometro = A0;
//USAR ARRAY , PROGRAMAR UN METODO DE ORDENAMIENTO , QUICKSORT , BURBUJA , 
//TOMAR LOS INDIICES DE EN MEDIO 
//VALOR MEDIANA = TOMAR ESOS DOS 
//GUARDAR LAS 30 LECTURAS , OBTENER EL PROMEDIO 


/*
MODA : 
SABER EL VALOR QUE MAS SE REPITE. HACER UNA EN EJECUCION X 

GUARDAR LAS 30 ORDENARLAS , DETERMIANR LA FRECUENCIA DE CADA UNO DE LOS NUMEROS , EL QUE APAREZCA MAS VECES ES LA MODA 


*/
int toMuestras = 30;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int i , valor , valorMayor = -1; 
void loop() {
  // put your main code here, to run repeatedly:
    for(i = 0; i <toMuestras; i++){ //-> Teorema del Limite Central
      valor = analogRead(potenciometro);
      if(valor>valorMayor){
          valorMayor = valor;
      }
    }
  //valor /= 10;
  Serial.println(valorMayor);
  delay(1000);

/*
Tarea:
  1.- Poblacion
  2.- Muestra
  3.- Ruido
  4.- Preprocesamineto
  5.- Teorema del Limite Central
  6.-Modulo PySerial
  7.- Tratemineto del Ruido en Sensores
  8.- Tecnicas de Filtrado y Suavisado para Sensores

Programas:
1.- Preprocesamiento: MODA
2.-Preprocesamiento: MEDIANA
*/

}