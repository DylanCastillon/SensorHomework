unsigned long TempAdc[][2]=
{ {50,0},
  {100,390},
  {150,1677},
  {200,2544},
  {250,3237},
  {300,3837},
  {350,4382},
  {400,4895},
  {450,5392},
  {500,5883},
  {550,6379},
  {600,6860},
  {650,7426},
  {700,8002},
  {750,8636},
  {800,9355},
  {850,10203},
  {900,11260},
  {950,12695},
  {971,14985},
  {1023,16567}
};

long T0 = 0;
long T1 = 0;
long A0b = 0;
long A1b = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void getValue(long sensorVal, unsigned long tADC[][2]) {
  for (int i = 0; i < 21; i++) {
    if (sensorVal < tADC[i + 1][0] && sensorVal >= tADC[i][0]) {
      A0b = tADC[i][0];
      A1b = tADC[i + 1][0];
      T0 = (tADC[i][1] - 4000) / 100;
      T1 = (tADC[i + 1][1] - 4000) / 100;
    }
  }
}

long calc(long adc, long T0, long T1, long A0b, long A1b) {
  return(T0 + ((adc - A0b) * (T1 - T0)) / (A1b - A0b));
}

void loop() {
  long sensorValue = analogRead(A0);
  getValue(sensorValue, TempAdc);
  Serial.println(calc(sensorValue, T0, T1, A0b, A1b));  
  delay(100);
}
