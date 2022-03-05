#pragma once

#include <units/angular_velocity.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <wpi/numbers>

/**
 * This header contains hold robot-wide numerical or boolean constants ONLY.
 * 
 * Place constants into subsystem/command -specific NAMESPACES within this
 * header, which can then be included (where they are needed).
 */

namespace controllerConstants {
    //USB port addresses on drivestation PC.
    constexpr int kControllerMainID = 0;
    constexpr int kControllerAuxID = 1;
}

namespace drivetrainConstants {
    //CAN IDs
    constexpr int kMotorDriveFrontRightID = 0;
    constexpr int kMotorDriveRearRightID = 1;
    constexpr int kMotorDriveFrontLeftID = 2;
    constexpr int kMotorDriveRearLeftID = 3;

    constexpr int kMotorTurnFrontRightID = 4;
    constexpr int kMotorTurnRearRightID = 5;
    constexpr int kMotorTurnFrontLeftID = 6;
    constexpr int kMotorTurnRearLeftID = 7;

    constexpr int kEncoderTurnFrontRightID = 8;
    constexpr int kEncoderTurnRearRightID = 9;
    constexpr int kEncoderTurnFrontLeftID = 10;
    constexpr int kEncoderTurnRearLeftID = 11;

    namespace swerveModules {
        constexpr int kModuleFrontRight[3]{kMotorDriveFrontRightID,
                                                   kMotorTurnFrontRightID,
                                                   kEncoderTurnFrontRightID};
        constexpr int kModuleRearRight[3]{kMotorDriveRearRightID,
                                                  kMotorTurnRearRightID,
                                                  kEncoderTurnRearRightID};
        constexpr int kModuleFrontLeft[3]{kMotorDriveFrontLeftID,
                                                  kMotorTurnFrontLeftID,
                                                  kEncoderTurnFrontLeftID};
        constexpr int kModuleRearLeft[3]{kMotorDriveRearLeftID,
                                                 kMotorTurnRearLeftID,
                                                 kEncoderTurnRearLeftID};
    }

    namespace calculations {
        constexpr auto kFinalDriveRatio{6.75 * 360_deg};
        constexpr units::length::inch_t kWheelCircumference = {2 * wpi::numbers::pi * 3.8_in / 2};

        constexpr auto kModuleMaxSpeed{16.3_fps};
        constexpr auto kChassisMaxSpeed{16.3_fps};

        constexpr auto kModuleMaxAngularVelocity{wpi::numbers::pi * 1_rad_per_s};  // radians per second
        constexpr auto kModuleMaxAngularAcceleration{wpi::numbers::pi * 2_rad_per_s / 1_s};  // radians per second^2

        constexpr double kMotorMaxOutput = 0.5;
        constexpr double kMotorDeadband = 0.1;
    }
}
