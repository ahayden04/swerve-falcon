#pragma once

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

    static constexpr int m_moduleFrontRight[3]{motorDriveFrontRight,
                                               motorTurnFrontRight,
                                               encoderTurnFrontRight};
    static constexpr int m_moduleRearRight[3]{motorDriveRearRight,
                                              motorTurnRearRight,
                                              encoderTurnRearRight};
    static constexpr int m_moduleFrontLeft[3]{motorDriveFrontLeft,
                                              motorTurnFrontLeft,
                                              encoderTurnFrontLeft};
    static constexpr int m_moduleRearLeft[3]{motorDriveRearLeft,
                                             motorTurnRearLeft,
                                             encoderTurnRearLeft};

    constexpr double wheelRadius = PLACEHOLDER_DOUBLE;
    constexpr int driveEncoderResolution = 2048; //Falcon, possibly unnecessary, API might have it.
    constexpr int steerEncoderResolution = 4096; //CANCoder; possibly unnecessary, just use degrees.

    //constexpr auto moduleMaxAngularVelocity; Cannot figure out how to import WPI numbers.
    //constexpr auto moduleMaxAngularAcceleration; Cannot figure out how to import WPI numbers.

    constexpr double motorMaxOutput = 0.5;
    constexpr double motorDeadband = 0.1;

}
