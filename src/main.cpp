
// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <Arduino.h>
#include <AccelStepper.h>

int IN1 = 5;   // D1
int IN2 = 4;   // D2
int EN = 0;    // D3

AccelStepper stepper(AccelStepper::FULL2WIRE, IN1, IN2);

unsigned long now = 0;
unsigned long doneMillis = 0;
boolean done = false;

int stepCount = 1000;
void setup()
{  
    now = millis();
    Serial.begin(9600);
    stepper.setEnablePin(EN);
    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);
    stepper.move(stepCount);
    //stepper.disableOutputs();   // Otherwise, outputs maintain motor "locked"
    Serial.println("Started");
}

void stop() {
    stepper.stop();
    stepper.disableOutputs();
    Serial.println("Stopped");
    //done = true;
    now = millis();
    stepper.move(stepCount);
}

void loop()
{
    if (millis() - now < 5000) return;
    // if (done) return;

    if (stepper.distanceToGo() == 0) {
        stop();
    }
    else {
        stepper.enableOutputs();  
        stepper.run();
    }
}

