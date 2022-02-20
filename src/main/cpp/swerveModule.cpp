#include "swerveModule.h"

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>

swerveModule::swerveModule(const int module[])
    : m_motorDrive(module[1]), m_motorTurn(module[2]), m_encoderTurn(module[3]) {
    ConfigModule(module[3]);
}

void swerveModule::SetupTools::BuildSettings(const ConfigType& type, int encoderID) {
    if (type == ConfigType::motorDrive) {
        motorDriveSettings.supplyCurrLimit.enable = true;
    }
    if (type == ConfigType::motorTurn && encoderID != 0) {
        motorTurnSettings.supplyCurrLimit.enable = true;
        motorTurnSettings.remoteFilter0.remoteSensorDeviceID = encoderID;
        motorTurnSettings.remoteFilter0.remoteSensorSource = ctre::phoenix::motorcontrol::
                                                             RemoteSensorSource::RemoteSensorSource_CANCoder;
    } else if (type == ConfigType::motorTurn && encoderID == 0) {
          throw std::invalid_argument("encoderID param missed in BuildSettings() call.");
      }
    if (type == ConfigType::encoderTurn) {
        encoderTurnSettings.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Unsigned_0_to_360;
    }
    else {
        printf("Invalid SwerveModule ConfigType.");
    }
}

void swerveModule::ConfigModule(int encoderID)  {
    m_setupTools.BuildSettings(SetupTools::ConfigType::motorDrive);
    m_setupTools.BuildSettings(SetupTools::ConfigType::motorTurn, encoderID);
    m_setupTools.BuildSettings(SetupTools::ConfigType::encoderTurn);

    m_motorDrive.ConfigFactoryDefault();
    m_motorTurn.ConfigFactoryDefault();
    m_encoderTurn.ConfigFactoryDefault();

    m_motorDrive.ConfigAllSettings(m_setupTools.motorDriveSettings);
    m_motorTurn.ConfigAllSettings(m_setupTools.motorTurnSettings);
    m_encoderTurn.ConfigAllSettings(m_setupTools.encoderTurnSettings);
}
