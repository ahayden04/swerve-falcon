#include "swerveModule.h"
#include "hardwareSettings.h"

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>
#include <iostream>

swerveModule::swerveModule(const int module[])
    : m_motorDrive(module[0]), m_motorTurn(module[1]), m_encoderTurn(module[2]) {
    std::cout << "\nFor module #" << module[0] << ":\n";
    std::cout << module[0] << " - drive Falcon ID.\n";
    std::cout << module[1] << " - turn Falcon ID.\n";
    std::cout << module[2] << " - CANCoder for steering.\n\n";
    ConfigModule(ConfigType::motorDrive);
    ConfigModule(ConfigType::motorTurn, module[2]);
    ConfigModule(ConfigType::encoderTurn);
}

void swerveModule::ConfigModule(const ConfigType& type, int encoderID) {
    switch(type) {
        case ConfigType::motorDrive :
            m_motorDrive.ConfigFactoryDefault();
            m_motorDrive.ConfigAllSettings(m_setupTools.hardwareSettings.motorDrive);
            //Bevel gear on left side.
            m_motorDrive.SetInverted(TalonFXInvertType::Clockwise);
            break;
        case ConfigType::motorTurn :
            if (encoderID != 0) {
                m_motorTurn.ConfigFactoryDefault();
                m_setupTools.motorTurnSettings.remoteFilter0.remoteSensorDeviceID = encoderID;
                m_motorTurn.ConfigAllSettings(m_setupTools.hardwareSettings.motorTurn);
                m_motorTurn.SetInverted(TalonFXInvertType::CounterClockwise);
            }
            else {
                throw std::invalid_argument("encoderID param invalid in ConfigModule() call.");
            }
            break;
        case ConfigType::encoderTurn :
            m_encoderTurn.ConfigFactoryDefault();
            m_encoderTurn.ConfigAllSettings(m_setupTools.hardwareSettings.encoderTurn);
            break;
        default :
            std::cout << encoderID;
            throw std::invalid_argument(": Invalid swerveModule ConfigType");
    }
}
