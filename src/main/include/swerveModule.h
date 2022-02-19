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
  static constexpr int m_moduleFrontRight[3]{motorDriveFrontRight,
                                           motorTurnFrontRight,
                                           encoderTurnFrontRight};
  static constexpr int m_moduleRearRight[3]{motorDriveRearRight,
                                           motorTurnRearRight,
                                           encoderTurnRearRight};
  static constexpr int m_moduleFrontLeft[3]{motorDriveFrontLeft,
                                           motorTurnFrontLeft,
                                           encoderTurnFrontLeft};
  static constexpr int m_moduleRearLeft[3]{motorDriveRearLeft,
                                           motorTurnRearLeft,
                                           encoderTurnRearLeft};
  WPI_CANCoder m_encoderTurn;
  WPI_TalonFX m_motorDrive;
  WPI_TalonFX m_motorTurn;

  static constexpr auto moduleMaxAngularVelocity =
      wpi::numbers::pi * 1_rad_per_s;  // radians per second
  static constexpr auto moduleMaxAngularAcceleration =
      wpi::numbers::pi * 2_rad_per_s / 1_s;  // radians per second^2
};
