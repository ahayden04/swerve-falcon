#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/drivetrain.h"

/**
 * The command that controls our autonomous routine.
 */
class Auto
    : public frc2::CommandHelper<frc2::CommandBase, Auto> {
 public:
  /**
   * Creates a new instance of Auto command.
   *
   * @param drivetrain A subsystem used by this command.
   */
  explicit Auto(drivetrain* drivetrain);

 private:
  drivetrain* m_drivetrain;
};
