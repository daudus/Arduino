// Senzor barometrického tlaku Bosch BMP180
// http://navody.arduino-shop.cz/navody-k-produktum/mereni-tlaku-bmp180.html
// připojení knihoven Wire a BMP085
#include <Wire.h>
#include <Adafruit_BMP085.h>

// inicializace senzoru BMP180 z knihovny BMP085
Adafruit_BMP085 bmp180;

// konstanta s korekcí měření v hPa
int korekce = 32;

void setup() {
  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600);
  // zapnutí komunikace se senzorem BMP180
  bmp180.begin();
}

void loop() {
  // výpis teploty ve stupních Celsia
  Serial.print("Teplota: ");
  Serial.print(bmp180.readTemperature());
  Serial.println(" stupnu Celsia");

  // výpis barometrického tlaku v hekto Pascalech
  Serial.print("Barometricky tlak: ");
  Serial.print((bmp180.readPressure() + korekce*100)/100.00);
  Serial.println(" hPa");

  // výpis nadmořské výšky při započítání
  // běžné hodnoty tlaku 1013,25 hekto Pascalů
  Serial.print("Nadmorska vyska prepoctena: ");
  Serial.print(bmp180.readAltitude(bmp180.readPressure() + korekce*100));
  Serial.println(" metru ");
  Serial.println("------------------------------");

  // pauza pro přehlednější výpis
  delay(10000);
}
