#define MOTOR_R_B 3
#define MOTOR_L_B 2
#define MOTOR_R_F 4
#define MOTOR_L_F 5

void setup() {
  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
}

void loop() {
  //goLeft();
  delay(1000);
}

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
}

void goBackwards() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
}

void goRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
}
