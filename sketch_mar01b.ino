#define MOTOR_R_B 4
#define MOTOR_L_B 2
#define MOTOR_R_F 7
#define MOTOR_L_F 3
#define LEFT_T 8
#define LEFT_E 9
#define FRONT_T 10
#define FRONT_E 11
#define MOTOR_SPEED_L 6
#define MOTOR_SPEED_R 6

#define SENSOR_CALC 340 / 10000 / 2
#define ROTATE_SPEED_L 220
#define ROTATE_SPEED_R 220

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
  analogWrite(MOTOR_SPEED_L, ROTATE_SPEED_L);
  analogWrite(MOTOR_SPEED_R, ROTATE_SPEED_R);
  if (DEBUG) {
    Serial.begin(9600);
  }
}
void loop() {
  //return;
  float left = checkLeftSensor();
  float front = checkFrontSensor();
  if (left > 15.0f) {
    goLeft();
  } else if (front < 15.0f && left < 15.0f) {
    goRight();
  } else if (front >= 15.0f) {
    goForwards();
  } else {
    goBackwards();
  }
  if (DEBUG) {
    Serial.write("L: ");
    Serial.print(left);
    Serial.write(" F: ");
    Serial.println(front);
  }
  delay(90);
}
//void loop() {}
float checkLeftSensor() {
  digitalWrite(LEFT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(LEFT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_T, LOW);
  return float(pulseIn(LEFT_E, HIGH)) * SENSOR_CALC;
}

float checkFrontSensor() {
  digitalWrite(FRONT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_T, LOW);
  return float(pulseIn(FRONT_E, HIGH)) * SENSOR_CALC;
}

void goForwards() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, ROTATE_SPEED_L);
  analogWrite(MOTOR_SPEED_R, ROTATE_SPEED_R);
}

void goBackwards() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, ROTATE_SPEED_L);
  analogWrite(MOTOR_SPEED_R, ROTATE_SPEED_R);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, ROTATE_SPEED_L);
  analogWrite(MOTOR_SPEED_R, ROTATE_SPEED_R);
}

void goRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, ROTATE_SPEED_L);
  analogWrite(MOTOR_SPEED_R, ROTATE_SPEED_R);
}

void stopMoving() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, LOW);
}
