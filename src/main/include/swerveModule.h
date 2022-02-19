#pragma once

#include <ctre/phoenix/sensors/CANCoder.h>
#include <ctre/Phoenix.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <units/angular_velocity.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/numbers>

class swerveModule {
 public:
  swerveModule(int motorDrive, int motorTurn, int encoderTurn);

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

  frc2::PIDController m_drivePIDController{1, 0, 0};
  frc::ProfiledPIDController<units::radians> m_turnPIDController{
    0, 0, 0,
    {moduleMaxAngularVelocity, moduleMaxAngularAcceleration}};
  
  frc::SimpleMotorFeedforward<units::meters> m_driveFeedforward{1_V, 3_V / 1_mps};
  frc::SimpleMotorFeedforward<units::radians> m_turnFeedforward{1_V, 0.5_V / 1_rad_per_s};
};
