#include "swerveModule.h"

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>
#include <iostream>

swerveModule::swerveModule(const int module[])
    : m_motorDrive(module[0]), m_motorTurn(module[1]), m_encoderTurn(module[2]) {
    std::cout << "\nFor module #" << module[0] << ":\n";
    std::cout << module[0] << " - drive Falcon ID.\n";
    std::cout << module[1] << " - turn Falcon ID.\n";
    std::cout << module[2] << " - CANCoder for steering.\n\n";
    ConfigModule(module[2]);
}

void swerveModule::SetupTools::BuildSettings(const ConfigType& type, int encoderID) {
    if (type == ConfigType::motorDrive) {
        motorDriveSettings.supplyCurrLimit.enable = true;
    }
    else if (type == ConfigType::motorTurn) {
        if (encoderID != 0) {
            motorTurnSettings.supplyCurrLimit.enable = true;
            motorTurnSettings.remoteFilter0.remoteSensorDeviceID = encoderID;
            motorTurnSettings.remoteFilter0.remoteSensorSource = ctre::phoenix::motorcontrol::
                                                                 RemoteSensorSource::RemoteSensorSource_CANCoder;
        }
        else {
            throw std::invalid_argument("encoderID param missed in BuildSettings() call.");
        }
    }
    else if (type == ConfigType::encoderTurn) {
        encoderTurnSettings.absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Unsigned_0_to_360;
    }
    else {
        std::cout << encoderID;
        throw std::invalid_argument(": Invalid swerveModule ConfigType");
    }
}

void swerveModule::ConfigModule(const int encoderID)  {
    m_setupTools.BuildSettings(SetupTools::ConfigType::motorDrive, encoderID);
    m_setupTools.BuildSettings(SetupTools::ConfigType::motorTurn, encoderID);
    m_setupTools.BuildSettings(SetupTools::ConfigType::encoderTurn, encoderID);

    m_motorDrive.ConfigFactoryDefault();
    m_motorTurn.ConfigFactoryDefault();
    m_encoderTurn.ConfigFactoryDefault();

    m_motorDrive.ConfigAllSettings(m_setupTools.motorDriveSettings);
    m_motorTurn.ConfigAllSettings(m_setupTools.motorTurnSettings);
    m_encoderTurn.ConfigAllSettings(m_setupTools.encoderTurnSettings);
}
