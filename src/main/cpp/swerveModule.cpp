#include "swerveModule.h"
#include "hardwareSettings.h"

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>
#include <iostream>

swerveModule::swerveModule(const int module[])
    : m_motorDrive(module[0]), m_motorTurn(module[1]), m_encoderTurn(module[2]) {
    std::cout << "\nFor module #" << module[0] << ":\n";
    std::cout << m_motorDrive.GetDeviceID() << " - drive Falcon ID.\n";
    std::cout << m_motorTurn.GetDeviceID() << " - turn Falcon ID.\n";
    std::cout << m_encoderTurn.GetDeviceNumber() << " - CANCoder for steering.\n\n";
    ConfigModule(ConfigType::motorDrive);
    ConfigModule(ConfigType::motorTurn);
    ConfigModule(ConfigType::encoderTurn);
}

void swerveModule::ConfigModule(const ConfigType& type) {
    switch(type) {
        case ConfigType::motorDrive :
            m_motorDrive.ConfigFactoryDefault();
            m_motorDrive.ConfigAllSettings(m_setupTools.settings.motorDrive);
            //Bevel gear on left side.
            m_motorDrive.SetInverted(TalonFXInvertType::Clockwise);
            break;
        case ConfigType::motorTurn :
            m_motorTurn.ConfigFactoryDefault();
            m_motorTurn.ConfigRemoteFeedbackFilter(m_encoderTurn.GetDeviceNumber(),
                                                   RemoteSensorSource::RemoteSensorSource_CANCoder, 0, 0);
            m_motorTurn.ConfigAllSettings(m_setupTools.settings.motorTurn);
            m_motorTurn.SetInverted(TalonFXInvertType::CounterClockwise);
            break;
        case ConfigType::encoderTurn :
            m_encoderTurn.ConfigFactoryDefault();
            m_encoderTurn.ConfigAllSettings(m_setupTools.settings.encoderTurn);
            break;
        default :
            throw std::invalid_argument("Invalid swerveModule ConfigType");
    }
}
