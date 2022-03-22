#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/filter/SlewRateLimiter.h>

#include "subsystems/drivetrain.h"

/**
 * The command that controls our drivetrain.
 */
class Drive
    : public frc2::CommandHelper<frc2::CommandBase, Drive> {
 public:
  /**
   * Creates a new instance of Drive command.
   *
   * @param drivetrain The subsystem used by this command.
   * @param xSpeed The input for the x-axis used by this command.
   * @param ySpeed The input for the y-axis used by this command.
   * @param zRotation The input for the z-axis used by this command.
   */
  explicit Drive(drivetrain* drivetrain,
                               std::function<double()> xSpeed,
                               std::function<double()> ySpeed,
                               std::function<double()> zRotation);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  drivetrain* m_drivetrain;
  std::function<double()> m_xSpeed{0};
  std::function<double()> m_ySpeed{0};
  std::function<double()> m_zRotation{0};

  frc::SlewRateLimiter<units::scalar> m_xSpeedLimiter{3 / 1_s};
  frc::SlewRateLimiter<units::scalar> m_ySpeedLimiter{3 / 1_s};
  frc::SlewRateLimiter<units::scalar> m_zRotationLimiter{3 / 1_s};
};
