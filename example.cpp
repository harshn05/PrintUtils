#include "PrintUtils.hpp"
#include <vector>
#include <iostream>

/**
 * The main function is the entry point of the program.
 * It demonstrates the usage of the PrintUtils library to print vectors and matrices.
 */
int main()
{

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Vector v = \n"
              << v << std::endl;
    std::vector<std::vector<int>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Matrix vv = \n"
              << vv << std::endl;
    PrintUtils::CSV<int>::TwoDVectorAsTwoDVector(vv, "matrix.csv");
    return 0;
}