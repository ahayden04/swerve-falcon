#include "swerveModule.h"
#include "hardwareSettings.h"

#include <iostream>
using namespace drivetrainConstants::calculations;

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
            m_motorDrive.ConfigAllSettings(m_settings.motorDrive);
            //Bevel gear on left side.
            m_motorDrive.SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::Clockwise);
            break;
        case ConfigType::motorTurn :
            m_motorTurn.ConfigFactoryDefault();
            m_motorTurn.ConfigRemoteFeedbackFilter(m_encoderTurn.GetDeviceNumber(),
                                                   ctre::phoenix::motorcontrol::
                                                   RemoteSensorSource::RemoteSensorSource_CANCoder, 0, 0);
            m_motorTurn.ConfigAllSettings(m_settings.motorTurn);
            m_motorTurn.SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::CounterClockwise);
            break;
        case ConfigType::encoderTurn :
            m_encoderTurn.ConfigFactoryDefault();
            m_encoderTurn.ConfigAllSettings(m_settings.encoderTurn);
            break;
        default :
            throw std::invalid_argument("Invalid swerveModule ConfigType");
    }
}

frc::SwerveModuleState swerveModule::GetState() {
    units::revolutions_per_minute_t wheelSpeed{
        (m_motorDrive.GetSelectedSensorVelocity(0)) * // native units per 100ms.
        (1000 / 60) * // 1000ms per 60s.
        (1 / driveEncoderResolution) * // 1 motor rotation per 2048 native units. 
        (1 / finalDriveRatio)}; // 1 wheel rotation per 6.75 motor rotations.
    units::meters_per_second_t velocity{wheelSpeed * wheelCircumference / 360_deg}; // Wheel RPM times inches per rotation.
    return {velocity,frc::Rotation2d(units::degree_t(m_encoderTurn.GetAbsolutePosition()))};
}

void swerveModule::SetDesiredState(const frc::SwerveModuleState& referenceState) {
    const auto state = frc::SwerveModuleState::Optimize(
        referenceState,units::degree_t(m_encoderTurn.GetAbsolutePosition()));

        const auto targetVelocity{state.speed};
        const auto targetAngle{state.angle};

        //Set the velocity and angle below.
}