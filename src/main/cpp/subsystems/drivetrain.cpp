#include "subsystems/drivetrain.h"

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
    //ADD FINAL MAX SPEED, TEMP 0_mps
    m_kinematics.DesaturateWheelSpeeds(&moduleStates, 0_mps);

    auto [frontRight, rearRight, frontLeft, rearLeft] = moduleStates;

    m_frontRight.SetDesiredState(frontRight);
    m_rearRight.SetDesiredState(rearRight);
    m_frontLeft.SetDesiredState(frontLeft);
    m_rearLeft.SetDesiredState(rearLeft);
}

void drivetrain::Periodic() {}

void drivetrain::SimulationPeriodic() {}
