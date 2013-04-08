#include <LiquidCrystal.h>
#include <dht11.h>

dht11 DHT11;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Inicializando sensor");
  
  DHT11.attach(2);
}

void loop()
{
  lcd.setCursor(0, 0);

  int chk = DHT11.read();
  
  //switch (chk)
  //{
  //  case 0: Serial.println("OK"); break;
  //  case -1: Serial.println("Checksum error"); break;
  //  case -2: Serial.println("Time out error"); break;
  //  default: Serial.println("Unknown error"); break;
  //}

  lcd.print("Humidade (%): ");
  lcd.print((float) DHT11.humidity, DEC);

  lcd.setCursor(0, 1);
  
  lcd.print("Temp. (C): ");
  lcd.print((float) DHT11.temperature, DEC);
  
  delay(2000);
}
