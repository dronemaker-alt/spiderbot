#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 110
#define SERVOMAX 510

#define SERVO_FREQ 50

struct Leg {
  int hip;
  int knee;
};

Leg legs[4] = {
  {0,1},
  {2,3},
  {4,5},
  {6,7}
};

void setServoAngle(uint8_t channel, int angle)
{
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void centerRobot()
{
  for (int i = 0; i < 4; i++) {
    setServoAngle(legs[i].hip, 90);
    setServoAngle(legs[i].knee, 90);
  }
}

void standPose()
{
  setServoAngle(0, 90);
  setServoAngle(1, 110);

  setServoAngle(2, 90);
  setServoAngle(3, 110);

  setServoAngle(4, 90);
  setServoAngle(5, 110);

  setServoAngle(6, 90);
  setServoAngle(7, 110);
}

void stepLeg(uint8_t hip, uint8_t knee)
{
  setServoAngle(knee, 80);
  delay(100);

  setServoAngle(hip, 110);
  delay(100);

  setServoAngle(knee, 110);
  delay(100);

  setServoAngle(hip, 90);
  delay(100);
}

void creepForward()
{
  stepLeg(0,1);
  stepLeg(6,7);
  stepLeg(2,3);
  stepLeg(4,5);
}

void setup()
{
  Serial.begin(115200);

  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);

  delay(500);

  centerRobot();
  delay(1000);

  standPose();
}

void loop()
{
  creepForward();
}
