#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Инициализация генератора случайных чисел
    std::srand(std::time(0));

    int secretNumber, guess, minNumber, maxNumber;
    char answer;

    std::cout << "Давайте сыграем в игру 'Угадай число'!" << std::endl;

    do {
        // Просим игрока выбрать число
        std::cout << "Загадайте число от 1 до 100: ";
        std::cin >> secretNumber;

        // Генерируем первую попытку компьютера
        minNumber = 1;
        maxNumber = 100;
        guess = std::rand() % (maxNumber - minNumber + 1) + minNumber;

        // Компьютер пытается угадать число игрока
        int attempts = 1;
        while (guess != secretNumber) {
            std::cout << "Попытка " << attempts << ": Компьютер думает, что это число " << guess << std::endl;

            if (guess < secretNumber) {
                std::cout << "Загаданное число больше" << std::endl;
                minNumber = guess + 1;
            } else {
                std::cout << "Загаданное число меньше" << std::endl;
                maxNumber = guess - 1;
            }

            guess = std::rand() % (maxNumber - minNumber + 1) + minNumber;
            attempts++;
        }

        // Поздравляем компьютер с победой
        std::cout << "Компьютер успешно угадал число " << secretNumber;
        std::cout << " за " << attempts << " попыток!" << std::endl;

        // Предлагаем сыграть еще раз
        std::cout << "Хотите сыграть еще раз? (y/n): ";
        std::cin >> answer;

    } while (answer == 'y' || answer == 'Y');

    std::cout << "Спасибо за игру! До свидания!" << std::endl;

    return 0;
}