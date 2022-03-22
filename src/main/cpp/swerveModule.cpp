#include "swerveModule.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/MathUtil.h>
#include <iostream>

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
            break;
        case ConfigType::motorTurn :
            m_motorTurn.ConfigFactoryDefault();
            m_motorTurn.ConfigAllSettings(m_settings.motorTurn);
            m_motorTurn.ConfigRemoteFeedbackFilter(m_encoderTurn.GetDeviceNumber(),
                                                   ctre::phoenix::motorcontrol::
                                                   RemoteSensorSource::RemoteSensorSource_CANCoder, 0, 50);
            m_motorTurn.SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::CounterClockwise);
            m_motorTurn.SelectProfileSlot(0, 0);
            break;
        case ConfigType::encoderTurn :
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
    return {wheelSpeed,frc::Rotation2d(frc::AngleModulus(units::degree_t(m_encoderTurn.GetPosition())))};
}

void swerveModule::SetDesiredState(const frc::SwerveModuleState& referenceState) {
    const auto state = CustomOptimize(
        referenceState,units::degree_t(m_encoderTurn.GetPosition()));
    //This returns the position in +-Cancoder units counting forever, as opposed to absolulte -180 to +180 deg.

    const auto targetWheelSpeed{state.speed};
    const auto targetAngle{(state.angle.Degrees().value())};
    const double turnOutput = targetAngle * (4096.0/360.0);
        

    units::native_units_per_decisecond_t targetMotorSpeed{
        (targetWheelSpeed * drivetrainConstants::calculations::kFinalDriveRatio)
        / drivetrainConstants::calculations::kWheelCircumference};
    //m_motorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, targetMotorSpeed.value());
    //std::cout << targetMotorSpeed.value() << "-target_SPEED\n";

    //This doesn't work for some reason. I suspect .value() doesn't produce a double by default.
    //m_motorTurn.Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, state.angle.Degrees().value());
        
    //This right here produces output.
    m_motorTurn.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::Position, turnOutput);
    std::cout << targetAngle << "-target_Deg | " << turnOutput << "u\n";
}

frc::SwerveModuleState swerveModule::CustomOptimize(const frc::SwerveModuleState& desiredState,
                                                    const frc::Rotation2d& currentAngle) {
    auto absAngle{units::math::fmod(currentAngle.Degrees(), 360_deg)};
    auto optAngle = desiredState.angle;
    auto optSpeed = desiredState.speed;

    if (absAngle < 0_deg) {absAngle = absAngle + 360_deg;}
    if (units::math::abs(absAngle) > 270_deg) {
        optAngle = desiredState.angle.Degrees() + 360_deg;
    }
    auto difference = optAngle.Degrees() - absAngle;

    if (units::math::abs(difference) > 90_deg) {
        optSpeed = -desiredState.speed;
        if (difference > 0_deg) {
            difference = difference - 180_deg;
        } else {
            difference = difference + 180_deg;
        }
    }
    optAngle = currentAngle.Degrees() + difference;
    return {optSpeed, optAngle};
}

double swerveModule::DashboardInfo(const DataType& type) {
    switch(type) {
        case DataType::kCurrentAngle :
            return {units::degree_t(frc::AngleModulus(units::degree_t(m_encoderTurn.GetPosition()))).value()};
        /*case DataType::kCurrentVelocity :
            units::native_units_per_decisecond_t motorSpeed{m_motorDrive.GetSelectedSensorVelocity(0)};
            units::meters_per_second_t wheelSpeed{
                (motorSpeed * drivetrainConstants::calculations::kWheelCircumference)
                / drivetrainConstants::calculations::kFinalDriveRatio};
            return {wheelSpeed.value()};*/
        default :
            throw std::invalid_argument("Invalid DashboardInfo DataType");
    }
}