#pragma once

inline double calculateTravelTime(
    double distance,
    double speed)
{
    // distance = km
    // speed = km/hour
    // result = minutes

    return (distance / speed) * 60.0;
}