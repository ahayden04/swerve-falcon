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
  swerveModule(const double module[]);

  enum class ConfigType {motorDrive, motorTurn, encoderTurn};
  void ConfigModule(const ConfigType& type);

  frc::SwerveModuleState GetState();

  void SetDesiredState(const frc::SwerveModuleState& state);

  frc::SwerveModuleState CustomOptimize(const frc::SwerveModuleState& desiredState, const frc::Rotation2d& currentAngle);

  enum class DataType {kCurrentAngle, kCurrentVelocity, kTargetAngle};
  double DashboardInfo(const DataType& type);

 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorDrive;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_motorTurn;
  ctre::phoenix::sensors::WPI_CANCoder m_encoderTurn;
  const double m_encoderOffset;
  double m_targetAngle;

  hardwareSettings m_settings;
};

namespace units {
  UNIT_ADD(angle, native_unit, native_units, nu, unit<std::ratio<360, 2048>, units::degrees>) // 2048 clicks per rotation.
  UNIT_ADD(angular_velocity, native_units_per_decisecond, native_units_per_decisecond, nu_per_ds,
           compound_unit<native_units, inverse<deciseconds>>) // clicks per 100ms (standard FX output).
  //UNIT_ADD(angle, drive_gearing, drive_gearing, dratio, unit<std::ratio<27, 4>, units::degrees>)
  UNIT_ADD(length, wheel_circumference, wheel_circumferences, wcrc, unit<std::ratio<1194, 100>, units::inches>) // 3.8in diameter.
}
