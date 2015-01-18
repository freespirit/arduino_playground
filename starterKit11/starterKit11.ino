#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  
  lcd.print("Ask the oracle");
  lcd.setCursor(0,1);
  lcd.print("& press button");
  
  Serial.begin(9600);
}

void loop() {
  switchState = digitalRead(switchPin);
  Serial.print(switchState);
  Serial.print(" : ");
  Serial.println(prevSwitchState);
  
  if(switchState != prevSwitchState && switchState == LOW) {
    int reply = random(8);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Oracle says:");
    lcd.setCursor(0,1);
    
    switch(reply) {
      case 0:
      lcd.print("Yes");
      break;
      case 1:
      lcd.print("Most likely");
      break;
      case 2:
      lcd.print("Certainly");
      break;
      case 3:
      lcd.print("Outlook good");
      break;
      case 4:
      lcd.print("Unsure");
      break;
      case 5:
      lcd.print("Ask again");
      break;
      case 6:
      lcd.print("Doubtful");
      break;
      case 7:
      lcd.print("No");
      break;
    }
  }
  
  prevSwitchState = switchState;
}
