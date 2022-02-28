#pragma once

#include <AHRS.h>
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>
#include <units/length.h>

#include "swerveModule.h"
#include "Constants.h"

using namespace drivetrainConstants::swerveModules;

class drivetrain : public frc2::SubsystemBase {
 public:
  drivetrain();

  void SwerveDrive(units::meters_per_second_t xSpeed,
                   units::meters_per_second_t ySpeed,
                   units::radians_per_second_t zRot,
                   bool fieldRelative);

  void UpdateOdometry();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:

  //GET FINAL VALUES, TEMP 0_in
  frc::Translation2d m_locationFrontRight{+0_in, -0_in};
  frc::Translation2d m_locationRearRight{-0_in, -0_in};
  frc::Translation2d m_locationFrontLeft{+0_in, +0_in};
  frc::Translation2d m_locationRearLeft{-0_in, +0_in};

  swerveModule m_frontRight{moduleFrontRight};
  swerveModule m_rearRight{moduleRearRight};
  swerveModule m_frontLeft{moduleFrontLeft};
  swerveModule m_rearLeft{moduleRearLeft};

  AHRS m_navX{frc::SPI::kMXP};

  frc::SwerveDriveKinematics<4> m_kinematics{m_locationFrontRight,
                                             m_locationRearRight,
                                             m_locationFrontLeft,
                                             m_locationRearLeft};

  frc::SwerveDriveOdometry<4> m_odometry{m_kinematics, m_navX.GetRotation2d()};
};
