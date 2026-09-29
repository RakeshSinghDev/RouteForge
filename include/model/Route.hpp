#pragma once
#include <vector>
struct Route
{
    int vehicleId;

    std::vector<int> customers;

    double distance = 0.0;

    int load = 0;
};