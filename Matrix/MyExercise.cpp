#include "MyExercise.h"
#include <iostream>

namespace miit::algebra {
     Matrix<int> MyExercise::task1()
    {

        Matrix<int> result(matrix);

        int rows = result.getRows();
        int cols = result.getColumns();
        for (int j = 0; j < cols; ++j) 
        {
            int minValue = std::abs(result[0][j]);
            std::vector<int> minIndices;

            for (int i = 0; i < rows; ++i) 
            {
                if (std::abs(result[i][j]) < minValue) 
                {
                    minValue = std::abs(result[i][j]);
                    minIndices.clear();
                    minIndices.push_back(i);
                }
                else if (std::abs(result[i][j]) == minValue) 
                {
                    minIndices.push_back(i);
                }
            }

            for (int i : minIndices)
            {
                result[i][j] *= -1;
            }
        }
        return result;
    }

    Matrix<int> MyExercise::task2()
    {
        std::vector<std::vector<int>> result_matrix;
        int rows = matrix.getRows();
        int cols = matrix.getColumns();
        int max_element = matrix[0][0];
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
         return Matrix<int>(result_matrix.size(), result_matrix[0].size(), result_matrix);
     }
}