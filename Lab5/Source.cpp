/***************************************************************************************
* Автор: Пушин Г.В.
* Группа: ИТ-11(2)
*
* Лабораторная работа № 5
* Вариант № 26
* Задание:  Даны четыре вещественных положительных числа 𝑎, 𝑏, 𝑐, 𝑑. Найти 
  среди них все тройки Пифагора.
***************************************************************************************/


#include <iostream>
#include <algorithm>
#include <vector>


using VecD = std::vector<double>;

void findPythagoreanTriplets(VecD nums);
bool isPythagoreanTriplets(VecD comb);
void findCombinations(VecD& nums, VecD& comb, std::vector<VecD>& combs, int index, int length);
void findPlacements(VecD& nums, std::vector<VecD>& perms, int index);

void test();


int main() {
    VecD numbers = { 0, 0, 0, 1 };
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] *= numbers[i];
    
    findPythagoreanTriplets(numbers);
}


void findPythagoreanTriplets(VecD nums) {
    VecD combination;
    std::vector<VecD> combinations;
    findCombinations(nums, combination, combinations, 0, 3);

    std::vector<VecD> permutations;
    std::vector<VecD> pythagoreanTriplets;
    for (size_t i = 0; i < combinations.size(); i++) {
        permutations.clear();
        findPlacements(combinations[i], permutations, 0);

        for (const auto& permutation : permutations) {
            bool isContain = std::binary_search(pythagoreanTriplets.begin(), pythagoreanTriplets.end(), permutation);

            if (isPythagoreanTriplets(permutation) && !isContain)
                pythagoreanTriplets.push_back(permutation);
        }
    }

    std::cout << "PythagoreanTriplets: " << std::endl;
    if (pythagoreanTriplets.size()) {
        for (const auto& tripl : pythagoreanTriplets) {
            for (const auto& num : tripl)
                std::cout << sqrt(num) << " ";

            std::cout << std::endl;
        }
    }
    else {
        std::cout << "None" << std::endl;
    }
}


bool isPythagoreanTriplets(VecD comb) {
    return comb[0] + comb[1] == comb[2];
}


void findCombinations(VecD& nums, VecD& comb, std::vector<VecD>& combs, int index, int length) {
    if (comb.size() == length) {
        combs.push_back(comb);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        comb.push_back(nums[i]);
        findCombinations(nums, comb, combs, i + 1, length);
        comb.pop_back();
    }
}


void findPlacements(VecD& nums, std::vector<VecD>& perms, int index) {
    if (index == nums.size() - 1) {
        perms.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        std::swap(nums[index], nums[i]);
        findPlacements(nums, perms, index + 1);
        std::swap(nums[index], nums[i]);
    }
}


void test() {

}