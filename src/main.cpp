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

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define A 2
#define B 3
#define C 4
#define D 5
#define closedBlinds 48000

AccelStepper step(8, IN1, IN3, IN2, IN4);

void setup()
{
    step.setMaxSpeed(1000.0);
    step.setAcceleration(500.0);
    step.setSpeed(1000);
}

void loop()
{
    if (digitalRead(A) == 1)
    {
        step.moveTo(closedBlinds);
    }
    else if (digitalRead(B) == 1)
    {
        step.moveTo(0);
    }
    else if (digitalRead(C) == 1)
    {
        step.stop();
    }
    else if (digitalRead(D) == 1)
    {
        step.moveTo(-step.currentPosition());
    }

    step.run();
}