#include <iostream>

#include "model/Problem.hpp"
#include "utils/DistanceMatrix.hpp"

int main()
{

    Problem problem;

    problem.depotX = 0.0;
    problem.depotY = 0.0;

    problem.customers.push_back({1,
                                 3.0,
                                 4.0,
                                 2,
                                 8,
                                 12,
                                 10});

    problem.customers.push_back({2,
                                 6.0,
                                 8.0,
                                 3,
                                 9,
                                 14,
                                 10});

    DistanceMatrix distances(problem);

    std::cout << "Depot -> C1: "
              << distances.get(0, 1)
              << '\n';

    std::cout << "C1 -> C2: "
              << distances.get(1, 2)
              << '\n';

    std::cout << "C2 -> Depot: "
              << distances.get(2, 0)
              << '\n';

    return 0;
}