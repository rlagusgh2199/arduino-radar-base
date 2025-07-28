#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h> 

#define trigPin 13 
#define echoPin 12

int speakerPin = 7;
int led1 = 4;
int motor_control = 8, agl = 90, i = 2; //초기 각도와 돌아갈 각도 설정
int motor_status = HIGH;
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int tones = 800;

void setup() 
{ 
    Serial.begin(9600); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    servo.attach(motor_control);
    servo.write(agl);
    lcd.begin();
    lcd.backlight(); 
    pinMode(led1, OUTPUT);
}


long microsecondsToInches(long microseconds) 
{
    return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}
  

void loop() 
{  
    long duration, inches, cm;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); 

    // convert the time into a distance
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);

    char read_data;

//서보모터 시리얼모니터로 제어하기 0을 입력하면 서보모터 정지 및 작동
    if (Serial.available())
    {
      read_data = Serial.read();
      if( read_data == '0' && motor_status == LOW)
      {
        motor_status = HIGH;
      }
      else if( read_data == '0' && motor_status == HIGH )
      {
        motor_status = LOW;
      }
    }

    if(motor_status == HIGH)
    {
      agl += i;
        if (agl > 180) {
          agl = 179;
          i = -2;
        } else if (agl < 0) {
          agl = 1;
          i = 2;
        }
        servo.write(agl); 
//프로세싱을 하기위해 각도와 거리를','로 '.'로 구분하기
        Serial.print(agl);
        Serial.print(",");
        Serial.print(cm);
        Serial.print(".");
    }

    else if (motor_status == LOW)
    {
      servo.write(agl); 
      Serial.print(agl);
      Serial.print(",");
      Serial.print(cm);
      Serial.print(".");
    }

    lcd.clear();
    lcd.print(inches, DEC);
    lcd.print("inch, ");
    lcd.print(cm, DEC);
    lcd.println(" cm"); 
    
//위험거리 10센티이내로 설정
    if (cm <= 10)
    {
      lcd.setCursor(0, 1);
      lcd.print("dangerous!!!"); // LCD화면에 위험하다고 나타내기
      tone(speakerPin, tones); // 부저로 알려주기
      digitalWrite(led1, HIGH); // LED로 알려주기
      delay(1000); //위험거리 이내로 들어오면 1초간 서보모터 자동으로 정지
    }
    else
    {
      lcd.print("             "); // 공백으로 초기화
      noTone(speakerPin);
      digitalWrite(led1, LOW);
    }

    delay(80); 
}
