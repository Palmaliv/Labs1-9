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
#include <vector>


void solveTask();
void findPolynomial(std::vector<double> coeffs, double x);
void test();


void main() {
	setlocale(LC_ALL, "Rus");

	// solveTask();
	test();
}


void solveTask() {
	double x;
	std::cout << "Введите x: ";
	std::cin >> x;

	int n;
	std::cout << "Введите n - количество элементов многочлена: ";
	std::cin >> n;

	std::vector<double> coeffs(10, 0);
	std::cout << "Введите коэффициенты:" << std::endl;
	for (size_t i = 0; i < n; i++) {
		std::cout << "a" << n - i - 1 << ": ";
		std::cin >> coeffs[n - i - 1];
	}

	findPolynomial(coeffs, x);
}


void findPolynomial(std::vector<double> coeffs, double x) {
	double polynomial, xpow;
	polynomial = coeffs[0];
	xpow = x;

	for (size_t i = 1; i < coeffs.size(); i++) {
		polynomial += coeffs[i] * xpow;
		xpow *= x;
	}

	std::cout << "Значение многочлена: " << polynomial;
	std::cout << std::endl;
}


void test() {
	std::vector<double> x = { 2, 0.25, 0.4 };
	std::vector<std::vector<double>> coeffs = {
		{7, 8, 2, 3, 4},
		{2.5, 4, 3, 1.5, 7.4},
		{1, 2, 3.1, 4.2, 5.3}};
	std::vector<double> polynomials = {119, 3.73984375, 2.70048};

	for (size_t i = 0; i < 3; i++) {
		findPolynomial(coeffs[i], x[i]);
		
		std::cout << "Ожидаемый результат: " << polynomials[i] << std::endl;
		std::cout << std::endl;
	}
}