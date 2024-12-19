#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
    * @brief Класс RandomGenerator, реализующий интерфейс Generator для генерации случайных целых чисел.
    */
    class RandomGenerator : public Generator
    {
    private:

        std::uniform_int_distribution<int> distribution;

        /**
        * @brief Объект генератора случайных чисел.
        */
        std::mt19937 generator;

    public:
        /**
        * @brief Конструктор класса RandomGenerator
        * @param min Минимальное значение генерации
        * @param max Максимальное значение генерации
        */
        RandomGenerator(const int min, const int max);

        /**
        * @brief Метод для генерации случайного целого числа
        * @return Сгенерированное случайное целое число
        */
        int generate() override;
    };
}