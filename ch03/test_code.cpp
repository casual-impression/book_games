#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>


enum fields {WORD, HINT, NUM_FIELDS};
const int NUM_WORDS = 5;
const std::wstring WORDS[NUM_WORDS][NUM_FIELDS] = {
    {L"стена", L"Вы чувствуете, что бьетесь головой об что-то?"},
    {L"очки", L"Они могут помочь вам разглядеть ответ."},
    {L"затрудненный", L"Идет медленно, верно?"},
    {L"устойчивый", L"Продолжайте в том же духе."},
    {L"беспорядок", L"В этом основа данной игры."}
};

std::wstring jumble_word(std::wstring original_word) {
    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Алгоритм тасования Фишера-Йетса
    for (int i = original_word.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(original_word[i], original_word[j]);
    }

    return original_word;
};

int main() {
    // Set the locale to support Russian characters
    std::locale::global(std::locale(""));

    std::wstring str = L"Привет, Мир!";
    std::wcout << L"Original string: " << str << " Size: " << str.size() << std::endl;
    str = jumble_word(str);
    std::wcout << L"Shuffled string: " << str << std::endl;

    return 0;
}