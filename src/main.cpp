#include <Arduino.h>
#include <AccelStepper.h>
#include <GyverButton.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define closedBlinds 48000

GButton btn(2);

AccelStepper step(8, IN1, IN3, IN2, IN4);

void isr()
{
    btn.tick();
}

void setup()
{
    attachInterrupt(1, isr, CHANGE);
    step.setMaxSpeed(1000.0);
    step.setAcceleration(500.0);
    step.setSpeed(1000);
}

void loop()
{
    btn.tick();

    if (btn.isSingle())
    {
        step.stop();
    }
    else if (btn.isDouble())
    {
        step.moveTo(-step.currentPosition());
    }
    else if (btn.isTriple())
    {
        step.moveTo(closedBlinds);
    }
    else if (btn.isHolded())
    {
        step.moveTo(0);
    }
    else if (btn.getClicks() == 4)
    {
        step.setCurrentPosition(0);
    }

    step.run();
}