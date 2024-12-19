#pragma once

#include "ExerciseVirtual.h" // Включаем заголовочный файл базового класса
#include <iostream>


namespace miit::algebra {
    class MyExercise : public ExerciseVirtual {
    public:
       
        /**
        * @brief Конструктор с matrix
        */
        MyExercise(const Matrix<int>& matrix) : ExerciseVirtual(matrix) {}


        ~MyExercise() override = default;

        /**
        * @brief Функция, выполняющая первое задание - Заменить минимальный по модулю элемент каждого столбца на противоположный.
        */
        Matrix<int> task1() override;

        /**
        * @brief Функция, выполняющая второе задание - Удалить все строки, содержащие максимальные элементы.
        */
        Matrix<int> task2() override;

    };
}