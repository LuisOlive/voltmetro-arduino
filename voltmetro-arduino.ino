#define N 200 // número de muestras antes de cada corte

double temp, sum = 0;
byte i = 0;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  // leyendo, ahora entre 2 terminales
  int A = analogRead(A0);
  int B = analogRead(A1);
  
  temp = caidaTension(A - B);
  sum += temp;
  
  // imprimirVoltaje(temp);
  
  if(++i == N) {
    Serial.print("El promedio es ");
    imprimirVoltaje(sum / i);
    
    sum = i = 0;
  }
}

void imprimirVoltaje(double v) {
  Serial.print(v, 7);
  Serial.println(" V");
}

double caidaTension(int entradaBits) {
  return 5.0 * entradaBits / 1024;  
}
