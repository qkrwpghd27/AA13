/*
 온도, 빛 입력 LCD 모니터링 및 제어
*/
#define TMP36_INPUT 0   // A0
#define CDS_INPUT 1     // A1

void setup() { 
  Serial.begin(9600);
// 16X2 LCD 모듈 설정하고 백라이트를 켠다.
// 
// 모든 메세지를 삭제한 뒤
// 숫자를 제외한 부분들을 미리 출력시킨다.

 }

void loop(){
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting the analog value to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;  // in C

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));  // in lux

  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
  
  delay(500);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, 
  // Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
