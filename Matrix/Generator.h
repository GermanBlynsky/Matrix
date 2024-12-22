#pragma once

namespace miit::algebra
{
	/**
	* @brief
	*/
	class Generator
	{
	public:
		/**
		* @brief Вертуальный деструктор
		*/
		virtual ~Generator() = 0 {};

		/**
		* @brief Вертуальный метод генерации числа
		*/
		virtual int generate() = 0;
	};
}