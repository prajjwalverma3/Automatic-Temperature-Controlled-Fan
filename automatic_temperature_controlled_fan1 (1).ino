#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
float temp;

byte customChar[] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};
byte moderate[] = {
 B00000,
  B00000,
  B01110,
  B10001,
  B10101,
  B10001,
  B01110,
  B00000
};
byte cold[] = {
  B10001,
  B01010,
  B00100,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001
};
byte high[] = {
  B00000,
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100
};
byte fire[] = {
   B00000,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};
void setup()
{
   digitalWrite(9,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(10,HIGH);
  lcd.begin(16,2);
  
  lcd.createChar(0, customChar);
   lcd.createChar(1, moderate);
  lcd.createChar(2,cold);
  lcd.createChar(3,high);
  lcd.createChar(4,fire);
   lcd.setCursor(2,0);
  
  lcd.setCursor(0,0);
  lcd.print("hey PV!...");
 // delay(2000);
  lcd.setCursor(0,1);
  lcd.print("temp control fan");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Automatic fan");
    lcd.setCursor(0,1);
  lcd.print("measure temp.....");
   
    delay(3000);
    lcd.clear();
  
  lcd.clear();
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
}

void loop()
{
  
  float reading,voltage,tempreading,fernite;
 tempreading = analogRead(A0);
 voltage=tempreading*5;
 voltage/=1024.0;
 temp = (voltage - 0.5)*100;
   lcd.setCursor(0,0);
  lcd.print("Temp: ");
  
  lcd.print(temp);
  lcd.write(byte(0));
 lcd.print("C");
 /*fernite=(temp/5.0)*9+32;
 lcd.setCursor(0,1);
 lcd.print("temp: ");
 lcd.print(fernite);
 lcd.print(" F");*/
 // delay(1000);
 // lcd.clear();
 if(temp>0 && temp<10)
 {
   analogWrite(11,0);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Fan OFF");
   digitalWrite(9,HIGH);
   delay(200);
   digitalWrite(9,LOW);
   delay(200);
    digitalWrite(10,LOW);
   digitalWrite(12,LOW);
    digitalWrite(8,LOW);
   delay(1000);
    lcd.clear();
 }
 else if(temp>10 && temp<25)
 {
   analogWrite(11,60);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Fan speed - 25%");
   lcd.setCursor(14,0);
  lcd.write(byte(1));
   digitalWrite(10,LOW);
   digitalWrite(9,HIGH);
    delay(200);
   digitalWrite(9,LOW);
   delay(200);
   digitalWrite(12,LOW);
    digitalWrite(8,LOW);
   delay(1000);
  lcd.clear();
 }
 else if(temp>25 && temp<45)
 {
    analogWrite(11,100);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Fan speed : 50%");
   lcd.setCursor(15,0);
  lcd.write(byte(3));
    digitalWrite(9,LOW);
   digitalWrite(10,HIGH);
    delay(200);
   digitalWrite(10,LOW);
   delay(200);
   digitalWrite(12,LOW);
    digitalWrite(8,LOW);
    delay(1000);
  lcd.clear();
 }
 else if(temp>45 && temp<60)
 {
   analogWrite(11,180);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Fan speed : 75%");
   lcd.setCursor(15,0);
  lcd.write(byte(3));
    digitalWrite(9,LOW);
   digitalWrite(10,HIGH);
    delay(200);
   digitalWrite(10,LOW);
   delay(200);
   digitalWrite(12,LOW);
    digitalWrite(8,LOW);
    delay(1000);
  lcd.clear();
  
 }
 
 else if(temp>60)
 {
    analogWrite(11,255);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Fan speed :100%");
   lcd.setCursor(15,0);
  lcd.write(byte(4));
    digitalWrite(9,LOW);
   digitalWrite(12,HIGH);
    delay(200);
   digitalWrite(12,LOW);
   delay(200);
   digitalWrite(10,LOW);
    digitalWrite(8,LOW);
    delay(1000);
  lcd.clear();
 }
else 
 {
   analogWrite(11,0);
   digitalWrite(13,LOW);
   lcd.setCursor(0,1);
   lcd.print("Too much cold");
  lcd.setCursor(15,0);
  lcd.write(byte(2));
  delay(1000);
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("FAN  OFF");
  
    digitalWrite(9,LOW);
   digitalWrite(12,LOW);
   digitalWrite(12,LOW);
   digitalWrite(10,LOW);
   digitalWrite(8,HIGH);
  delay(200);
   digitalWrite(8,LOW);
  delay(200);
    delay(1000);
  lcd.clear();
  
 }
}
//
