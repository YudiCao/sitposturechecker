// Experiment 1: Pressure
// Project Name: Sit Posture Checker
// by Yudi Cao
// DIGF-6037 Creation & Computation
// Credits: Kate Hartman & Nick Pucket
// sensor group

int topLeftS = A5;
int topRightS = A4;
int bottomLeftFrontS = A0;
int bottomRightFrontS = A2;
int bottomLeftBackS = A1;
int bottomRightBackS = A3;


// calibration data
int topLeftSv = 0;
int topRightSv = 0;
int bottomLeftFrontSv = 0;
int bottomRightFrontSv = 0;
int bottomLeftBackSv = 0;
int bottomRightBackSv = 0;


// LED group
int green = 7;
int yellow = 6;
int red = 5;




void setup() {
 // put your setup code here, to run once:
 // wait five seconds to sit good
 while (millis() < 5000) {
 }


 // store sensor data at 5 sec
 topLeftSv = analogRead(topLeftS);
 topRightSv = analogRead(topRightS);
 bottomLeftFrontSv = analogRead(bottomLeftFrontS);
 bottomRightFrontSv = analogRead(bottomRightFrontS);
 bottomLeftBackSv = analogRead(bottomLeftBackS);
 bottomRightBackSv = analogRead(bottomRightBackS);
}


void loop() {
 // put your main code here, to run repeatedly:
 // before 20 minutes
 while (millis() < 1200000000) {
   // turn on green LED
   digitalWrite(green, HIGH);
   // turn off yellow LED
   digitalWrite(yellow, LOW);


   // if top left and right sensor pair difference is too much
   if ((analogRead(topLeftS) - topLeftSv) - (analogRead(topRightS) - topRightSv) > 300) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(topLeftS));
     Serial.print(",");
     Serial.print(analogRead(topRightS));
     Serial.println("topleft heavy");
   }
   // if any left and right sensor pair difference is too much
   if ((analogRead(topRightS) - topRightSv) - (analogRead(topLeftS) - topLeftSv) > 300) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(topLeftS));
     Serial.print(",");
     Serial.print(analogRead(topRightS));
     Serial.println("topright heavy");
   }
   // if any left and right sensor pair difference is too much
   if ((analogRead(bottomLeftFrontS) - bottomLeftFrontSv) - (analogRead(bottomRightFrontS) - bottomRightFrontSv) > 700) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(bottomLeftFrontS));
     Serial.print(",");
     Serial.print(analogRead(bottomRightFrontS));
     Serial.println("bottomleft heavy");
   }
   // if any left and right sensor pair difference is too much
   if ((analogRead(bottomRightFrontS) - bottomRightFrontSv) - (analogRead(bottomLeftFrontS) - bottomLeftFrontSv) > 400) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(bottomLeftFrontS));
     Serial.print(",");
     Serial.print(analogRead(bottomRightFrontS));
     Serial.println("bottomRight heavy");
   }
   // if any left and right sensor pair difference is too much
   if ((analogRead(bottomLeftBackS) - bottomLeftBackSv) - (analogRead(bottomRightBackS) - bottomRightBackSv) > 500) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(bottomLeftBackS));
     Serial.print(",");
     Serial.print(analogRead(bottomRightBackS));
     Serial.println("bottom right back heavy");
   }
   // if any left and right sensor pair difference is too much
   if ((analogRead(bottomRightBackS) - bottomRightBackSv) - (analogRead(bottomLeftBackS) - bottomLeftBackSv) > 300) {
     // turn off green LED
     digitalWrite(green, LOW);
     // turn on yellow LED
     digitalWrite(yellow, HIGH);
     digitalWrite(yellow, HIGH);
     Serial.print(analogRead(bottomLeftBackS));
     Serial.print(",");
     Serial.print(analogRead(bottomRightBackS));
     Serial.println("bottom left back heavy");
   }
 }
 // turn off green LED
 digitalWrite(green, LOW);
 // turn off yellow LED
 digitalWrite(yellow, LOW);
 //turn on the red LED
 digitalWrite(red, HIGH);
}