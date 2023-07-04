#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    int guess = 0;

    cout << "\tДобро пожаловать в игру 'Угадай число'.\n\n";

    while (guess != secretNumber) {
        tries++;

        cout << "Предположение (1..100): ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "мало\n\n";
        }
        else if (guess > secretNumber) {
            cout << "много\n\n";
        }
        else {
            cout << "угадал!\n\n";
        }
    }

    cout << "Количество попыток: " << tries << endl;
    return 0;
}