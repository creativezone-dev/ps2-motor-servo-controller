
# PS2 Motor & Servo Controller

This project controls 4 DC motors and 2 servo motors using a wireless PS2 gamepad.  
It's built with Arduino UNO, Motor Shield, and the PS2X library.

## 🎮 Features

- 4 DC motors controlled by right joystick
- 2 servo motors controlled by D-pad buttons (UP/DOWN & LEFT/RIGHT)
- Variable motor speed using L1 (fast) and L2 (slow)
- Simple control system ideal for RC car, robot, or arm platform

## 🔧 Hardware Required

- Arduino UNO
- Motor Driver Shield (e.g. L298P)
- 4x DC Motors
- 2x Servo Motors (SG90/MG996R)
- Wireless PS2 Controller + Receiver
- External Power Supply (6V–12V for motors, 5V for servos)

## 🧠 Pin Mapping

| Component         | Pin      |
|------------------|----------|
| PS2 DAT          | A0       |
| PS2 CMD          | A1       |
| PS2 SEL (CS)     | A2       |
| PS2 CLK          | A3       |
| Servo 1          | D9       |
| Servo 2          | D10      |
| Motor Ports      | M1–M4 on motor shield |

## 📦 Libraries Used

- [PS2X_lib](https://github.com/madsci1016/Arduino-PS2X)
- AFMotor (Adafruit Motor Shield library)
- Servo (built-in)

## 📝 How It Works

- Use right joystick (RX/RY) to move motors:
  - Forward, Backward, Turn Left, Turn Right
- Press D-PAD UP/DOWN to move Servo 1
- Press D-PAD LEFT/RIGHT to move Servo 2
- Press L1 for high speed, L2 for low speed

## 🚀 Future Improvements

- Add support for analog joystick servo control
- OLED or LCD display
- Battery monitoring
