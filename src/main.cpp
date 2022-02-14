/*
  Titre      : Conexion I2C
  Auteur     : Cedric Yonta
  Date       : 13/02/2022
  Description: communique avec un autre uC
  Droits     : ...
  Version    : 0.0.1
   Source     :https://www.instructables.com/I2C-between-Arduinos/
*/

#include <Arduino.h>

// Include the required Wire library for I2C<br>
#include <Wire.h>

int LED = 6;
int x = 0;
void receiveEvent(int bytes);

void setup() {

  Serial.begin(9600);
  // Define the LED pin as Output

  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms
 // Serial.println(x);

  analogWrite(LED, x);
  
 /* if (x == 0) {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 3) {
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(400);
  }*/
}