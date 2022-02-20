#include "swerveModule.h"

#include <ctre/Phoenix.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>

swerveModule::swerveModule(const int module[])
    : m_motorDrive(module[1]), m_motorTurn(module[2]), m_encoderTurn(module[3]) {
    ConfigModule(module[3]);
}

void swerveModule::Config::BuildSettings(const ConfigType& type, int encoderID) {
    if (type == ConfigType::motorDrive) {
        motorDriveConfig.supplyCurrLimit.enable = true;
    }
    if (type == ConfigType::motorTurn && encoderID != 0) {
        motorTurnConfig.supplyCurrLimit.enable = true;
        motorTurnConfig.remoteFilter0.remoteSensorDeviceID = encoderID;
        motorTurnConfig.remoteFilter0.remoteSensorSource = RemoteSensorSource::RemoteSensorSource_CANCoder;
    } else if (type == ConfigType::motorTurn && encoderID == 0) {
          throw std::invalid_argument("encoderID param missed in BuildSettings() call.");
      }
    if (type == ConfigType::encoderTurn) {
        encoderTurnConfig.absoluteSensorRange = Unsigned_0_to_360;
    }
    else {
        printf("Invalid SwerveModule ConfigType.");
    }
}

void swerveModule::ConfigModule(int encoderID)  {
    m_moduleConfig.BuildSettings(Config::ConfigType::motorDrive);
    m_moduleConfig.BuildSettings(Config::ConfigType::motorTurn, encoderID);
    m_moduleConfig.BuildSettings(Config::ConfigType::encoderTurn);

    m_motorDrive.ConfigFactoryDefault();
    m_motorTurn.ConfigFactoryDefault();
    m_encoderTurn.ConfigFactoryDefault();

    m_motorDrive.ConfigAllSettings(m_moduleConfig.motorDriveConfig);
    m_motorTurn.ConfigAllSettings(m_moduleConfig.motorTurnConfig);
    m_encoderTurn.ConfigAllSettings(m_moduleConfig.encoderTurnConfig);
}
