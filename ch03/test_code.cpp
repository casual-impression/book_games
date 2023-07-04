#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

int main() {
    // Set the locale to support Russian characters
    std::locale::global(std::locale(""));

    std::wstring str = L"Привет, Мир!";

    std::wcout << L"Original string: " << str << " Size: " << str.size() << std::endl;

    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Алгоритм тасования Фишера-Йетса
    for (int i = str.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(str[i], str[j]);
    }

    std::wcout << L"Shuffled string: " << str << std::endl;

    return 0;
}