/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 6
* Вариант № 26
* Задание:  Коэффициенты многочлена (𝑎_𝑛)*𝑥^𝑛 + (𝑎_(𝑛−1))*𝑥^(𝑛−1) + ⋯ + (𝑎_1)*𝑥 + 𝑎_0 размещены
  в массиве 𝑎0, 𝑎1 … 𝑎𝑛−1, 𝑎𝑛. Дано вещественное число 𝑥. Найти значение многочлена для
  данного 𝑥. Указание: ввод коэффициентов осуществлять с клавиатуры, начиная со старшего
  коэффициента; операцию возведения в степень не использовать.
***************************************************************************************/


#include <iostream>
#include <locale.h>


void solveTask();

void findPolynomial(const double* coeffs, int size, double x);
void findPolynomialGorner(const double* coeffs, int size, double x);

void test();


void main() {
	setlocale(LC_ALL, "Rus");

	// solveTask();
	test();
}


void solveTask() {
	double x;
	std::cout << "Введите значение x: ";
	std::cin >> x;

	int n;
	std::cout << "Введите n - количество элементов многочлена: ";
	std::cin >> n;

	double* coeffs = new double[n];
	std::cout << "Введите коэффициенты многочлена: ";
	for (int i = 0; i < n; i++) {
		std::cin >> coeffs[i];
	}

	findPolynomial(coeffs, n, x);
	findPolynomialGorner(coeffs, n, x);
}


void findPolynomial(const double* coeffs, int size, double x) {
	double polynomial, xpow;
	polynomial = coeffs[0];
	xpow = x;

	for (size_t i = 1; i < size; i++) {
		polynomial += coeffs[i] * xpow;
		xpow *= x;
	}

	std::cout << "Значение многочлена: " << polynomial;
	std::cout << std::endl;
}


void findPolynomialGorner(const double* coeffs, int size, double x) {
	double polynomial = coeffs[size - 1];

	for (int i = size - 2; i >= 0; i--) {
		polynomial = polynomial * x + coeffs[i];
	}

	std::cout << "Значение многочлена (схема Горнера): " << polynomial << std::endl;
}


void test() {
	double x[] = { 2, 0.25, 0.4 };
	double* coeffs[] = {
		new double[5]{7, 8, 2, 3, 4},
		new double[5]{2.5, 4, 3, 1.5, 7.4},
		new double[5]{1, 2, 3.1, 4.2, 5.3}
	};
	double polynomials[] = { 119, 3.73984375, 2.70048 };

	for (size_t i = 0; i < 3; i++) {
		findPolynomial(coeffs[i], 5, x[i]);
		findPolynomialGorner(coeffs[i], 5, x[i]);
		
		std::cout << "Ожидаемый результат: " << polynomials[i] << std::endl;
		std::cout << std::endl;
	}
}