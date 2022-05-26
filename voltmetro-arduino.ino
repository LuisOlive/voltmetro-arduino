int sensorPin = A0,
    sensorValue = 0;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  Serial.print("El voltaje medido es ");
  Serial.print(elVoltaje(sensorValue));
  Serial.println(" V");
}

double elVoltaje(int entradaBits) {
  return 5.0 * entradaBits / 1024;  
}
