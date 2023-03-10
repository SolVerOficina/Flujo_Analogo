const int sensorPin = 18; // Conecta el pin de señal del sensor al pin 2 de Arduino
const int ledPin = 2; // Conecta un LED al pin 13 de Arduino para indicar que se está leyendo la señal

void setup() {
  Serial.begin(115200); // Inicia la comunicación serial con una velocidad de 9600 baudios
  pinMode(sensorPin, INPUT); // Configura el pin del sensor como entrada
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
  digitalWrite(ledPin, HIGH); // Enciende el LED para indicar que se está leyendo la señal
  int pulso = pulseIn(sensorPin, HIGH); // Lee la señal de pulso del sensor
  digitalWrite(ledPin, LOW); // Apaga el LED

  // Convierte la señal de pulso en una señal analógica de 0 a 5V
  float voltaje = map(pulso, 0, 1000, 0, 5000) / 1000.0;

  // Envía el valor del voltaje a la computadora a través de la comunicación serial
  Serial.println(voltaje);

  delay(100); // Espera 100 milisegundos antes de leer la siguiente señal
}
