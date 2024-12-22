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
		size_t rows;
		size_t columns;
	public:

		Matrix() = default; 

		/**
		* @brief Конструктор создания матрицы
		* @param rows количество строк
		* @param cols количество столбцов
		*/
		Matrix(size_t row, size_t column);

		/**
		* @brief Оператор разыменывания
		* @param index индекс строки
		*/
		std::vector<T>& operator[](size_t index);

		/**
		* @brief Оператор разыменывания
		* @param index индекс строки
		*/
		const std::vector<T>& operator[](size_t index) const;

		/**
		* @brief Преобразовает матрицу в строку
		* @return матрицу в виде строки
		*/
		std::string ToString() const;

		/**
		* @brief Гетер для строк
		* @return возвращает значения  поля строк (кол-во строк)
		*/
		size_t getRows();

		/**
		* @brief Гетер для столбцов
		* @return возвращает значения  поля столбцов (кол-во столбцов)
		*/
		size_t getColumns();

		void Fill(Generator& generator);
	};
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(size_t row, size_t column)
{
	rows = row;
	columns = column;
	this->matrix.assign(row, std::vector<T>(column));
}

template <typename T>
std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index)
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Введенно некорерктное значение индекса");
	}
	return matrix[index];
}

template <typename T>
const std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index) const
{
	return matrix[index];
}

template <typename T>
std::string miit::algebra::Matrix<T>::ToString() const
{
	std::stringstream buffer{};
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::getRows()
{
	return rows;
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::getColumns()
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