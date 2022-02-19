#include "swerveModule.h"

#include <frc/geometry/Rotation2d.h>
#include <wpi/numbers>

swerveModule::swerveModule(const int motorDrive, const int motorTurn, const int encoderTurn)
    : m_motorDrive(motorDrive), m_motorTurn(motorTurn), m_encoderTurn(encoderTurn) {}