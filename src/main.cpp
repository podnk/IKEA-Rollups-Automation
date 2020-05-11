/*
    step.stop();                          // Остановка
    step.moveTo(-step.currentPosition()); // Переместиться в изначальную позицию отосительно текущей
    step.moveTo(closedBlinds);            // закрыть роллапы
    step.moveTo(0);                       // Переместиться в начальную позицию
    step.setCurrentPosition(0);           // Установить текущую позицию в качестве начальной
    step.run();                           // Запуск действий
*/

#include <Arduino.h>
#include <AccelStepper.h>

//Stepper 1
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

// Remote module
#define A 2
#define B 3
#define C 4
#define D 5

// Closed blind stepper motor count of steps
#define closedBlinds 48000

AccelStepper step(8, IN1, IN3, IN2, IN4);

void closeBlinds()
{
    step.enableOutputs();
    step.moveTo(closedBlinds);
    while (step.distanceToGo() != 0)
    {
        step.run();
    }
    step.disableOutputs();
}

void moveToZero()
{
    step.enableOutputs();
    step.moveTo(0);
    while (step.distanceToGo() != 0)
    {
        step.run();
    }
    step.disableOutputs();
}

void mainLoop()
{
    if (digitalRead(A) == 1)
    {
        if (step.currentPosition() != 0)
        {
            moveToZero();
        }
        else
        {
            closeBlinds();
        }
    }
}

void setup()
{
    step.setMaxSpeed(1000.0);
    step.setAcceleration(500.0);
    step.setSpeed(1000);
}

void loop()
{
    mainLoop();
}