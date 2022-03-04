#include "commands/Drive.h"
#include "Constants.h"

using namespace drivetrainConstants;

Drive::Drive(drivetrain* drivetrain,
             std::function<double()> xSpeed,
             std::function<double()> ySpeed,
             std::function<double()> zRotation)
    : m_drivetrain{drivetrain},
      m_xSpeed(std::move(xSpeed)),
      m_ySpeed(std::move(ySpeed)),
      m_zRotation(std::move(zRotation)) {
  SetName("Drive");
  AddRequirements({m_drivetrain});
}

void Drive::Initialize() { printf("Drive initialized.\n"); }

void Drive::Execute() {
  m_drivetrain->SwerveDrive(-m_ySpeed()*calculations::kChassisMaxSpeed,
                            -m_xSpeed()*calculations::kChassisMaxSpeed,
                            -m_zRotation()*calculations::moduleMaxAngularVelocity, true);
}

void Drive::End(bool interrupted) { printf("**Drive has been interrupted!**\n"); }

bool Drive::IsFinished() { return false; }