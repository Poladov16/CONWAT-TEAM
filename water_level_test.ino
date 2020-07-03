#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST
#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
Ultrasonic ultrasonic(12, 13);
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
int distance;
int sound = 500;
void setup() {
  Serial.begin(9600);
lcd.begin(16,2);
//myRTC.setDS1302Time(00,42, 19, 0, 03, 07, 2020);
 pinMode (4, OUTPUT);
}

void loop() {
distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
myRTC.updateTime();
lcd.setCursor(0, 0);
lcd.print("date: ");
lcd.print(myRTC.dayofmonth);
lcd.print("/");
lcd.print(myRTC.month);
lcd.print("/");
lcd.print(myRTC.year);
lcd.print(" ");
lcd.setCursor(0, 1);
lcd.print("time: ");
lcd.print(myRTC.hours);
lcd.print(":");
lcd.print(myRTC.minutes);
lcd.print(":");
lcd.print(myRTC.seconds);
lcd.println(" ");


Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.print(myRTC.seconds);
Serial.println(" ");
if(myRTC.hours==19&&myRTC.minutes==53&&myRTC.seconds==10)
{
  Serial.println("InSide");
  Serial.println(myRTC.hours);
  Serial.println(myRTC.minutes);
 digitalWrite(4, HIGH);

}
if(distance>=27) 
  {
    digitalWrite(4, LOW);
   
  }
  delay (1000);
}
