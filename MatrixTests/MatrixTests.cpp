#include "../Matrix/Matrix.h"
#include "..//Matrix/MyExercise.h"
#include "..//Matrix/RandomGenerator.h"
#include "..//Matrix/IStreamGenerator.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace MatrixTests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		
		TEST_METHOD(TestChangeTheSignOfMinimumAbsElement)
		{
			Matrix<int> test1(2, 2);
			test1[0][0] = 4; test1[0][1] = -2;
			test1[1][0] = 7; test1[1][1] = 1;
			MyExercise solver1(test1);
			Matrix<int> result1 = solver1.task1();
			Assert::AreEqual(4, result1[0][0]);
			Assert::AreEqual(2, result1[0][1]);
			Assert::AreEqual(7, result1[1][0]);
			Assert::AreEqual(-1, result1[1][1]);
		}
	};
}

