#include "MyExercise.h"
using namespace miit::algebra;

void miit::algebra::MyExercise::task1()
{

    for (int j = 0; j < matrix.getColumns(); ++j)
    {
        int minValue = std::abs(matrix[0][j]);
        std::vector<int> minIndices;

        for (int i = 0; i < matrix.getRows(); ++i)
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

        for (int i : minIndices)
        {
            matrix[i][j] *= -1;
        }
    }
}

void miit::algebra::MyExercise::task2()
{
    std::vector<std::vector<int>> result_matrix;
    size_t rows = matrix.getRows();
    size_t cols = matrix.getColumns();
    int max_element = this->matrix[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] > max_element)
            {
                max_element = matrix[i][j];
            }
        }
    }
    std::vector<int> rows_to_keep;
    for (int i = 0; i < rows; ++i)
    {
        bool has_max = false;
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == max_element)
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

    for (int i : rows_to_keep)
    {
        result_matrix.push_back(matrix[i]);
    }

      matrix = Matrix<int>(result_matrix.size(), result_matrix[0].size(), result_matrix);

}