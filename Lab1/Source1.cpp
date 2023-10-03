/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
* 
* Лабораторная работа № 1
* Вариант № 26
* Задание: Ребенок-вундеркинд учит слова тарабарского языка. В первый день обучения
  он выучил 1 слово, в каждый последующий день он учит вдвое больше слов, чем в день
  предыдущий. Сколько дней понадобится ребенку выучить весь тарабарский язык, если
  всего в нём N слов? Циклами не пользоваться.
***************************************************************************************/


#include <iostream>
#include <locale>
#include <math.h>
#include <iomanip>


int getDaysCount(int words);
void test();


void main() {
	setlocale(LC_ALL, "Rus");

	int n = 0;
	std::cout << "Введите n : ";
	std::cin >> n;

	std::cout << "На изучение " << n << " слов, понадобится дней : " << getDaysCount(n) * (n > 0) << std::endl;

	// test();
}


int getDaysCount(int words) {
	int days = 0;
	int whole = 0;
	float fract = 0;

	fract = log2(words);
	whole = std::ceil(fract);
	fract -= whole;

	days = whole + (fract == 0);

	return days;
}


void test() {
	int words[7] { 224, 456, 128, 45, 65, 63, 15 };
	int correctAnswers[7] { 8, 9, 8, 6, 7, 6, 4 };

	for (int i = 0; i < std::end(words) - std::begin(words); i++) {
		std::cout << "| Слов " << std::setw(5) << words[i]
				  << "| Ответ " << std::setw(5) << getDaysCount(words[i])
				  << "| Верный ответ " << std::setw(5) << correctAnswers[i] << " |" << std::endl;
	}
}