#include "swerveModule.h"

#include <ctre/Phoenix.h>

swerveModule::swerveModule(int module[])
    : m_motorDrive(module[1]), m_motorTurn(module[2]), m_encoderTurn(module[3]) {
    ConfigModule();
}

void swerveModule::Config::BuildSettings(const ConfigType& type) {
    if (type == ConfigType::motorDrive) {
        motorDriveConfig.supplyCurrLimit.enable = true;
    }
    if (type == ConfigType::motorTurn) {
        motorTurnConfig.supplyCurrLimit.enable = true;
    }
    if (type == ConfigType::encoderTurn) {
        encoderTurnConfig.absoluteSensorRange = Unsigned_0_to_360;
    }
    else {
        printf("Invalid SwerveModule ConfigType.");
    }
}

void swerveModule::ConfigModule() {
    m_moduleConfig.BuildSettings(Config::ConfigType::motorDrive);
    m_moduleConfig.BuildSettings(Config::ConfigType::motorTurn);
    m_moduleConfig.BuildSettings(Config::ConfigType::encoderTurn);

    m_motorDrive.ConfigAllSettings(m_moduleConfig.motorDriveConfig);
    m_motorTurn.ConfigAllSettings(m_moduleConfig.motorTurnConfig);
    m_encoderTurn.ConfigAllSettings(m_moduleConfig.encoderTurnConfig);
}
