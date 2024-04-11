#define MOTOR_R_B 2
#define MOTOR_L_B 7
#define MOTOR_R_F 4
#define MOTOR_L_F 3
#define LEFT 10
#define FRONT 9
#define MOTORSPEED_L 5
#define MOTORSPEED_R 6
#define DEBUG false
/// @brief nigger intelect or divine intervention
void setup() {
  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
  pinMode(LEFT, INPUT);
  pinMode(FRONT, INPUT);
  pinMode(MOTORSPEED_L, OUTPUT);
  pinMode(MOTORSPEED_R, OUTPUT);
  analogWrite(MOTORSPEED_L, 90);
  analogWrite(MOTORSPEED_R, 90);
  if (DEBUG) {
    Serial.begin(9600);
  }
}

void loop() {
  bool left = digitalRead(LEFT);
  bool front = digitalRead(FRONT);
  if (DEBUG) {
    Serial.write("L: ");
    Serial.print(left);
    Serial.write(" F: ");
    Serial.println(front);
  }
  
  if (left == 1) {
    if (DEBUG) {
      Serial.println("RIGHT");
    }
    goLeft();
  } else if (front == 0) {
    if (DEBUG) {
      Serial.println("LEFT");
    }
    goRight();
  } else {
    goForwards();
  }
}

void goForwards() {
  digitalWrite(MOTOR_L_F, 1);
  digitalWrite(MOTOR_L_B, 0);
  digitalWrite(MOTOR_R_F, 1);
  digitalWrite(MOTOR_R_B, 0);
  // analogWrite(MOTORSPEED_L, 60);
  // analogWrite(MOTORSPEED_R, 60);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, 0);
  digitalWrite(MOTOR_L_B, 1);
  digitalWrite(MOTOR_R_F, 1);
  digitalWrite(MOTOR_R_B, 0);
  // analogWrite(MOTORSPEED_L, 45);  
  // analogWrite(MOTORSPEED_R, 90);
}

void goRight() {
  digitalWrite(MOTOR_L_F, 1);
  digitalWrite(MOTOR_L_B, 0);
  digitalWrite(MOTOR_R_F, 0);
  digitalWrite(MOTOR_R_B, 1);
  // analogWrite(MOTORSPEED_L, 60);
  // analogWrite(MOTORSPEED_R, 60);
}

void goBack() {
  digitalWrite(MOTOR_L_F, 0);
  digitalWrite(MOTOR_L_B, 1);
  digitalWrite(MOTOR_R_F, 0);
  digitalWrite(MOTOR_R_B, 1);
  // analogWrite(MOTORSPEED_L, 60);
  // analogWrite(MOTORSPEED_R, 60);
}