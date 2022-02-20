#pragma once

#include <ctre/Phoenix.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <units/angular_velocity.h>
#include <units/time.h>
#include <units/velocity.h>
#include <wpi/numbers>

#include "Constants.h"
using namespace drivetrainConstants;

class swerveModule {
 public:
  swerveModule(int module[]);

  frc::SwerveModuleState GetState() const;

  void SetDesiredState(const frc::SwerveModuleState& state);

 private:
  WPI_CANCoder m_encoderTurn;
  WPI_TalonFX m_motorDrive;
  WPI_TalonFX m_motorTurn;

  static constexpr auto moduleMaxAngularVelocity =
      wpi::numbers::pi * 1_rad_per_s;  // radians per second
  static constexpr auto moduleMaxAngularAcceleration =
      wpi::numbers::pi * 2_rad_per_s / 1_s;  // radians per second^2
};
