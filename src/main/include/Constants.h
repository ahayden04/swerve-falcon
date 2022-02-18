#pragma once

/**
 * This header contains hold robot-wide numerical or boolean constants ONLY.
 * 
 * Place constants into subsystem/command -specific NAMESPACES within this
 * header, which can then be included (where they are needed).
 */

constexpr int PLACEHOLDER_INT = 0;

namespace controllerConstants {

    //USB port addresses on drivestation PC.
    constexpr int controllerMain = 0;
    constexpr int controllerAux = 1;

}

namespace drivetrainConstants {

    //CAN IDs
    constexpr int motorRearRight = 0;
    constexpr int motorFrontRight = 1;
    constexpr int motorRearLeft = 2;
    constexpr int motorFrontLeft = 3;

    constexpr double motorMaxOutput = 0.5;
    constexpr double motorDeadband = 0.1;

}
