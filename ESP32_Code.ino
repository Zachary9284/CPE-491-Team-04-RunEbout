#include <driver/dac.h>
double out = 0.0;
double physical_throttle_value = 0.0;
double percent = 0.0;


void setup() {
  //Serial.begin(115200);
  // Set pin mode
  pinMode(25,OUTPUT);
  ledcAttachPin(25, 0);
  ledcSetup(0,500000,8);
  pinMode(34, INPUT);
  dac_output_enable(DAC_CHANNEL_1);
  
}

void loop() {
  
  physical_throttle_value = analogRead(34);
  //Serial.println(physical_throttle_value);
  percent = physical_throttle_value/4095;
  out = 80 + (72 * percent);
  //117 2880 rpm 60 mph
  //72 1960 rpm 30 mph
  //36 1050 rpm 16.656 mph
  //Serial.println(out);
  
  dac_output_voltage(DAC_CHANNEL_1, out);

}
