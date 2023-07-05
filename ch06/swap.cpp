#include <iostream>
using namespace std;

void badSwap(int x, int y);
void goodSwap(int& x, int& y);
void showData(int x, int y);

int main() {
    int myScore = 150;
    int yourScore = 1000;

    showData(myScore, yourScore);
    cout << "Вызываю badSwap()" << endl;
    badSwap(myScore, yourScore);
    showData(myScore, yourScore);
    cout << "Вызываю goodSwap()" << endl;
    goodSwap(myScore, yourScore);
    showData(myScore, yourScore);

    return 0;
}

void showData(int x, int y) {
    cout << "myScore = " << x << endl;
    cout << "yourScore = " << y << endl << endl;
}

void badSwap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int&x, int& y) {
    x += y;
    y = x - y;
    x = x - y; 
}