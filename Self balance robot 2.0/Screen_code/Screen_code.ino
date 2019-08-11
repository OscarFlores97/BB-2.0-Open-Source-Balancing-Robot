
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/////////// fully open
byte eye[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
//////////fully closed
byte fullyclosed[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte midclosed[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte meh[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte smile[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B01110
};
byte blush[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000
};

void setup()
{
  lcd.init();                      // initialize the lcd 
  //////////////////mpu data
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  // Print a message to the LCD.
  lcd.backlight();
  lcd.createChar(0, eye);
  lcd.createChar(1, fullyclosed);
  lcd.createChar(2, midclosed);
  lcd.createChar(3, meh);
  lcd.createChar(4, smile);
   lcd.createChar(5, blush);
   
lcd.begin(20,4);
}


void loop()
{
  ///////////////mpu data
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("  angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("  angleZ : ");
  Serial.println(mpu6050.getAngleZ());
  
  lcd.clear();// clearn previous values from screen
  lcdDisplay(
             // to print X:
             0, // character 0  
             0, // line 0
             "X:", 

             // to print AngleX
             2, // character 2
             0, // line 0
             mpu6050.getAngleX() 
             );

  lcdDisplay(
             // to print Y:
             0, // character 13 
             1, // line 0
             "Y:", 

             // to print AngleY
             2, // character 0
             1, // line 1
             mpu6050.getAngleY() 
             );  

  lcdDisplay(
             // to print Z:
             0, // character 7 
             2, // line 1
             "Z:", 

             // to print AngleZ
             2, // character 9
             2, // line 0
             mpu6050.getAngleZ() 
             );                         
   delay(100);
   //////////blush
    lcd.setCursor(7,3);
    lcd.write(byte(5));

    lcd.setCursor(19,3);
    lcd.write(byte(5));
  //left eye
  //////no movment
  lcd.setCursor(9,1);
  lcd.write(byte(0));
  lcd.setCursor(9,2);
  lcd.write(byte(0));
  
  lcd.setCursor(10,1);
  lcd.write(byte(0));
  lcd.setCursor(10,2);
  lcd.write(byte(0));
 
  lcd.setCursor(11,1);
  lcd.write(byte(0));
  lcd.setCursor(11,2);
  lcd.write(byte(0));
 ///////////////////
 
   //right eye
  //////no movment
  lcd.setCursor(15,1);
  lcd.write(byte(0));
  lcd.setCursor(15,2);
  lcd.write(byte(0));
  

  lcd.setCursor(16,1);
  lcd.write(byte(0));
  lcd.setCursor(16,2);
  lcd.write(byte(0));

  lcd.setCursor(17,1);
  lcd.write(byte(0));
  lcd.setCursor(17,2);
  lcd.write(byte(0));

  /////////////////mouth meh
  lcd.setCursor(13,3);
  lcd.write(byte(3));
  
 ///////////////////blink
  ////////////right
  delay(3000);
 
  lcd.setCursor(15,2);
  lcd.write(byte(2));
    lcd.setCursor(9,2);
  lcd.write(byte(2));
  
  lcd.setCursor(16,2);
  lcd.write(byte(2));
   lcd.setCursor(10,2);
  lcd.write(byte(2));
  
  lcd.setCursor(17,2);
  lcd.write(byte(2));
   lcd.setCursor(11,2);
  lcd.write(byte(2));
  
  lcd.setCursor(15,1);
  lcd.write(byte(1));
  lcd.setCursor(9,1);
  lcd.write(byte(1));
  
  lcd.setCursor(16,1);
  lcd.write(byte(1));
   lcd.setCursor(10,1);
  lcd.write(byte(1));
  
  lcd.setCursor(17,1);
  lcd.write(byte(1));
  lcd.setCursor(11,1);
  lcd.write(byte(1));

 delay(2000);
  
  /////////////////mouth smile
  lcd.setCursor(13,3);
  lcd.write(byte(4));

  delay(2000);
}
void lcdDisplay(int tc, int tr, String title, int vc, int vr, float value)
{
   // Robojax.com MPU6050 Demo
   lcd.setCursor (tc,tr); //
   lcd.print(title);
   
   lcd.setCursor (vc,vr); //
   lcd.print(value);
}
 
