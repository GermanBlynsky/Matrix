#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	class MyExercise :public miit::algebra::ExerciseVirtual
	{
	public:

		MyExercise(int rows, int columns, Generator& generator) : ExerciseVirtual(rows, columns, generator) {}

		void task1() override;

		void task2() override;
	};
}