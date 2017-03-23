// http://rancidbacon.com/files/kiwicon8/ESP8266_WiFi_Module_Quick_Start_Guide_v_1.0.4.pdf
// http://www.xpablo.cz/?p=996
// http://xanadu.khnet.info/esp8266.php

#include <SoftwareSerial.h>

#define DEBUG true

SoftwareSerial Serial1(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3

void setup()
{
    Serial.begin(9600);  // Serial Monitor
    Serial1.begin(115200);
}
void loop()
{
    while (Serial1.available()) {
        Serial.write(Serial1.read());
    }
    while (Serial.available()) {
        Serial1.write(Serial.read());
    }
}
