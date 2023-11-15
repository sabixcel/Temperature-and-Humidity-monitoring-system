#include <dht.h>
#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
dht DHT;

#define DHT11_PIN 7
void setup() { 
      lcd.init(); // initialize the lcd
      lcd.backlight(); // open the backlight
      lcd.begin(16,2);
}

void loop() {  
      int chk = DHT.read11(DHT11_PIN); 
      lcd.clear();  lcd.print("Temp: "); // print the temperature
      lcd.print(DHT.temperature);  
      lcd.setCursor(0,1); // start to print at the second row
      lcd.print("Humidity: "); // print the humidity
      lcd.print(DHT.humidity);    
      delay(2000); // wait a few seconds between measurements
}
