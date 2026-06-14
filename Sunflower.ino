#include <Servo.h>   // Include servo library

// Create servo objects
Servo servoHorizontal;   // Left-Right movement
Servo servoVertical;     // Up-Down movement

// Servo signal pins
const int SERVO_H_PIN = 5;
const int SERVO_V_PIN = 3;

// LDR pins
const int LDR_TOP = A1;
const int LDR_LEFT = A2;
const int LDR_RIGHT = A3;
const int LDR_BOTTOM = A4;

// Starting servo positions
int posHorizontal = 90;
int posVertical = 90;

// Tracker settings
const int THRESHOLD = 50;  // Minimum light difference required to move
const int STEP_SIZE = 2;   // Servo movement per step
const int DELAY_TIME = 30; // Delay between readings

void setup()
{
  // Start serial communication
  Serial.begin(9600);

  // Connect servos to Arduino pins
  servoHorizontal.attach(SERVO_H_PIN);
  servoVertical.attach(SERVO_V_PIN);

  // Move servos to center position
  servoHorizontal.write(posHorizontal);
  servoVertical.write(posVertical);

  Serial.println("Solar Tracker Started");
}

void loop()
{
  // Read all LDR values
  int topVal = analogRead(LDR_TOP);
  int leftVal = analogRead(LDR_LEFT);
  int rightVal = analogRead(LDR_RIGHT);
  int bottomVal = analogRead(LDR_BOTTOM);

  // Print sensor values on Serial Monitor
  Serial.print("Top = ");
  Serial.print(topVal);

  Serial.print("  Left = ");
  Serial.print(leftVal);

  Serial.print("  Right = ");
  Serial.print(rightVal);

  Serial.print("  Bottom = ");
  Serial.println(bottomVal);

  // -------------------------------
  // HORIZONTAL TRACKING
  // Compare left and right LDRs
  // -------------------------------

  if (abs(leftVal - rightVal) > THRESHOLD)
  {
    // If left side receives more light
    if (leftVal > rightVal)
    {
      posHorizontal = posHorizontal - STEP_SIZE;
    }

    // If right side receives more light
    else
    {
      posHorizontal = posHorizontal + STEP_SIZE;
    }

    // Keep servo angle between 0 and 180
    posHorizontal = constrain(posHorizontal, 0, 180);

    // Move servo
    servoHorizontal.write(posHorizontal);
  }

  // -------------------------------
  // VERTICAL TRACKING
  // Compare top and bottom LDRs
  // -------------------------------

  if (abs(topVal - bottomVal) > THRESHOLD)
  {
    // If top receives more light
    if (topVal > bottomVal)
    {
      posVertical = posVertical - STEP_SIZE;
    }

    // If bottom receives more light
    else
    {
      posVertical = posVertical + STEP_SIZE;
    }

    // Keep servo angle between 0 and 180
    posVertical = constrain(posVertical, 0, 180);

    // Move servo
    servoVertical.write(posVertical);
  }

  // Print servo positions
  Serial.print("Horizontal Servo = ");
  Serial.print(posHorizontal);

  Serial.print("  Vertical Servo = ");
  Serial.println(posVertical);

  // Small delay for smooth operation
  delay(DELAY_TIME);
}
