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

void welcome() {
    std::wcout << L"Добро пожаловать в игру 'Словомешалка'." << std::endl;
    std::wcout << L"Расшифруйте буквы, чтобы составить слово." << std::endl;
    std::wcout << L"Введите 'hint' для подсказки." << std::endl;
    std::wcout << L"Введите 'quit' для выхода.\n" << std::endl;
};

struct data_needed {
    int choice;
    std::wstring word, hint, jumble;
};

struct data_needed prepare_data() {
    struct data_needed Obj;
    // Random seed - to choose "random" word.
    srand(time(0));

    Obj.choice = rand() % NUM_WORDS;
    Obj.word = WORDS[Obj.choice][WORD];
    Obj.hint = WORDS[Obj.choice][HINT];
    Obj.jumble = jumble_word(Obj.word);

    return Obj;
}

int main() {
    // Set the locale to support Russian characters
    std::locale::global(std::locale(""));

    bool isRunning = true;
    struct data_needed Object = prepare_data();
    std::wstring guess;

    welcome();
    std::wcout << L"Замешанное слово: " << Object.jumble << std::endl;
    std::wcout << L"Начальное слово: ";
    std::wcin >> guess;

    while (isRunning) {
        if (guess == Object.word)
        {
            std::wcout << L"Вы угадали! Поздравляю.\n";
            isRunning = false;
        }
        else if (guess == L"quit") {
            std::wcout << L"Жаль, что вы решили выйти.\n";
            std::wcout << L"Правильный ответ: " << Object.word << std::endl;
            isRunning = false;
        }
        else if (guess == L"hint") {
            std::wcout << L"Подсказка: " << Object.hint << std::endl;
            std::wcout << L"Начальное слово: ";
            std::wcin >> guess;
        }
        else {
            std::wcout << L"Вы не угадали. Попробуйте еще раз.\n";
            std::wcout << L"Начальное слово: ";
            std::wcin >> guess;
        }
    }
    
    std::wcout << L"Всего доброго!\n";
    return 0;
}