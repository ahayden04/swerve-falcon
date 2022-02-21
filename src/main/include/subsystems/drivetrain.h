#pragma once

#include <AHRS.h>
#include <frc2/command/SubsystemBase.h>


#include "swerveModule.h"

#include "Constants.h"
using namespace swerveModules;

class drivetrain : public frc2::SubsystemBase {
 public:
  drivetrain();

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
  AHRS m_navX{frc::SPI::kMXP};

  swerveModule m_frontRight{moduleFrontRight};
  swerveModule m_rearRight{moduleRearRight};
  swerveModule m_frontLeft{moduleFrontLeft};
  swerveModule m_rearLeft{moduleRearLeft};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
