#include <iostream>
#include <vector>

using namespace std;

string& refToElement(vector<string>& vec, int i) { return vec[i]; };

int main() {
    vector<string> inventory;
    inventory.push_back("1");
    inventory.push_back("2");
    inventory.push_back("3");

    cout << "Element 0: ";
    cout << refToElement(inventory, 0) << endl;

    string& rStr = refToElement(inventory, 1);
    string str = refToElement(inventory, 2);

    cout << "Element 1: ";
    cout << rStr << endl;

    cout << "Element 2: ";
    cout << str << endl;

    cout << "\nChanging reference to element1 reference value. ";
    rStr += "!1!";
    cout << "Element 1: ";
    cout << inventory[1] << endl;

    cout << "\nChanging copy to element1 reference value. ";
    str += "!2!";
    cout << "Element 2: ";
    cout << inventory[2] << endl;

    return 0;
}