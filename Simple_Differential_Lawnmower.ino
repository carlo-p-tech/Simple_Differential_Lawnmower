// Author: Carlo Pane
// Date: 18/04/2022
// Board: WeMos D1 V2
// Code for a simple differential wheeled robot + (hopefully Lawnmower)

// Left Motor Pin Definitions
#define left_L_EN D5
#define left_R_EN D6
#define left_LPWM D5
#define left_RPWM D4

// Right Motor Pin Definitions
#define right_L_EN D7
#define right_R_EN D7
#define right_LPWM D3
#define right_RPWM D2

// Left Motor Functions
void left_motor_CW() {
  digitalWrite (left_LPWM, LOW);
  digitalWrite (left_RPWM, HIGH);
  analogWrite (left_L_EN,100);
  Serial.println ("left CW");
}

void left_motor_CCW() {
  digitalWrite (left_LPWM, HIGH);
  digitalWrite (left_RPWM, LOW);
  analogWrite (left_L_EN,100);
  Serial.println ("left CCW");
}

void left_motor_stop() {
  digitalWrite (left_LPWM, LOW);
  digitalWrite (left_RPWM, LOW);
  analogWrite (left_L_EN,0);
  analogWrite (left_R_EN,0);
  Serial.println ("left Stop");
}

// Right Motor Functions
void right_motor_CW() {
  digitalWrite (right_LPWM, LOW);
  digitalWrite (right_RPWM, HIGH);
  analogWrite (right_L_EN,100);
  Serial.println ("right CW");
}

void right_motor_CCW() {
  digitalWrite (right_LPWM, HIGH);
  digitalWrite (right_RPWM, LOW);
  analogWrite (right_L_EN,100);
  Serial.println ("right CCW");
}

void right_motor_stop() {
  digitalWrite (right_LPWM, LOW);
  digitalWrite (right_RPWM, LOW);
  analogWrite (right_L_EN,0);
  analogWrite (right_R_EN,0);
  Serial.println ("right Stop");
}

// Composite Motor Actions
void motors_stop(){
  left_motor_stop();
  right_motor_stop();
}

void setup() {
  Serial.begin (115200);
  Serial.println ("Starting...");

  pinMode (left_L_EN, OUTPUT);
  pinMode (left_R_EN, OUTPUT);
  pinMode (left_LPWM, OUTPUT);
  pinMode (left_RPWM, OUTPUT);
  
  pinMode (right_L_EN, OUTPUT);
  pinMode (right_R_EN, OUTPUT);
  pinMode (right_LPWM, OUTPUT);
  pinMode (right_RPWM, OUTPUT);
}

void loop() { 
  // Forward Action
  left_motor_CW();
  right_motor_CW();
  delay (5000);
  
  motors_stop();
  delay (1000);

  // Reverse Action
  left_motor_CCW();
  right_motor_CCW();
  delay (5000);

  motors_stop();
  delay (1000);
  
  // Left Action
  left_motor_CCW();
  right_motor_CW();
  delay (5000);

  motors_stop();
  delay (1000);

  // Right Action
  left_motor_CW();
  right_motor_CCW();
  delay (5000);
  
//  
//  digitalWrite (LPWM, LOW);
//  digitalWrite (RPWM, HIGH);
//  for(int i = 5; i<=10; i++){
//     analogWrite (L_EN,i*10);
//     Serial.print(i*10);
//     Serial.println ("%");
//     delay (1000);
//  }
// Serial.println ("Finish Loop");
//  motor_CW(); 
//  delay (1000); 
//  motor_stop();
//  delay (1000);
//  motor_CCW(); 
//  delay (1000);
//  motor_stop(); 
//  delay (1000);
}
