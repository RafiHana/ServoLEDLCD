#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

Servo servo1, servo2, servo3, servo4; 

int pos = 0; 
int ledPur = 13;
int ledYell = 12;

void setup() { 

  servo1.attach(5); 
  servo2.attach(6); 
  servo3.attach(10); 
  servo4.attach(11); 

  pinMode(ledPur, OUTPUT);
  pinMode(ledYell, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Hallo");

} 
void loop() { 

  for (pos = 0; pos <= 180; pos += 1) { 

    lcd.setCursor(2, 0);
    lcd.print("Servo Kuning");

    digitalWrite(ledYell, HIGH);
      servo1.write(pos); 
      servo2.write(pos); 
    digitalWrite(ledYell, LOW);
    delay(50); 
  } 

 for (pos = 180; pos >= 0; pos -= 1) {

    lcd.setCursor(2, 0);
    lcd.print("Servo Ungu");

    digitalWrite(ledPur, HIGH);
      servo3.write(pos); 
      servo4.write(pos); 
    digitalWrite(ledPur, LOW);
    delay(50); 
  } 
} 