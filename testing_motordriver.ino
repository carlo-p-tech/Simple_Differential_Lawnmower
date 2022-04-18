// Author: Carlo Pane
// Date: 18/04/2022
// Board: WeMos D1 V2 LawnMower
// Code for a simple differential wheeled robot

// Left Motor Pin Definitions
#define left_L_EN D5
#define left_R_EN D5
#define left_LPWM D7
#define left_RPWM D6

// Right Motor Pin Definitions

void motor_CW() {
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, HIGH);
  analogWrite (L_EN,100);
  Serial.println ("CW");
}

void motor_CCW() {
  digitalWrite (LPWM, HIGH);
  digitalWrite (RPWM, LOW);
  analogWrite (L_EN,100);
  Serial.println ("CCW");
}

void motor_stop() {
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, LOW);
  analogWrite (L_EN,0);
  analogWrite (R_EN,0);
  Serial.println ("Stop");
}

void setup() {
  Serial.begin (115200);
  Serial.println ("Starting...");

  pinMode (L_EN, OUTPUT);
  pinMode (R_EN, OUTPUT);
  
  pinMode (LPWM, OUTPUT);
  pinMode (RPWM, OUTPUT);
}

//Main program
void loop() { 
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, HIGH);
  for(int i = 5; i<=10; i++){
     analogWrite (L_EN,i*10);
     Serial.print(i*10);
     Serial.println ("%");
     delay (1000);
  }
  Serial.println ("Finish Loop");
//  motor_CW(); 
//  delay (1000); 
//  motor_stop();
//  delay (1000);
//  motor_CCW(); 
//  delay (1000);
//  motor_stop(); 
//  delay (1000);
}
