 #define ANALOG_IN_PIN A1

float adc_voltage = 0.0;
float in_voltage = 0.0;                               
float per = 0.0;
float per_in = 0.0;
float per_in_one = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;

float ref_voltage = 5.0;

int adc_value = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("DC voltge Test");
  
}

void loop()
{
  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;

  in_voltage = adc_voltage / (R2/(R1+R2));
  per_in = 12.6 - in_voltage;
  per_in_one = 3.6 - per_in;
  per = per_in_one / 3.6 *100;
  //Serial.println("Input voltge in Percentage = ");
  //Serial.println(per , 2);
  Serial.println(in_voltage);

  delay(500);
}
