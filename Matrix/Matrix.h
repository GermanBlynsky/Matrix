#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
namespace miit::algebra
{
	template<typename T> class Matrix;

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<T>& matr);

	/**
	* @brief Класс Matrix - двумерный массив
	*/
	template<typename T>
	class Matrix
	{
	private:
		std::vector<std::vector<T>> matrix;
		int rows;
		int columns;
	public:

		Matrix() = default; 

		/**
		* @brief Конструктор создания матрицы
		* @param rows количество строк
		* @param cols количество столбцов
		*/
		Matrix(int row, int column);

		/**
		* @brief Конструктор создания матрицы по параметрам rows, columns, matrix
		* @param rows количество строк
		* @param cols количество столбцов
		* @param matrix матрица
		*/
		Matrix(int rows, int columns, const std::vector<std::vector<T>>& matrix);

		/**
		* @brief Конструктор копирования
		* @param other матрица, которая будет скопирована
		*/
		Matrix(const Matrix& other);

		/**
		* @brief Конструктор перемещения
		* @param other матрица, данные которой будут перемещены
		*/
		Matrix(Matrix&& other)noexcept;

		/**
		* @brief Оператор присваивания копированием
		* @param other матрица, данные  которой будут скопированы
		*/
		Matrix& operator =(const Matrix& other);

		/**
		* @brief Оператор присваивания копированием
		* @param other матрица, данные  которой будут перемещены
		*/
		Matrix& operator =(Matrix&& other) noexcept;

		/**
		* @brief Оператор разыменывания
		* @param index индекс строки
		*/
		std::vector<T>& operator[](int index);

		/**
		* @brief Оператор разыменывания
		* @param index индекс строки
		*/
		const std::vector<T>& operator[](int index) const;

		/**
		* @brief Преобразовает матрицу в строку
		* @return матрицу в виде строки
		*/
		std::string ToString() const;

		/**
		* @brief Гетер для строк
		* @return возвращает значения  поля строк (кол-во строк)
		*/
		int getRows();

		/**
		* @brief Гетер для столбцов
		* @return возвращает значения  поля столбцов (кол-во столбцов)
		*/
		int getColumns();

		void Fill(Generator& generator);
	};
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(int row, int column)
{
	if (row < 0 || column < 0)
	{
		throw std::out_of_range("Выход за границу");
	}
	rows = row;
	columns = column;
	this->matrix.assign(row, std::vector<T>(column));
}


template <typename T>
miit::algebra::Matrix<T>::Matrix(int rows, int columns, const std::vector<std::vector<T>>& matrix) : rows{ rows }, columns{ columns }, matrix{ matrix }
{

}

template <typename T>
miit::algebra::Matrix<T>::Matrix(const Matrix& other) :matrix{ other.matrix }, rows{ other.rows }, columns{ other.columns } {}

template <typename T>
miit::algebra::Matrix<T>::Matrix(Matrix&& other)noexcept :matrix{ std::move(other.matrix) }, rows{ std::move(other.rows) }, columns{ std::move(other.columns) } {}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->matrix = other.matrix;
		this->rows = other.rows;
		this->columns = other.columns;
	}
	return *this;
}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		this->matrix = std::move(other.matrix);
		this->rows = std::move(other.rows);
		this->columns = std::move(other.columns);
	}
	return *this;
}
template <typename T>
std::vector<T>& miit::algebra::Matrix<T>::operator[](int index)
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Введенно некорерктное значение индекса");
	}
	return matrix[index];
}

template <typename T>
const std::vector<T>& miit::algebra::Matrix<T>::operator[](int index) const
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Введенно некорерктное значение индекса");
	}
	return matrix[index];
}

template <typename T>
std::string miit::algebra::Matrix<T>::ToString() const
{
	std::stringstream buffer{};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

template<typename T>
inline int miit::algebra::Matrix<T>::getRows()
{
	return rows;
}

template<typename T>
inline int miit::algebra::Matrix<T>::getColumns()
{
	return columns;
}

template <typename T>
std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix<T>& matr)
{
	os << matr.ToString();
	return os;
}

template<typename T>
inline void miit::algebra::Matrix<T>::Fill(Generator& generator)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			matrix[i][j] = generator.generate();
		}
	}
}