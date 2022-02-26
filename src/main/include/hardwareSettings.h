#ifndef SWERVEMODULECONFIGS_H
#define SWERVEMODULECONFIGS_H

#include <ctre/Phoenix.h>

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
        encoderTurn.velocityMeasurementPeriod = SensorVelocityMeasPeriod::Period_100Ms;
        encoderTurn.velocityMeasurementWindow = 64;
        encoderTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Unsigned_0_to_360;
        encoderTurn.magnetOffsetDegrees = 0;
        encoderTurn.sensorDirection = false;
        encoderTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
        encoderTurn.sensorCoefficient = 360.0 / 4096.0;
        encoderTurn.unitString = std::string("deg");
        encoderTurn.sensorTimeBase = ctre::phoenix::sensors::SensorTimeBase::PerSecond;

        //TalonFX
        motorDrive.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
        motorDrive.primaryPID.selectedFeedbackCoefficient = 1.0;
        motorDrive.auxiliaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
        motorDrive.auxiliaryPID.selectedFeedbackCoefficient = 1.0;
        motorDrive.forwardLimitSwitchSource = LimitSwitchSource_Deactivated;
        motorDrive.reverseLimitSwitchSource = LimitSwitchSource_Deactivated;

        motorDrive.sum0Term = FeedbackDevice::QuadEncoder;
        motorDrive.sum1Term = FeedbackDevice::RemoteSensor0;
        motorDrive.diff0Term = FeedbackDevice::RemoteSensor1;
        motorDrive.diff1Term = FeedbackDevice::PulseWidthEncodedPosition;
        motorDrive.openloopRamp = 1.023000;
        motorDrive.closedloopRamp = 1.705000;
        motorDrive.peakOutputForward = 0.939394;
        motorDrive.peakOutputReverse = -0.289345F;
        motorDrive.nominalOutputForward = 0.739980;
        motorDrive.nominalOutputReverse = -0.119257F;
        motorDrive.neutralDeadband = 0.199413;
        motorDrive.voltageCompSaturation = 9.296875;
        motorDrive.voltageMeasurementFilter = 16;
        motorDrive.velocityMeasurementPeriod = SensorVelocityMeasPeriod::Period_25Ms;
        motorDrive.velocityMeasurementWindow = 8;
        motorDrive.forwardLimitSwitchDeviceID = 6;
        motorDrive.reverseLimitSwitchDeviceID = 4;
        motorDrive.forwardLimitSwitchNormal = LimitSwitchNormal_NormallyClosed;
        motorDrive.reverseLimitSwitchNormal = LimitSwitchNormal_Disabled;
        motorDrive.forwardSoftLimitThreshold = 2767;
        motorDrive.reverseSoftLimitThreshold = -1219;
        motorDrive.forwardSoftLimitEnable = true;
        motorDrive.reverseSoftLimitEnable = true;
        motorDrive.slot0.kP = 504.000000;
        motorDrive.slot0.kI = 5.600000;
        motorDrive.slot0.kD = 0.200000;
        motorDrive.slot0.kF = 19.300000;
        motorDrive.slot0.integralZone = 900;
        motorDrive.slot0.allowableClosedloopError = 217;
        motorDrive.slot0.maxIntegralAccumulator = 254.000000;
        motorDrive.slot0.closedLoopPeakOutput = 0.869990;
        motorDrive.slot0.closedLoopPeriod = 33;
        motorDrive.slot1.kP = 155.600000;
        motorDrive.slot1.kI = 5.560000;
        motorDrive.slot1.kD = 8.868600;
        motorDrive.slot1.kF = 454.000000;
        motorDrive.slot1.integralZone = 100;
        motorDrive.slot1.allowableClosedloopError = 200;
        motorDrive.slot1.maxIntegralAccumulator = 91.000000;
        motorDrive.slot1.closedLoopPeakOutput = 0.199413;
        motorDrive.slot1.closedLoopPeriod = 34;
        motorDrive.slot2.kP = 223.232000;
        motorDrive.slot2.kI = 34.000000;
        motorDrive.slot2.kD = 67.000000;
        motorDrive.slot2.kF = 6.323232;
        motorDrive.slot2.integralZone = 44;
        motorDrive.slot2.allowableClosedloopError = 343;
        motorDrive.slot2.maxIntegralAccumulator = 334.000000;
        motorDrive.slot2.closedLoopPeakOutput = 0.399804;
        motorDrive.slot2.closedLoopPeriod = 14;
        motorDrive.slot3.kP = 34.000000;
        motorDrive.slot3.kI = 32.000000;
        motorDrive.slot3.kD = 436.000000;
        motorDrive.slot3.kF = 0.343430;
        motorDrive.slot3.integralZone = 2323;
        motorDrive.slot3.allowableClosedloopError = 543;
        motorDrive.slot3.maxIntegralAccumulator = 687.000000;
        motorDrive.slot3.closedLoopPeakOutput = 0.129032;
        motorDrive.slot3.closedLoopPeriod = 12;
        motorDrive.auxPIDPolarity = true;
        motorDrive.remoteFilter0.remoteSensorDeviceID = 22;
        motorDrive.remoteFilter0.remoteSensorSource = RemoteSensorSource::RemoteSensorSource_GadgeteerPigeon_Roll;
        motorDrive.remoteFilter1.remoteSensorDeviceID = 41;
        motorDrive.remoteFilter1.remoteSensorSource = RemoteSensorSource::RemoteSensorSource_GadgeteerPigeon_Yaw;
        motorDrive.motionCruiseVelocity = 37;
        motorDrive.motionAcceleration = 3;
        motorDrive.motionProfileTrajectoryPeriod = 11;
        motorDrive.feedbackNotContinuous = true;
        motorDrive.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        motorDrive.clearPositionOnLimitF = true;
        motorDrive.clearPositionOnLimitR = true;
        motorDrive.clearPositionOnQuadIdx = false;
        motorDrive.limitSwitchDisableNeutralOnLOS = true;
        motorDrive.softLimitDisableNeutralOnLOS = false;
        motorDrive.pulseWidthPeriod_EdgesPerRot = 9;
        motorDrive.pulseWidthPeriod_FilterWindowSz = 32;
        motorDrive.customParam0 = 3;
        motorDrive.customParam1 = 5;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimit(true, 23.1, 25, 1.4);
        motorDrive.supplyCurrLimit = supplyLimit;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimit(true, 12.1, 87.4, 0.4);
        motorDrive.statorCurrLimit = statorLimit;
        motorDrive.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorDrive.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Signed_PlusMinus180;
        motorDrive.integratedSensorOffsetDegrees = 42;
        motorDrive.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;

        //TalonFX
        motorTurn.primaryPID.selectedFeedbackSensor = FeedbackDevice::RemoteSensor0;
        motorTurn.primaryPID.selectedFeedbackCoefficient = 0.328293;
        motorTurn.auxiliaryPID.selectedFeedbackSensor = FeedbackDevice::RemoteSensor0;
        motorTurn.auxiliaryPID.selectedFeedbackCoefficient = 0.877686;
        motorTurn.forwardLimitSwitchSource = LimitSwitchSource_Deactivated;
        motorTurn.reverseLimitSwitchSource = LimitSwitchSource_RemoteTalonSRX;
        motorTurn.sum0Term = FeedbackDevice::QuadEncoder;
        motorTurn.sum1Term = FeedbackDevice::RemoteSensor0;
        motorTurn.diff0Term = FeedbackDevice::RemoteSensor1;
        motorTurn.diff1Term = FeedbackDevice::PulseWidthEncodedPosition;
        motorTurn.openloopRamp = 1.023000;
        motorTurn.closedloopRamp = 1.705000;
        motorTurn.peakOutputForward = 0.939394;
        motorTurn.peakOutputReverse = -0.289345F;
        motorTurn.nominalOutputForward = 0.739980;
        motorTurn.nominalOutputReverse = -0.119257F;
        motorTurn.neutralDeadband = 0.199413;
        motorTurn.voltageCompSaturation = 9.296875;
        motorTurn.voltageMeasurementFilter = 16;
        motorTurn.velocityMeasurementPeriod = SensorVelocityMeasPeriod::Period_25Ms;
        motorTurn.velocityMeasurementWindow = 8;
        motorTurn.forwardLimitSwitchDeviceID = 6;
        motorTurn.reverseLimitSwitchDeviceID = 4;
        motorTurn.forwardLimitSwitchNormal = LimitSwitchNormal_NormallyClosed;
        motorTurn.reverseLimitSwitchNormal = LimitSwitchNormal_Disabled;
        motorTurn.forwardSoftLimitThreshold = 2767;
        motorTurn.reverseSoftLimitThreshold = -1219;
        motorTurn.forwardSoftLimitEnable = true;
        motorTurn.reverseSoftLimitEnable = true;
        motorTurn.slot0.kP = 504.000000;
        motorTurn.slot0.kI = 5.600000;
        motorTurn.slot0.kD = 0.200000;
        motorTurn.slot0.kF = 19.300000;
        motorTurn.slot0.integralZone = 900;
        motorTurn.slot0.allowableClosedloopError = 217;
        motorTurn.slot0.maxIntegralAccumulator = 254.000000;
        motorTurn.slot0.closedLoopPeakOutput = 0.869990;
        motorTurn.slot0.closedLoopPeriod = 33;
        motorTurn.slot1.kP = 155.600000;
        motorTurn.slot1.kI = 5.560000;
        motorTurn.slot1.kD = 8.868600;
        motorTurn.slot1.kF = 454.000000;
        motorTurn.slot1.integralZone = 100;
        motorTurn.slot1.allowableClosedloopError = 200;
        motorTurn.slot1.maxIntegralAccumulator = 91.000000;
        motorTurn.slot1.closedLoopPeakOutput = 0.199413;
        motorTurn.slot1.closedLoopPeriod = 34;
        motorTurn.slot2.kP = 223.232000;
        motorTurn.slot2.kI = 34.000000;
        motorTurn.slot2.kD = 67.000000;
        motorTurn.slot2.kF = 6.323232;
        motorTurn.slot2.integralZone = 44;
        motorTurn.slot2.allowableClosedloopError = 343;
        motorTurn.slot2.maxIntegralAccumulator = 334.000000;
        motorTurn.slot2.closedLoopPeakOutput = 0.399804;
        motorTurn.slot2.closedLoopPeriod = 14;
        motorTurn.slot3.kP = 34.000000;
        motorTurn.slot3.kI = 32.000000;
        motorTurn.slot3.kD = 436.000000;
        motorTurn.slot3.kF = 0.343430;
        motorTurn.slot3.integralZone = 2323;
        motorTurn.slot3.allowableClosedloopError = 543;
        motorTurn.slot3.maxIntegralAccumulator = 687.000000;
        motorTurn.slot3.closedLoopPeakOutput = 0.129032;
        motorTurn.slot3.closedLoopPeriod = 12;
        motorTurn.auxPIDPolarity = true;
        motorTurn.remoteFilter0.remoteSensorDeviceID = 22;
        motorTurn.remoteFilter0.remoteSensorSource = RemoteSensorSource::RemoteSensorSource_GadgeteerPigeon_Roll;
        motorTurn.remoteFilter1.remoteSensorDeviceID = 41;
        motorTurn.remoteFilter1.remoteSensorSource = RemoteSensorSource::RemoteSensorSource_GadgeteerPigeon_Yaw;
        motorTurn.motionCruiseVelocity = 37;
        motorTurn.motionAcceleration = 3;
        motorTurn.motionProfileTrajectoryPeriod = 11;
        motorTurn.feedbackNotContinuous = true;
        motorTurn.remoteSensorClosedLoopDisableNeutralOnLOS = false;
        motorTurn.clearPositionOnLimitF = true;
        motorTurn.clearPositionOnLimitR = true;
        motorTurn.clearPositionOnQuadIdx = false;
        motorTurn.limitSwitchDisableNeutralOnLOS = true;
        motorTurn.softLimitDisableNeutralOnLOS = false;
        motorTurn.pulseWidthPeriod_EdgesPerRot = 9;
        motorTurn.pulseWidthPeriod_FilterWindowSz = 32;
        motorTurn.customParam0 = 3;
        motorTurn.customParam1 = 5;
        ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration supplyLimitB(true, 23.1, 25, 1.4);
        motorTurn.supplyCurrLimit = supplyLimitB;
        ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration statorLimitB(true, 12.1, 87.4, 0.4);
        motorTurn.statorCurrLimit = statorLimitB;
        motorTurn.motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;
        motorTurn.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Unsigned_0_to_360;
        motorTurn.integratedSensorOffsetDegrees = 42;
        motorTurn.initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToAbsolutePosition;
    }
};
#endif SWERVEMODULECONFIGS_H
