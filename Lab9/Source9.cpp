/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 9
* Вариант № 26
* Задание: Дана символьная строка, в которой могут быть круглые скобки. Реализовать
  булевскую рекурсивную функцию, возвращающую истина, если в строке соблюден баланс
  круглых скобок, и ложь – в противном случае.
***************************************************************************************/


#include <iostream>
#include <locale.h>
#include <string>


const std::string MSG_T = " Баланс соблюдён ";
const std::string MSG_F = " Баланс не соблюдён ";


void solveTask();

bool isBalanced(const std::string& str);
bool isBalancedReq(const std::string& str, int index = 0, int count = 0);

void test();


int main() {
	setlocale(LC_ALL, "Rus");

	// solveTask();
	test();
}


void solveTask() {
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);


	std::cout << "В строке: " << str << std::endl;

	if (isBalanced(str))
		std::cout << "(DEF)" << MSG_T << std::endl;
	else
		std::cout << "(DEF)" << MSG_F << std::endl;

	if (isBalancedReq(str))
		std::cout << "(REQ)" << MSG_T << std::endl;
	else
		std::cout << "(REQ)" << MSG_F << std::endl;
}


bool isBalanced(const std::string& str) {
	int balance = 0;

	for (size_t i = 0; i < str.length(); i++) {
		if (balance < 0) return false;

		if (str[i] == '(') balance++;
		else if (str[i] == ')') balance--;
	}

	return balance == 0;
}


bool isBalancedReq(const std::string& str, int index, int count) {
	if (index == str.length()) {
		return count == 0;
	}

	if (str[index] == '(') {
		return isBalancedReq(str, index + 1, count + 1);
	}

	if (str[index] == ')') {
		if (count == 0) {
			return false;
		}
		return isBalancedReq(str, index + 1, count - 1);
	}

	return isBalancedReq(str, index + 1, count);
}


void test() {
	std::string strings[6] = {
		"Hello(world)!",
		"IsBal(la(nce)d)",
		"No(Bala( )nced",
		"( ( ( ) ) )",
		"((()()()()))))",
		"(1 (0) (0) (2 (0) (0) 2) 1)"
	};

	for (size_t i = 0; i < 6; i++) {
		std::cout << "В строке: " << strings[i] << std::endl;

		if (isBalanced(strings[i]))
			std::cout << "(DEF)" << MSG_T << std::endl;
		else
			std::cout << "(DEF)" << MSG_F << std::endl;
		
		if (isBalancedReq(strings[i]))
			std::cout << "(REQ)" << MSG_T << std::endl;
		else
			std::cout << "(REQ)" << MSG_F << std::endl;

		std::cout << std::endl;
	}
}