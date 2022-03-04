#ifndef HARDWARESETTINGS_H
#define HARDWARESETTINGS_H

class hardwareSettings {
    public:
     /*Holds all configuration data*/
     ctre::phoenix::sensors::CANCoderConfiguration encoderTurn;
     ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorDrive;
     ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorTurn;

	hardwareSettings() {
		/*Construct all of the configurations with needed values.
		 *FX still have arbitrary values to demonstrate the feature
         */

        //CanCoder
        encoderTurn.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_100Ms;
        encoderTurn.velocityMeasurementWindow = 64;
        encoderTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        encoderTurn.magnetOffsetDegrees = 0;
        encoderTurn.sensorDirection = false;
        encoderTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
        encoderTurn.sensorCoefficient = 360.0 / 4096.0;
        encoderTurn.unitString = std::string("deg");
        encoderTurn.sensorTimeBase = ctre::phoenix::sensors::SensorTimeBase::PerSecond;

        //TalonFX
        motorDrive.primaryPID.selectedFeedbackSensor = ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor;
        motorDrive.primaryPID.selectedFeedbackCoefficient = 1.0;
        motorDrive.sum0Term = ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder;
        motorDrive.sum1Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorDrive.diff0Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor1;
        motorDrive.diff1Term = ctre::phoenix::motorcontrol::FeedbackDevice::PulseWidthEncodedPosition;
        motorDrive.closedloopRamp = 1.705000;
        motorDrive.peakOutputForward = 1.0F;
        motorDrive.peakOutputReverse = -1.0F;
        motorDrive.nominalOutputForward = 0;
        motorDrive.nominalOutputReverse = -0;
        motorDrive.neutralDeadband = 0.001;
        motorDrive.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_25Ms;
        motorDrive.velocityMeasurementWindow = 8;
        motorDrive.slot0.kP = 504.000000;
        motorDrive.slot0.kI = 5.600000;
        motorDrive.slot0.kD = 0.200000;
        motorDrive.slot0.kF = 19.300000;
        motorDrive.slot0.integralZone = 900;
        motorDrive.slot0.allowableClosedloopError = 217;
        motorDrive.slot0.maxIntegralAccumulator = 254.000000;
        motorDrive.slot0.closedLoopPeakOutput = 1.0;
        motorDrive.slot0.closedLoopPeriod = 33;
        motorDrive.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        motorDrive.customParam0 = 3;
        motorDrive.customParam1 = 5;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimit(true, 23.1, 25, 1.4);
        motorDrive.supplyCurrLimit = supplyLimit;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimit(true, 12.1, 87.4, 0.4);
        motorDrive.statorCurrLimit = statorLimit;
        motorDrive.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorDrive.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;

        //TalonFX
        motorTurn.primaryPID.selectedFeedbackSensor = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.primaryPID.selectedFeedbackCoefficient = 1.0;
        motorTurn.sum0Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.sum1Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.diff0Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.diff1Term = ctre::phoenix::motorcontrol::FeedbackDevice::RemoteSensor0;
        motorTurn.closedloopRamp = 1.705000;
        motorTurn.peakOutputForward = 1.0F;
        motorTurn.peakOutputReverse = -1.0F;
        motorTurn.nominalOutputForward = 0.F;
        motorTurn.nominalOutputReverse = -0.F;
        motorTurn.neutralDeadband = 0.001;
        motorTurn.velocityMeasurementPeriod = ctre::phoenix::sensors::SensorVelocityMeasPeriod::Period_25Ms;
        motorTurn.velocityMeasurementWindow = 8;
        motorTurn.slot0.kP = 504.000000;
        motorTurn.slot0.kI = 5.600000;
        motorTurn.slot0.kD = 0.200000;
        motorTurn.slot0.kF = 19.300000;
        motorTurn.slot0.integralZone = 900;
        motorTurn.slot0.allowableClosedloopError = 217;
        motorTurn.slot0.maxIntegralAccumulator = 254.000000;
        motorTurn.slot0.closedLoopPeakOutput = 1.0;
        motorTurn.slot0.closedLoopPeriod = 33;
        motorTurn.motionCruiseVelocity = 50;
        motorTurn.motionAcceleration = 1;
        motorTurn.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        motorTurn.customParam0 = 3;
        motorTurn.customParam1 = 5;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimitB(true, 23.1, 25, 1.4);
        motorTurn.supplyCurrLimit = supplyLimitB;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimitB(true, 12.1, 87.4, 0.4);
        motorTurn.statorCurrLimit = statorLimitB;
        motorTurn.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        motorTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
    }
};
#endif
