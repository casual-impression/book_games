#include <iostream>
using namespace std;

void showScore(int me, int mike);

int main() {
    int myScore = 1000;
    int& mikesScore = myScore;

    showScore(myScore, mikesScore);
    cout << "Я (+500)..." << endl;
    myScore += 500;
    showScore(myScore, mikesScore);
    cout << "Майк (+500)..." << endl;
    mikesScore += 500;
    showScore(myScore, mikesScore);

    return 0;
}

inline void showScore(int me, int mike) {
    cout << "Я: " << me << endl;
    cout << "Майк: " << mike << endl;
}