#pragma once

#include "Matrix.h" 

namespace miit::algebra {

    class ExerciseVirtual {
    protected:
        Matrix<int> matrix;
    public:

        /**
        * @brief Конструктор по умолчанию
        */
        ExerciseVirtual() = default;

        /**
        * @brief Конструктор с matrix
        */
        ExerciseVirtual(const Matrix<int>& matrix) : matrix(matrix) {}

        /**
        * @brief Деструктор по умолчанию
        */
        virtual ~ExerciseVirtual() = default; 

        /**
        * @brief Чисто виртуальная функция
        */
        virtual Matrix<int> task1() = 0;

        /**
        * @brief Чисто виртуальная функция
        */
        virtual Matrix<int> task2() = 0;
    };
}