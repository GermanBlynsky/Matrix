#include "MyExercise.h"
using namespace miit::algebra;

void miit::algebra::MyExercise::task1()
{

    for (size_t j = 0; j < matrix.getColumns(); ++j)
    {
        int minValue = std::abs(matrix[0][j]);
        std::vector<size_t> minIndices;

        for (size_t i = 0; i < matrix.getRows(); ++i)
        {
            if (std::abs(matrix[i][j]) < minValue)
            {
                minValue = std::abs(matrix[i][j]);
                minIndices.clear();
                minIndices.push_back(i);
            }
            else if (std::abs(matrix[i][j]) == minValue)
            {
                minIndices.push_back(i);
            }
        }

        for (size_t i : minIndices)
        {
            matrix[i][j] *= -1;
        }
    }
}

void miit::algebra::MyExercise::task2()
{
    std::vector<std::vector<int>> result_matrix;
    size_t rows = this->matrix.getRows();
    size_t cols = this->matrix.getColumns();
    int max_element = std::numeric_limits<int>::min();

    for (size_t i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (this->matrix[i][j] > max_element)
            {
                max_element = matrix[i][j];
            }
        }
    }
    std::vector<size_t> rows_to_keep;
    for (size_t i = 0; i < rows; ++i)
    {
        bool has_max = false;
        for (size_t j = 0; j < cols; ++j)
        {
            if (this->matrix[i][j] == max_element)
            {
                has_max = true;
                break;
            }
        }
        if (!has_max)
        {
            rows_to_keep.push_back(i);
        }
    }
    for (size_t i : rows_to_keep)
    {
        result_matrix.push_back(matrix[i]);
    }

    if (result_matrix.empty())
    {
        this->matrix = Matrix<int>(0, 0); 
    }
    else
    {
        Matrix<int> newMatrix(result_matrix.size(), result_matrix[0].size()); 

        for (size_t i = 0; i < result_matrix.size(); ++i)
        {
            for (size_t j = 0; j < result_matrix[0].size(); ++j)
            {
                newMatrix[i][j] = result_matrix[i][j]; 
            }
        }
        this->matrix = newMatrix;
    }
}