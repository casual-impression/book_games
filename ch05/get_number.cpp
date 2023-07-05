#include <iostream>
#include <string>
#include <limits>

float getUserNumber(const std::string& prompt = "Введите число: ") {
    std::cout << prompt;
    float number;
    std::cin >> number;
    if (std::cin.fail()) {
        std::cout << "Ошибка: введено некорректное число." << std::endl;
        number = 0.0f;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return number;
}

int main() {
    float number1 = getUserNumber("Введите целое число: ");
    std::cout << "Введенное число: " << number1 << std::endl;

    float number2 = getUserNumber(); // Using default argument
    std::cout << "Введенное число: " << number2 << std::endl;

    return 0;
}
