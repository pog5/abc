#define MOTOR_R_B 4
#define MOTOR_L_B 2
#define MOTOR_R_F 7
#define MOTOR_L_F 3
#define LEFT_T 8
#define LEFT_E 9
#define FRONT_T 12
#define FRONT_E 13
#define MOTORSPEED_L 6
#define MOTORSPEED_R 5
#define DEBUG true

void setup() {
  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
  pinMode(LEFT_E, INPUT);
  pinMode(LEFT_T, OUTPUT);
  pinMode(FRONT_E, INPUT);
  pinMode(FRONT_T, OUTPUT);
  pinMode(MOTORSPEED_L, OUTPUT);
  pinMode(MOTORSPEED_R, OUTPUT);
  analogWrite(MOTORSPEED_L, 220);
  analogWrite(MOTORSPEED_R, 220);
  if (DEBUG) {
    Serial.begin(9600);
  }
}

void loop() {
  float left = (checkLeftSensor()*.0343)/2;
  float front = (checkFrontSensor()*.0343)/2;
  
  if (DEBUG) {
    Serial.write("L: ");
    Serial.print(left);
    Serial.write(" F: ");
    Serial.println(front);
  }
  
  if (left < 5.0f && front < 5.0f) {
    goRight();
  } else if (left < 5.0f) {
    goForwards();
  } else if (front < 5.0f) {
    goLeft();
  } else {
    goBackwards();
  }
}

float checkLeftSensor() {
  digitalWrite(LEFT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(LEFT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_T, LOW);
  return float(pulseIn(LEFT_E, HIGH));
}

float checkFrontSensor() {
  digitalWrite(FRONT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_T, LOW);
  return float(pulseIn(FRONT_E, HIGH));
}

void goForwards() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTORSPEED_L, 200);
  analogWrite(MOTORSPEED_R, 200);
}

void goBackwards() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTORSPEED_L, 220);
  analogWrite(MOTORSPEED_R, 220);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTORSPEED_L, 120);
  analogWrite(MOTORSPEED_R, 120);
}

void goRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTORSPEED_L, 120);
  analogWrite(MOTORSPEED_R, 120);
}

void goToHell() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, LOW);
}
