/*
optimize(double currentAngle, double desiredState) {

    currentAngle % 360 = absAngle;
    if (absAngle < 0) {360 + absAngle  = absAngle};
    desiredState.angle - absAngle = difference;

    if (units::math::abs(difference) > 90) {
        -desiredState.speed = adjSpeed;
        if (difference > 0) {difference - 180 = difference;}
        else {difference + 180 = difference;}

        currentAngle + difference = adjAngle;
        return {adjSpeed, adjAngle};

    } else {
        currentAngle + difference = adjAngle;
        return {desiredState.speed, adjAngle};
    }
};
*/