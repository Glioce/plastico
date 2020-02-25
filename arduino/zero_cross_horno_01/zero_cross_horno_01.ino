/* PROYECTO RECICLADO DE PLÁSTICO
 * 
 * Programa para controlar el disparo de los triacs.
 * Instalado en el horno para derretir plástico.
 * El circuito externo es un optoacopldor H11AA
*/

// Variables globales
volatile byte tic = false; //indica inicio de tiempo de espera
byte duty = 50; //duty cycle (0 - dutymax)
int t = 4000; //microsegundos de espera (0 - tmax) calculado a partir del duty cycle
#define dutymax 100.0 //máximo valor de duty cycle
#define tmax 7200.0 //número máximo de microsegundos
#define pulso 1 //microsegundos de pulso para activar triac

// Pines
#define entrada 2
#define salida 12

void setup() {
  pinMode(entrada, INPUT); //pin de entrada, usable para interrupciones
  // activar interrupción en pin 2, la rutina se llama isr_zero()
  // y se activa cuando el pin pasa de 1 a 0 (flanco de bajada)
  attachInterrupt(digitalPinToInterrupt(entrada), isr_zero, FALLING);
  pinMode(salida, OUTPUT); //pin de salida
  digitalWrite(salida, 0); //apagar salida

  // Comunicación
  Serial.begin(9600);
}

void isr_zero() {
  tic = true; //iniciar tiempo de espera en loop()
}

void loop() {
  if (Serial.available()) {
    // Calcular el tiempo de encendido
    // La señal eléctrica tiene una frecuencia de 60 Hz
    // En cada segundo hay 120 cruces por cero
    // El tiempo entre cada cruce es 1 s / 120 = 8.333 ms
    // Los flancos de subida y de bajada del pulso del circuito detector
    // no pasan exactamente por cero, hay un retardo de 0.4 ms aprox.
    // El tiempo utilizable entre cada pulso es un poco menor a 8 ms
    // Experimentar para encontrar el valor exacto
    duty = Serial.read(); //recibir byte

    // Si el ancho de pulso es 255, el tiempo de espera es 0
    // si el ancho de pulso es 0, el tiempo de espera es 8 ms
    float inverso = float(dutymax - duty); //inverso
    //float inverso = float(duty); //inverso
    t = int((inverso / dutymax) * tmax); //tiempo de espera
  }

  if (tic == true) {
    tic = false;
    digitalWrite(salida, 0); //apagar salida
    delayMicroseconds(t); //esperar
    
    if (tic == false) {//si no ha ocurrido otro flanco de bajada
      digitalWrite(salida, 1);
      delayMicroseconds(pulso); //pulso corto
      digitalWrite(salida, 0);
    }
  }
}
