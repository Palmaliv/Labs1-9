/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 2
* Вариант № 26
* Задание: Напечатать треугольник Паскаля, состоящий из n строк.
***************************************************************************************/


#include <iostream>
#include <locale.h>
#include <vector>
#include <iomanip>


int main() {
	setlocale(LC_ALL, "Rus");

	int n;
	std::cout << "Введите количество строк треугольника Паскаля: ";
	std::cin >> n;

	int m = n / 2; // Количество элементов в полустроке
	std::vector<int> line(m);
	line[0] = 1; // Инициализация первой строки

	int temp1, temp2; // Переменные для хранение
	int count = 1; // Количесвто элементов для расчёта
	for (size_t i = 1; i < n; i++) {

		// Вывод левой части строки
		for (size_t j = 0; j < m; j++) {
			if (line[m - j - 1] == 0)
				std::cout << "      ";
			else
				std::cout << std::setw(6) << line[m - j - 1];
		}

		// Вывод правой части строки
		for (size_t j = (i % 2); j < m; j++) {
			if (line[j] == 0)
				std::cout << "      ";
			else
				std::cout << std::setw(6) << line[j];
		}

		std::cout << std::endl;

		count += !(i % 2);

		// Проверка на симметричность/чётность строки
		if (i % 2) {
			for (size_t j = 0; j < count - 1; j++)
				line[j] += line[j + 1];
		}
		else {
			temp1 = line[0];
			line[0] *= 2;

			for (size_t j = 1; j < count; j++) {
				temp2 = line[j];
				line[j] = temp1 + line[j];
				temp1 = temp2;
			}
		}
	}
}