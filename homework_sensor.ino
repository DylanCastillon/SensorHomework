  float R0 = 10000;
  float R5 = 10000;
  float B = 3435;
  float T0 = 298.15;
  float diffTemp = 273.15;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

float calcRTH(float adc,float R5) {
  return (R5*1024/adc-R5);
}

float calcT(float rth, float R0, float B, float T0){
  return (1/(log(rth/R0)/B + 1 / T0));
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(calcT(calcRTH(sensorValue,R5), R0, B, T0) - diffTemp);
  delay(100);
}
