#include "swerveModule.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/MathUtil.h>
#include <iostream>
#include <cmath>

using ControlMode = ctre::phoenix::motorcontrol::ControlMode;


swerveModule::swerveModule(const double module[])
    : m_motorDrive(module[0]), m_motorTurn(module[1]),
      m_encoderTurn(module[2]), m_encoderOffset(module[3]) {
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
            m_motorDrive.SelectProfileSlot(0, 0);
            break;
        case ConfigType::motorTurn :
            m_motorTurn.ConfigFactoryDefault();
            m_motorTurn.ConfigAllSettings(m_settings.motorTurn);
            /*m_motorTurn.ConfigRemoteFeedbackFilter(m_encoderTurn.GetDeviceNumber(),
                                                   ctre::phoenix::motorcontrol::
                                                   RemoteSensorSource::RemoteSensorSource_CANCoder, 0, 50);*/
            m_motorTurn.SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::CounterClockwise);
            m_motorTurn.SelectProfileSlot(0, 0);
            break;
        case ConfigType::encoderTurn :
           // m_motorTurn.ConfigFactoryDefault();
            m_encoderTurn.ConfigFactoryDefault();
            m_encoderTurn.ConfigAllSettings(m_settings.encoderTurn);
            m_encoderTurn.ConfigMagnetOffset(m_encoderOffset);
            break;
        default :
            throw std::invalid_argument("Invalid swerveModule ConfigType");
    }
}

frc::SwerveModuleState swerveModule::GetState() {
    units::native_units_per_decisecond_t motorSpeed{m_motorDrive.GetSelectedSensorVelocity(0)};
    units::meters_per_second_t wheelSpeed{
        (motorSpeed * drivetrainConstants::calculations::kWheelCircumference)
        / drivetrainConstants::calculations::kFinalDriveRatio};
           // frc::SmartDashboard::PutNumber("new data", 0.087890625*remainder(m_motorTurn.GetSelectedSensorPosition(), 4096));
    return {wheelSpeed,frc::Rotation2d(frc::AngleModulus(units::degree_t(/*m_encoderTurn.GetPosition()*/0.087890625*remainder(m_motorTurn.GetSelectedSensorPosition(), 4096))))};
}

void swerveModule::SetDesiredState(const frc::SwerveModuleState& referenceState) {
    const auto state = CustomOptimize(
        referenceState,units::degree_t(/*m_encoderTurn.GetPosition()*/0.087890625*remainder(m_motorTurn.GetSelectedSensorPosition(), 4096)));

    //This returns the position in +-Cancoder units counting forever, as opposed to absolulte -180 to +180 deg.
    //m_encoderTurn.GetPosition();
    const auto targetWheelSpeed{state.speed};
    m_targetAngle = state.angle.Degrees().value();
    const double turnOutput = m_targetAngle * (4096.0/360.0);

    units::native_units_per_decisecond_t targetMotorSpeed{
        (targetWheelSpeed * drivetrainConstants::calculations::kFinalDriveRatio)
        / drivetrainConstants::calculations::kWheelCircumference};
    
   m_motorDrive.Set(ControlMode::Velocity, targetMotorSpeed.value());
    //std::cout << targetMotorSpeed.value() << "-target_SPEED\n";
                frc::SmartDashboard::PutNumber("TMS", targetMotorSpeed.value());
                frc::SmartDashboard::PutNumber("AMS", m_motorDrive.GetSelectedSensorVelocity());
    m_motorTurn.Set(ControlMode::Velocity, turnOutput);
                frc::SmartDashboard::PutNumber("ARMS", m_motorTurn.GetSelectedSensorVelocity());
                frc::SmartDashboard::PutNumber("turnOutput", turnOutput);
  // m_motorTurn.SetSelectedSensorPosition(turnOutput);
    //std::cout << turnOutput << "u\n";
}

frc::SwerveModuleState swerveModule::CustomOptimize(const frc::SwerveModuleState& desiredState,
                                                    const frc::Rotation2d& currentAngle) {
    auto modulusAngle{frc::AngleModulus(currentAngle.Degrees())};
    auto optAngle = desiredState.angle;
    auto optSpeed = desiredState.speed;
    
    auto difference = optAngle.Degrees() - modulusAngle;
    frc::SmartDashboard::PutNumber("Difference", difference.value());

    if (difference >= 270_deg) {
        difference = difference - 360_deg;
    } else if (difference <= -270_deg) {
        difference = difference + 360_deg;
    }

    if (units::math::abs(difference) > 90_deg) {
        optSpeed = -desiredState.speed;
        if (difference > 0_deg) {
            difference = difference - 180_deg;
        } else {
            difference = difference + 180_deg;
        }
    }
    optAngle = currentAngle.Degrees() + difference;

    frc::SmartDashboard::PutNumber("Desired Angle", optAngle.Degrees().value());
    return {optSpeed, optAngle};
}

double swerveModule::DashboardInfo(const DataType& type) {
    switch(type) {
        case DataType::kCurrentAngle :
            //frc::SmartDashboard::PutNumber("Desired Angle", 0.087890625*remainder(m_motorTurn.GetSelectedSensorPosition(), 4096).value());
            frc::SmartDashboard::PutNumber("nue", m_motorTurn.GetSelectedSensorPosition());
            return {units::degree_t(frc::AngleModulus(units::degree_t(/*m_encoderTurn.GetPosition()*/0.087890625*remainder(m_motorTurn.GetSelectedSensorPosition(), 4096)))).value()};
        /*case DataType::kCurrentVelocity :
            units::native_units_per_decisecond_t motorSpeed{m_motorDrive.GetSelectedSensorVelocity(0)};
            units::meters_per_second_t wheelSpeed{
                (motorSpeed * drivetrainConstants::calculations::kWheelCircumference)
                / drivetrainConstants::calculations::kFinalDriveRatio};
            return {wheelSpeed.value()};*/
        case DataType::kTargetAngle :
            return {m_targetAngle};
        default :
            throw std::invalid_argument("Invalid DashboardInfo DataType");
    }
}