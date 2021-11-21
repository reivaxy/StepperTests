
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

int IN1 = 5;
int IN2 = 4;

AccelStepper stepper(AccelStepper::FULL2WIRE, IN1, IN2);

void setup()
{  
    stepper.setMaxSpeed(300.0);
    stepper.setAcceleration(100.0);
    stepper.moveTo(96);
 
}

void loop()
{
    // Change direction at the limits
    if (stepper.distanceToGo() == 0)
	    stepper.stop();
    else
        stepper.run();
}