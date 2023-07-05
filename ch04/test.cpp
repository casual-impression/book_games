#include <iostream>

using namespace std;

enum difficulty {EASY = 1, NORMAL, HARD};

int main() {
    std::string data;
    int choice;

    cout << "Выберите уровень сложности:" << endl;
    cout << "1. EASY" << endl;
    cout << "2. NORMAL" << endl;
    cout << "3. HARD" << endl;

    do {
        cout << "Ваш выбор: ";
        getline(cin, data);
        try {
            choice = stoi(data);
        }
        catch(std::invalid_argument const& ex) {
            choice = 0;
        }
        

        switch (choice) {
            case EASY:
                cout << "Изи!" << endl;
                break;
            case NORMAL:
                cout << "Нормально." << endl;
                break;
            case HARD:
                cout << "Сложнааа..." << endl;
                break;
            default:
                cout << "Неправильно набран номер. Попробуй еще." << endl;
        }
    } while (choice < EASY || choice > HARD);

    return 0;
}