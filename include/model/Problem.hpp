#pragma once
#include <vector>
#include "Customer.hpp"
#include "Vehicle.hpp"
struct Problem
{
    std::vector<Customer> customers;
    std::vector<Vehicle> vehicles;

    int depotX;
    int depotY;
};