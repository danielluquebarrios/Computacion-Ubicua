// Definición de los pines (usamos const para mayor seguridad en el código)
const int pinBoton = 2;
const int pinIndicador = 3;

void setup() {
  // Configuración de los pines como entrada y salida
  pinMode(pinBoton, INPUT);
  pinMode(pinIndicador, OUTPUT);
  
  // Garantizamos que la luz inicie apagada por defecto
  digitalWrite(pinIndicador, LOW);
}

void loop() {
  // Evaluamos si el botón está siendo presionado (estado ALTO)
  if (digitalRead(pinBoton) == HIGH) {
    
    // Acción: Encender la luz indicadora
    digitalWrite(pinIndicador, HIGH);
    
    // Temporizador de 5000 milisegundos (5 segundos)
    delay(5000); 
    
    // Acción: Apagar la luz indicadora
    digitalWrite(pinIndicador, LOW); 
    
    // Función antirrebote: Evita que el ciclo se reinicie inmediatamente 
    // si el usuario mantiene presionado el botón más de la cuenta
    while (digitalRead(pinBoton) == HIGH) {
      delay(10); // Pequeña pausa para estabilizar la lectura
    }
  }
}