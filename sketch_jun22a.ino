#include <ESP8266.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2); /* RX:D3, TX:D2 */
void setup() {
  mySerial.begin(115200); 
  Serial.begin(9600);
  Serial.println("start");
}
 
void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
 
  if (Serial.available()) {
    char chars = Serial.read();
    mySerial.write(chars);
  }
}
