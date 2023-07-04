#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int>::const_iterator iter;
    vector<int> scores;

    cout << "Создаем список рекордов." << endl;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    cout << "\tРекорды:" << endl; 
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "Находим рекорд." << endl;
    int score;
    cout << "Введите рекорд для поиска: ";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end()) {
        cout << "Рекорд был найден." << endl;
    }
    else {
        cout << "Рекорд не найден." << endl;
    }

    cout << "\nРазброс рекордов (shuffle)." << endl;
    srand(time(0));
    random_shuffle(scores.begin(), scores.end());
    cout << "\tРекорды:" << endl; 
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nСортировка рекордов." << endl;
    sort(scores.begin(), scores.end(), greater<int>());
    cout << "\tРекорды:" << endl; 
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << endl;
    return 0;
}