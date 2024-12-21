#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	class MyExercise :public miit::algebra::ExerciseVirtual
	{
	public:

		MyExercise(size_t rows, size_t columns, Generator& generator) : ExerciseVirtual(rows, columns, generator) {}

		void task1() override;

		void task2() override;
	};
}