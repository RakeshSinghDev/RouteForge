#pragma once

#include "model/Route.hpp"
#include "utils/DistanceMatrix.hpp"

inline double calculateRouteDistance(
    const Route &route,
    const DistanceMatrix &distances)
{
    double totalDistance = 0.0;

    int previous = 0; // depot

    for (int customerId : route.customers)
    {

        totalDistance += distances.get(
            previous,
            customerId);

        previous = customerId;
    }

    // Last customer → depot
    totalDistance += distances.get(
        previous,
        0);

    return totalDistance;
}