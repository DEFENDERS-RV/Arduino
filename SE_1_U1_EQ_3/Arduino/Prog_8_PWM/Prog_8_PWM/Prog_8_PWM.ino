//MODULACION POR ANCHO DE PULSO = PWM
//CONSISTE EN (ANALOGIA)
// SIMULA UNA SEÑAL ANALOGICA A TRAVES DE LA VARIACION DEL ANCHO DE PULSO DE UNA SEÑAL DIGITAL

//1 byte para trabajar con pwn = 8 bits
// 0 v. = 0
// 5v. = 255

//PARA TRABAJAR CON PWM SE REQUIERE QUE SE UTILICE UN PIN QUE LO SOPORTE.
//EN ARDUINO , POR EJEMPLO VIENE SEÑALADOS CON UNA VIRTIGUILLA (~)

int led = 6;


void setup() {
  // LOS PINES PWM , NO REQUIEREN QUE SE ESTABLEZCA EL MODO DE TRABAJO

}

int i;

void loop() { //16Mhz
  

  for (i = 0; i < 255; i++){
    analogWrite(led,i);
    delay(10);
  }

   for (i = 255; i >0; i--){
    analogWrite(led,i);
    delay(10);
  }

}
