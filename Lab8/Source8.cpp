/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 8
* Вариант № 26
* Задание: Даны две строки символов s1 и s2, а также натуральное число L. Выяснить,
  есть ли у этих строк общая подстрока длиной L.
***************************************************************************************/


#include <iostream>
#include <locale.h>
#include <string>
#include <vector>


void solveTask();

void findCommonSubstring(const std::string& s1, const std::string& s2, int L);

void test();


void main() {
	setlocale(LC_ALL, "Rus");

	// solveTask();
	test();
}


void solveTask() {
	std::string s1, s2, sub;
	std::cout << "Введите строку s1: ";
	std::cin >> s1;
	std::cout << "Введите строку s2: ";
	std::cin >> s2;

	int L;
	std::cout << "Введите длину подстроки L: ";
	std::cin >> L;

	findCommonSubstring(s1, s2, L);
}


void findCommonSubstring(const std::string& s1, const std::string& s2, int L) {
	for (int i = 0; i <= s1.length() - L; i++) {
		std::string sub = s1.substr(i, L);

		if (s2.find(sub) != std::string::npos) {
			std::cout << "Общая подстрока длиной " << L << " найдена: " << sub << std::endl;
			return;
		}
	}

	std::cout << "Общей подстроки длиной " << L << " не найдено" << std::endl;
}


void test() {
	std::vector<std::string> s1 = { "rabcdefx", "hellowor", "programming", "apple", "theIs"};
	std::vector<std::string> s2 = { "xyzabcdx", "world", "language", "banana", "NoSubstrings"};

	std::vector<int> L = { 4, 3, 2, 3, 5 };

	std::string sub;
	for (int i = 0; i < s1.size(); i++) {
		std::cout << "s1: " << s1[i] << " s2: " << s2[i] << std::endl;
		findCommonSubstring(s1[i], s2[i], L[i]);
		std::cout << std::endl;
	}
}