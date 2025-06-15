#include <PS2X_lib.h>
#include <AFMotor.h>
#include <Servo.h>

// DC motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Servo motors
Servo servo1; // pin 9
Servo servo2; // pin 10
int pos1 = 90;
int pos2 = 90;

// PS2 controller pins
#define PS2_DAT A0
#define PS2_CMD A1
#define PS2_SEL A2
#define PS2_CLK A3

PS2X ps2x;

int speedDefault = 200;
int speedFast = 255;
int speedSlow = 150;

void setup() {
  Serial.begin(9600);

  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  if (error == 0) Serial.println("PS2 connected");
  else Serial.println("PS2 not found");

  motor1.setSpeed(speedDefault);
  motor2.setSpeed(speedDefault);
  motor3.setSpeed(speedDefault);
  motor4.setSpeed(speedDefault);

  servo1.attach(9);
  servo2.attach(10);
  servo1.write(pos1);
  servo2.write(pos2);
}

void loop() {
  ps2x.read_gamepad();

  int speed = speedDefault;
  if (ps2x.Button(PSB_L1)) speed = speedFast;
  if (ps2x.Button(PSB_L2)) speed = speedSlow;

  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

  // Right joystick
  int lx = ps2x.Analog(PSS_RX);
  int ly = ps2x.Analog(PSS_RY);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  if (ly < 100) {
    motor1.run(FORWARD); motor2.run(FORWARD);
    motor3.run(FORWARD); motor4.run(FORWARD);
  } else if (ly > 150) {
    motor1.run(BACKWARD); motor2.run(BACKWARD);
    motor3.run(BACKWARD); motor4.run(BACKWARD);
  } else if (lx > 150) {
    motor1.run(FORWARD); motor2.run(BACKWARD);
    motor3.run(FORWARD); motor4.run(BACKWARD);
  } else if (lx < 100) {
    motor1.run(BACKWARD); motor2.run(FORWARD);
    motor3.run(BACKWARD); motor4.run(FORWARD);
  }

  // Servo control
  if (ps2x.ButtonPressed(PSB_PAD_UP)) {
    pos1 = constrain(pos1 + 5, 0, 180);
    servo1.write(pos1);
  }
  if (ps2x.ButtonPressed(PSB_PAD_DOWN)) {
    pos1 = constrain(pos1 - 5, 0, 180);
    servo1.write(pos1);
  }

  if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
    pos2 = constrain(pos2 + 5, 0, 180);
    servo2.write(pos2);
  }
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
    pos2 = constrain(pos2 - 5, 0, 180);
    servo2.write(pos2);
  }

  delay(50);
}
