#pragma once

#include <vector>
#include "model/Problem.hpp"
#include "utils/Distance.hpp"

class DistanceMatrix {
private:
    std::vector<std::vector<double>> matrix;

public:
    DistanceMatrix(const Problem& problem) {

        int n = problem.customers.size();

        matrix.resize(n + 1, std::vector<double>(n + 1));

        // Customer-to-customer distances
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                matrix[i + 1][j + 1] =
                    calculateDistance(
                        problem.customers[i].x,
                        problem.customers[i].y,
                        problem.customers[j].x,
                        problem.customers[j].y
                    );
            }
        }

        // Depot-to-customer and customer-to-depot
        for (int i = 0; i < n; i++) {

            double distance = calculateDistance(
                problem.depotX,
                problem.depotY,
                problem.customers[i].x,
                problem.customers[i].y
            );

            matrix[0][i + 1] = distance;
            matrix[i + 1][0] = distance;
        }

        // Depot to depot
        matrix[0][0] = 0.0;
    }

    double get(int from, int to) const {
        return matrix[from][to];
    }
};