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

void drawPascalTriangle(int n);
void drawLine(std::vector<int> line, int i, int m);
void test();


int main() {
	setlocale(LC_ALL, "Rus");

	/*int n;
	std::cout << "Введите количество строк треугольника Паскаля: ";
	std::cin >> n;

	drawPascalTriangle(n); */

	test();
}


void drawPascalTriangle(int n) {
	if (n <= 1)
		return drawLine({ 1 }, 1, 1);

	int m = n / 2 + n % 2; // Количество элементов в полустроке
	std::vector<int> line(m);
	line[0] = 1; // Инициализация первой строки

	drawLine(line, 1, m);

	for (size_t i = 1; i < n; i++) {
		// Проверка на симметричность/чётность строки
		if (i % 2) {
			for (size_t j = 0; j < m - 1; j++)
				line[j] += line[j + 1];
		}
		else {
			int temp1, temp2; // Переменные для хранение
			temp1 = line[0];
			line[0] *= 2;

			for (size_t j = 1; j < m; j++) {
				temp2 = line[j];
				line[j] = temp1 + line[j];
				temp1 = temp2;
			}
		}

		drawLine(line, i + 1, m);
	}
}

void drawLine(std::vector<int> line, int i, int m) {
	std::cout << std::setw(3) << i << " |";

	// Вывод левой части строки
	for (size_t j = 0; j < m; j++) {
		if (line[m - j - 1] != 0)
			std::cout << std::setw(6) << line[m - j - 1];
	}

	// Вывод правой части строки
	for (size_t j = (i % 2); j < m; j++) {
		if (line[j] != 0)
			std::cout << std::setw(6) << line[j];
	}

	std::cout << std::endl;
}


void test() {
	for (size_t i = 0; i < 20; i++) {
		drawPascalTriangle(i + 1);

		std::cout << std::endl;
	}
}