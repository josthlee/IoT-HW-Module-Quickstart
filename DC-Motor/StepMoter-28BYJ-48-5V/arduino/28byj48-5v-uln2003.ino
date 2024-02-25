#include <Unistep2.h>

Unistep2 stepper(8, 9, 10, 11, 4096, 1000);// IN1, IN2, IN3, IN4, Total number of steps, delay (in micros) per step

void setup()
{

}

void loop()
{
  stepper.run();  // Stepper motor run


  if ( stepper.stepsToGo() == 0 ){ // If stepsToGo = 0, it means that the stepper motor has completed the required steps.
    // delay(500);
    stepper.move(4096);    // Rotate clockwise one full revolution
    //stepper.move(-4096);  // Rotate counter clockwise one full revolution
  }
}
