#pragma once

#include <units/angular_velocity.h>
#include <units/length.h>
#include <units/time.h>
#include <wpi/numbers>

/**
 * This header contains hold robot-wide numerical or boolean constants ONLY.
 * 
 * Place constants into subsystem/command -specific NAMESPACES within this
 * header, which can then be included (where they are needed).
 */

constexpr int PLACEHOLDER_INT = 0;
constexpr double PLACEHOLDER_DOUBLE = 0.0;

namespace controllerConstants {

    //USB port addresses on drivestation PC.
    constexpr int controllerMain = 0;
    constexpr int controllerAux = 1;

}

namespace drivetrainConstants {

    //CAN IDs
    constexpr int motorDriveFrontRight = 0;
    constexpr int motorDriveRearRight = 1;
    constexpr int motorDriveFrontLeft = 2;
    constexpr int motorDriveRearLeft = 3;

    constexpr int motorTurnFrontRight = 4;
    constexpr int motorTurnRearRight = 5;
    constexpr int motorTurnFrontLeft = 6;
    constexpr int motorTurnRearLeft = 7;

    constexpr int encoderTurnFrontRight = 8;
    constexpr int encoderTurnRearRight = 9;
    constexpr int encoderTurnFrontLeft = 10;
    constexpr int encoderTurnRearLeft = 11;

    namespace swerveModules {
        constexpr int moduleFrontRight[3]{motorDriveFrontRight,
                                                   motorTurnFrontRight,
                                                   encoderTurnFrontRight};
        constexpr int moduleRearRight[3]{motorDriveRearRight,
                                                  motorTurnRearRight,
                                                  encoderTurnRearRight};
        constexpr int moduleFrontLeft[3]{motorDriveFrontLeft,
                                                  motorTurnFrontLeft,
                                                  encoderTurnFrontLeft};
        constexpr int moduleRearLeft[3]{motorDriveRearLeft,
                                                 motorTurnRearLeft,
                                                 encoderTurnRearLeft};
    }

    namespace calculations {
        constexpr int driveEncoderResolution{2048}; //Falcon native units.
        constexpr double finalDriveRatio{6.75};
        constexpr units::length::inch_t wheelCircumference = {2 * wpi::numbers::pi * 3.8_in / 2};

        constexpr auto moduleMaxAngularVelocity{wpi::numbers::pi * 1_rad_per_s};  // radians per second
        constexpr auto moduleMaxAngularAcceleration{wpi::numbers::pi * 2_rad_per_s / 1_s};  // radians per second^2

        constexpr double motorMaxOutput = 0.5;
        constexpr double motorDeadband = 0.1;
    }
}
