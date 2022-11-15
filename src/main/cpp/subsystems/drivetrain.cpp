#include "subsystems/drivetrain.h"

#include <frc/smartdashboard/SmartDashboard.h>

drivetrain::drivetrain() {
    m_navX.ZeroYaw();
}

void drivetrain::SwerveDrive(units::meters_per_second_t xSpeed,
                             units::meters_per_second_t ySpeed,
                             units::radians_per_second_t zRot,
                             bool fieldRelative) {
    auto moduleStates = m_kinematics.ToSwerveModuleStates(
        fieldRelative ? frc::ChassisSpeeds::FromFieldRelativeSpeeds(
                            xSpeed, ySpeed, zRot, m_navX.GetRotation2d())
                      : frc::ChassisSpeeds{xSpeed, ySpeed, zRot});
    m_kinematics.DesaturateWheelSpeeds(&moduleStates, drivetrainConstants::calculations::kModuleMaxSpeed);

    frc::SmartDashboard::PutNumber("xSpeed", xSpeed.value());
    frc::SmartDashboard::PutNumber("ySpeed", ySpeed.value());
    frc::SmartDashboard::PutNumber("zRotation", zRot.value());
    
    auto [frontRight, rearRight, frontLeft, rearLeft] = moduleStates;

    m_frontRight.SetDesiredState(frontRight);
    m_rearRight.SetDesiredState(rearRight);
    m_frontLeft.SetDesiredState(frontLeft);
    m_rearLeft.SetDesiredState(rearLeft);
}

void drivetrain::UpdateOdometry() {
    m_odometry.Update(m_navX.GetRotation2d(), m_frontRight.GetState(),
                      m_rearRight.GetState(), m_frontLeft.GetState(),
                      m_rearLeft.GetState());
}

void drivetrain::Periodic() {
    UpdateOdometry();

    // Test posting angle to Dashboard.
    //frc::SmartDashboard::PutNumber("new data", 0.087890625*remainder(m_frontLeft.GetSelectedSensorPosition(), 4096));
    frc::SmartDashboard::PutNumber("Front Right Angle", m_frontRight.DashboardInfo(swerveModule::DataType::kCurrentAngle));
    frc::SmartDashboard::PutNumber("Rear Right Angle", m_rearRight.DashboardInfo(swerveModule::DataType::kCurrentAngle));
    frc::SmartDashboard::PutNumber("Front Left Angle", m_frontLeft.DashboardInfo(swerveModule::DataType::kCurrentAngle));
    frc::SmartDashboard::PutNumber("Rear Left Angle", m_rearLeft.DashboardInfo(swerveModule::DataType::kCurrentAngle));

    frc::SmartDashboard::PutNumber("Front Right TARGET", m_frontRight.DashboardInfo(swerveModule::DataType::kTargetAngle));
    frc::SmartDashboard::PutNumber("Rear Right TARGET", m_rearRight.DashboardInfo(swerveModule::DataType::kTargetAngle));
    frc::SmartDashboard::PutNumber("Front Left TARGET", m_frontLeft.DashboardInfo(swerveModule::DataType::kTargetAngle));
    frc::SmartDashboard::PutNumber("Rear Left TARGET", m_rearLeft.DashboardInfo(swerveModule::DataType::kTargetAngle));
}

void drivetrain::SimulationPeriodic() {}
