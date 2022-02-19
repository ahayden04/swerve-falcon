#include "swerveModule.h"

swerveModule::swerveModule(int module[])
    : m_motorDrive(module[1]), m_motorTurn(module[2]), m_encoderTurn(module[3]) {}
