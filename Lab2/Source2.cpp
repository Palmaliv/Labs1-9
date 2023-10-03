/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 2
* Вариант № 26
* Задание: Даны вещественные a1, b1, c1, a2, b2, c2. Решить систему уравнений
	a1x + b1y = c1
	a2x + b2y = c2
***************************************************************************************/


#include <iostream>
#include <locale.h>
#include <iomanip>
#include <map>


void solveEquationSystem(float a1, float b1, float c1, float a2, float b2, float c2);
void test();


int main() {
	setlocale(LC_ALL, "Rus");
	
	/*td::map<std::string, float> coefficients{
		{"a1", 0}, {"b1", 0}, {"c1", 0},
		{"a2", 0}, {"b2", 0}, {"c2", 0}
	};

	for (auto& elem : coefficients) {
		std::cout << "Введите " + elem.first << " : ";
		std::cin >> elem.second;
	}

	std::cout << "| " << coefficients["a1"] << "x + " << coefficients["b1"] << "y = " << coefficients["c1"] << '\n'
		  << "| " << coefficients["a2"] << "x + " << coefficients["b2"] << "y = " << coefficients["c2"] << std::endl;

	solveEquationSystem(coefficients["a1"], coefficients["b1"], coefficients["c1"],
			    coefficients["a2"], coefficients["b2"], coefficients["c2"]);*/
	
	test();
}


void solveEquationSystem(float a1, float b1, float c1, float a2, float b2, float c2) {
	bool flagA = a1 == 0 && a2 == 0;
	bool flagB = b1 == 0 && b2 == 0;
	bool flagAB = (a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0);
	bool flagABC = (a1 == a2) && (b1 == b2) && (c1 == c2);

	if (!(flagA || flagB || flagAB || flagABC)) {
		float x, y;
		x = (b1 * c2 - b2 * c1) / (b1 * a2 - b2 * a1);
		y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
		std::cout << "x = " << x << " y = " << y << std::endl;
	}
	else if ((flagA != flagB) && c1 == c2) {
		if (flagB && a1 == a2) {
			float x = c1 / a1;
			std::cout << "x = " << x << std::endl;
		}
		else if (flagA && b1 == b2) {
			float y = c1 / b1;
			std::cout << "y = " << y << std::endl;
		}
		else {
			std::cout << "Введено некорректное значение коэффициентов или система имеет бесконченое кол-во решений" << std::endl;
		}
	}
	else {
		std::cout << "Введено некорректное значение коэффициентов или система имеет бесконченое кол-во решений" << std::endl;
	}
}


void test() {
	using Coefficient = float[10];
	Coefficient a1{ 0,  7, 17, 4,  14, 0, 0, 2, 4, 0 },
		    b1{ 2,  4,  1, 5, -12, 2, 0, 0, 4, 0 },
		    c1{ 3, -5, 24, 6,  11, 5, 7, 2, 4, 0 },
		    a2{ 0, 12,  0, 7,   5, 0, 4, 0, 4, 0 },
		    b2{ 2,  4, 12, 1,   7, 2, 5, 4, 4, 0 },
		    c2{ 3,  2,  7, 3,  -2, 6, 6, 5, 4, 0 };

	Coefficient xV { NAN, 1.4, 1.37745098039216, 0.290322580645161,  0.335443037974684, NAN, NAN, 1, NAN, NAN},
		    yV { 1.5, -3.7, 0.583333333333333, 0.967741935483871,  -0.525316455696203, NAN, NAN, 1.25, NAN, NAN};

	
	float x, y;
	for (int i = 0; i < std::end(a1) - std::begin(a1); i++) {
		std::cout << "| " << a1[i] << "x + " << b1[i] << "y = " << c1[i] << '\n'
			  << "| " << a2[i] << "x + " << b2[i] << "y = " << c2[i] << std::endl;

		std::cout << std::setw(17) << "GetedResult: ";
		solveEquationSystem(a1[i], b1[i], c1[i], a2[i], b2[i], c2[i]);

		if (xV[i] != xV[i] && yV[i] != yV[i]) {
			std::cout << std::setw(16) << "ExpectedResult:" << " Введено некорректное значение коэффициентов или система имеет бесконченое кол-во решений" << std::endl;
		}
		else if (xV[i] != xV[i]) {
			std::cout << std::setw(16) << "ExpectedResult:" << " y = " << yV[i] << '\n' << std::endl;
		}
		else if (yV[i] != yV[i]) {
			std::cout << std::setw(16) << "ExpectedResult:" << " x = " << xV[i] << '\n' << std::endl;
		}
		else {
			std::cout << std::setw(16) << "ExpectedResult:" << " x = " << xV[i] << " y = " << yV[i] << '\n' << std::endl;
		}
	}
}
