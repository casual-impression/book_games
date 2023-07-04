#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> gameList;
    std::string gameTitle;
    char choice;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Перечислить все игры" << std::endl;
        std::cout << "2. Добавить игру" << std::endl;
        std::cout << "3. Удалить игру" << std::endl;
        std::cout << "4. Выход" << std::endl;

        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            if (gameList.empty()) {
                std::cout << "Список игр пуст" << std::endl;
            }
            else {
                std::cout << "Список игр:" << std::endl;
                for (const std::string& title: gameList) {
                    std::cout << title << std::endl;
                }
            }
            break;
        case '2':
            std::cout << "Введите название игры: ";
            std::cin.ignore();
            std::getline(std::cin, gameTitle);
            gameList.push_back(gameTitle);
            std::cout << "Игра успешно добавлена" << std::endl;
            break;
        case '3':
            if (gameList.empty()) {
                std::cout << "Список игр пуст" << std::endl;
            }
            else {
                std::cout << "Введите название игры для удаления: ";
                std::cin.ignore();
                std::getline(std::cin, gameTitle);

                auto it = std::find(gameList.begin(), gameList.end(), gameTitle);
                if (it != gameList.end()) {
                    gameList.erase(it);
                    std::cout << "Игра успешно удалена" << std::endl;
                }
                else {
                    std::cout << "Игра не найдена" << std::endl;
                }
            }
            break;
        case '4':
            std::cout << "Программа завершена" << std::endl;
            break;
        default:
            std::cout << "Неверный ввод, попробуйте еще раз" << std::endl;
        } 

        std::cout << std::endl;
    } while (choice != '4');

    return 0;
}