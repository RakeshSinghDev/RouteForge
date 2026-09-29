#include "algorithms/Greedy.hpp"

std::vector<Route> GreedySolver::solve(
    const Problem &problem,
    const DistanceMatrix &distances) const
{

    std::vector<Route> routes;

    // Create one route for every vehicle.
    for (const Vehicle &vehicle : problem.vehicles)
    {

        Route route;

        route.vehicleId = vehicle.id;

        routes.push_back(route);
    }

    FeasibilityChecker checker;

    // Try to assign every customer.
    for (const Customer &customer : problem.customers)
    {

        bool assigned = false;

        // Try every vehicle.
        for (Route &route : routes)
        {

            // Temporarily add the customer.
            route.customers.push_back(customer.id);

            // Check whether this route is still valid.
            if (checker.isFeasible(
                    route,
                    problem,
                    distances))
            {

                assigned = true;

                break;
            }

            // Customer didn't fit.
            // Remove the temporary insertion.
            route.customers.pop_back();
        }

        if (!assigned)
        {

            // No vehicle could accommodate this customer.
            // For now, we simply report the problem.
            return {};
        }
    }

    return routes;
}