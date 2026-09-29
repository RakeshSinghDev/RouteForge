#include "constraints/Feasibility.hpp"
#include "utils/TravelTime.hpp"

bool FeasibilityChecker::checkCapacity(
    const Route &route,
    const Problem &problem) const
{
    int load = 0;

    for (int customerId : route.customers)
    {
        const Customer &customer =
            problem.customers[customerId - 1];

        load += customer.demand;
    }

    const Vehicle &vehicle =
        problem.vehicles[route.vehicleId - 1];

    return load <= vehicle.capacity;
}

bool FeasibilityChecker::checkTimeWindows(
    const Route &route,
    const Problem &problem,
    const DistanceMatrix &distances) const
{
    const Vehicle &vehicle =
        problem.vehicles[route.vehicleId - 1];

    double currentTime = 0.0;

    int previous = 0; // 0 = depot

    for (int customerId : route.customers)
    {
        const Customer &customer =
            problem.customers[customerId - 1];

        // Get distance from previous location
        // to the current customer.
        double distance =
            distances.get(previous, customerId);

        // Convert distance into travel time.
        double travelTime =
            calculateTravelTime(
                distance,
                vehicle.speed);

        // Move forward in time.
        currentTime += travelTime;

        // Arrived before the time window opens.
        // Wait until readyTime.
        if (currentTime < customer.readyTime)
        {
            currentTime = customer.readyTime;
        }

        // Arrived after the deadline.
        if (currentTime > customer.dueTime)
        {
            return false;
        }

        // Serve the customer.
        currentTime += customer.serviceTime;

        // Current customer becomes the previous location.
        previous = customerId;
    }

    return true;
}

bool FeasibilityChecker::isFeasible(
    const Route &route,
    const Problem &problem,
    const DistanceMatrix &distances) const
{
    if (!checkCapacity(route, problem))
    {
        return false;
    }

    if (!checkTimeWindows(route, problem, distances))
    {
        return false;
    }

    return true;
}