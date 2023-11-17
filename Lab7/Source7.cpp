/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 7
* Вариант № 26
* Задание:  Дана прямоугольная целочисленная матрица размера m строк и n столбцов.
  Последовательность элементов матрицы, расположенных по чётным строкам слева направо,
  по нечётным строкам справа налево, (строки рассматриваем последовательно сверху вниз) 
  назовем «змейкой». Сдвинуть циклически элементы змейки на одну позицию к концу.
***************************************************************************************/


#include <iostream>
#include <locale.h>
#include <vector>


using Matrix = std::vector<std::vector<int>>;


void solveTask();

void fillMatrix(Matrix& mat);
void shiftSnake(Matrix& mat);
void printMatrix(const Matrix& mat);

void swap(int& a, int& b);

void test();


int main() {
    setlocale(LC_ALL, "Rus");

    // solveTask();
    test();
}


void solveTask() {
    int m, n;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> n;

    Matrix matrix(m, std::vector<int>(n, 0));

    fillMatrix(matrix);

    std::cout << "Сгенерированная матрица:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    shiftSnake(matrix);

    std::cout << "Матрица после сдвига змейки на одну позицию:" << std::endl;

    printMatrix(matrix);
}


void fillMatrix(Matrix& mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[1].size(); j++) {
            mat[i][j] = rand() % 100;
        }
    }
}


void shiftSnake(Matrix& mat) {
    int m, n;
    m = mat.size();
    n = mat[0].size();

    int temp = 0;
    for (size_t i = 0; i < m; i++) {
        if (i % 2)
            for (int j = 0; j < n; j++)
                swap(mat[i][j], temp);
        else
            for (int j = n - 1; j >= 0; j--)
                swap(mat[i][j], temp);
    }

    mat[0][n - 1] = temp;
}


void printMatrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[1].size(); j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void test() {
    Matrix matrix = { {3, 2, 1},
                      {4, 5, 6},
                      {9, 8, 7} };

    std::cout << "Матрица:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    for (size_t i = 0; i < 9; i++) {
        std::cout << "Сдвиг: " << i + 1 << std::endl;
        shiftSnake(matrix);
        printMatrix(matrix);
        std::cout << std::endl;
    }
}