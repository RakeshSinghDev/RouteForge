#pragma once

#include <vector>

#include "model/Problem.hpp"
#include "model/Route.hpp"
#include "utils/DistanceMatrix.hpp"
#include "constraints/Feasibility.hpp"

class GreedySolver
{

public:
    std::vector<Route> solve(
        const Problem &problem,
        const DistanceMatrix &distances) const;
};