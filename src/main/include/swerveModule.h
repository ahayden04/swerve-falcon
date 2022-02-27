#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <units/angular_velocity.h>
#include <units/time.h>
#include <units/velocity.h>
#include <wpi/numbers>

#include "Constants.h"
#include "hardwareSettings.h"

class swerveModule {
 public:
  swerveModule(const int module[]);

  enum class ConfigType {motorDrive, motorTurn, encoderTurn};
  void ConfigModule(const ConfigType& type);

  frc::SwerveModuleState GetState() const;

  void SetDesiredState(const frc::SwerveModuleState& state);

 private:
  ctre::phoenix::sensors::WPI_CANCoder m_encoderTurn;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorDrive;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorTurn;

  hardwareSettings m_settings;
};
