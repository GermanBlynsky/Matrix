#include <iostream>
#include "..\Matrix\Matrix.h"
#include "..\Matrix\MyExercise.h"

using namespace miit::algebra;
int main()
{
	Matrix<int> test(3, 5);
	RandomGenerator randomGenerator(-9, 9);
	IStreamGenerator istreamGenarator(std::cin);
	MyExercise task(3, 5, randomGenerator);
	task.Run();
	return 0;
}
