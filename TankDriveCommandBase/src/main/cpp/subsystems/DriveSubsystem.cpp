// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
#include <ctre/Phoenix.h>
#include "ctre/phoenix/motorcontrol/can/TalonFX.h"

phoenix::motorcontrol::can::TalonFX leftFront{1};
phoenix::motorcontrol::can::TalonFX leftBack{2};
phoenix::motorcontrol::can::TalonFX rightFront{3};
phoenix::motorcontrol::can::TalonFX rightBack{4};

DriveSubsystem::DriveSubsystem() {
    leftFront.ConfigFactoryDefault();
    leftBack.ConfigFactoryDefault();

    rightFront.ConfigFactoryDefault();
    rightFront.ConfigFactoryDefault();


    leftBack.Follow(leftFront);
    rightBack.Follow(rightFront); 


    leftBack.SetInverted(true);
    rightBack.SetInverted(false);
}


// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {}

void set(double leftSpeed, double rightSpeed){
leftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, leftSpeed);
}