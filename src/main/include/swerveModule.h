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

using namespace drivetrainConstants;

class swerveModule {
 public:
  swerveModule(const int module[]);

  class SetupTools {
    public:
     hardwareSettings settings;
    private:
  };

  enum class ConfigType {motorDrive, motorTurn, encoderTurn};
  void ConfigModule(const ConfigType& type);

  frc::SwerveModuleState GetState() const;

  void SetDesiredState(const frc::SwerveModuleState& state);

 private:
  SetupTools m_setupTools;

  ctre::phoenix::sensors::WPI_CANCoder m_encoderTurn;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorDrive;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorTurn;
};
