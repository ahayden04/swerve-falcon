#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <units/angular_velocity.h>
#include <units/time.h>
#include <units/velocity.h>
#include <wpi/numbers>

#include "Constants.h"
using namespace drivetrainConstants;

class swerveModule {
 public:
  swerveModule(const int module[]);

  class Config {
    public:
     enum class ConfigType {motorDrive, motorTurn, encoderTurn};
     void BuildSettings(const ConfigType& type, int encoderID = 0);
    
    ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorDriveConfig;
    ctre::phoenix::motorcontrol::can::TalonFXConfiguration motorTurnConfig;
    ctre::phoenix::sensors::CANCoderConfiguration encoderTurnConfig;

    private:
  };

  void ConfigModule(int encoderID);

  frc::SwerveModuleState GetState() const;

  void SetDesiredState(const frc::SwerveModuleState& state);

 private:
  Config m_moduleConfig;

  ctre::phoenix::sensors::WPI_CANCoder m_encoderTurn;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorDrive;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorTurn;
};
