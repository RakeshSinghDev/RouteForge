#pragma once

#include <unordered_map>
#include "model/Problem.hpp"
#include "model/Route.hpp"
#include "utils/DistanceMatrix.hpp"

class FeasibilityChecker
{

public:
    bool checkCapacity(
        const Route &route,
        const Problem &problem) const;

    bool checkTimeWindows(
        const Route &route,
        const Problem &problem,
        const DistanceMatrix &distances) const;

    bool isFeasible(
        const Route &route,
        const Problem &problem,
        const DistanceMatrix &distances) const;
};