#include <iostream>
#include "../Matrix/Matrix.h"
#include "../Matrix/MyExercise.h"

using namespace miit::algebra;

int main() {
    Matrix<int> test(3, 5);
    test.RandomIntFill(-10, 10);
    std::cout << std::endl << test << std::endl;
    MyExercise solver(test);
   std::cout << std::endl << solver.task1() << std::endl;
    std::cout << solver.task2() << std::endl;
    return 0;
}