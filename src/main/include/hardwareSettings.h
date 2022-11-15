#ifndef HARDWARESETTINGS_H
#define HARDWARESETTINGS_H

class hardwareSettings {
    public:
     /*Holds all configuration data*/
     ctre::phoenix::sensors::CANCoderConfiguration encoderTurn;
     ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorDrive;
     ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorTurn;

	hardwareSettings() {

        //CanCoder
        motorTurn.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_100Ms;
        encoderTurn.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_100Ms;
        //encoderTurn.velocityMeasurementWindow = 64;
        motorTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        encoderTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        encoderTurn.sensorDirection = false;
        //motorTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
        encoderTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
        encoderTurn.sensorCoefficient = 360.0 / 4096.0;
        encoderTurn.unitString = std::string("deg");
        encoderTurn.sensorTimeBase = ctre::phoenix::sensors::SensorTimeBase::PerSecond;

        //TalonFX
        motorDrive.primaryPID.selectedFeedbackSensor = ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor;
        motorDrive.primaryPID.selectedFeedbackCoefficient = 1.0;
        motorDrive.closedloopRamp = 1.705000;
        motorDrive.peakOutputForward = 0.20F;
        motorDrive.peakOutputReverse = -0.20F;
        motorDrive.nominalOutputForward = 0.0;
        motorDrive.nominalOutputReverse = -0.0;
        motorDrive.neutralDeadband = 0.001;
        motorDrive.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_100Ms;
        motorDrive.slot0.kP = 0;
        motorDrive.slot0.kI = 0;
        motorDrive.slot0.kD = 0;
        motorDrive.slot0.kF =  (0.5*1023.0)/(22100.0*0.5);
        //motorDrive.slot0.integralZone = 900;
        motorDrive.slot0.allowableClosedloopError = 0;
        //motorDrive.slot0.maxIntegralAccumulator = 254.000000;
        motorDrive.slot0.closedLoopPeakOutput = 1.0;
        //motorDrive.slot0.closedLoopPeriod = 33;
        motorDrive.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimit(true, 23.1, 25, 1.4);
        //motorDrive.supplyCurrLimit = supplyLimit;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimit(true, 12.1, 87.4, 0.4);
        //motorDrive.statorCurrLimit = statorLimit;
        motorDrive.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorDrive.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;

        //TalonFX
        motorTurn.primaryPID.selectedFeedbackSensor = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.primaryPID.selectedFeedbackCoefficient = 1.0;
        motorTurn.closedloopRamp = 1.0;
        motorTurn.peakOutputForward = 0.20F; //0.15
        motorTurn.peakOutputReverse = -0.20F; //0.15
        motorTurn.nominalOutputForward = 0.018F;
        motorTurn.nominalOutputReverse = -0.018F;
        motorTurn.neutralDeadband = 0.001;
        motorTurn.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_100Ms;
        motorTurn.slot0.kP = 0.35;
        motorTurn.slot0.kI = 0;
        motorTurn.slot0.kD = 40;
        motorTurn.slot0.kF = 0;
        //motorTurn.slot0.integralZone = 0;
        motorTurn.slot0.allowableClosedloopError = 1*(4096/360);
        //motorTurn.slot0.maxIntegralAccumulator = 0;
        motorTurn.slot0.closedLoopPeakOutput = 1.0;
        //motorTurn.slot0.closedLoopPeriod = 1;
        //motorTurn.motionCruiseVelocity = 500;
        //motorTurn.motionAcceleration = 500;
        motorTurn.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimitB(true, 23.1, 25, 1.4);
        //motorTurn.supplyCurrLimit = supplyLimitB;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimitB(true, 12.1, 87.4, 0.4);
        //motorTurn.statorCurrLimit = statorLimitB;
        motorTurn.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        motorTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
    }
};
#endif
