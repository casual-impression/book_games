#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_ITEMS = 10;
    int numItems = 0;
    string inventory[MAX_ITEMS];

    inventory[numItems++] = "меч";
    inventory[numItems++] = "броня";
    inventory[numItems++] = "щит";

    for (int i=0; i<numItems; i++) {
        cout << i << ". " << inventory[i] << endl;
    }

    cout << "\nПредмет с наименованием '" << inventory[0] << "' имеет размер: " << inventory[0].length() << ".\n";
    cout << "Вы нашли зелье лечения.\n";
    
    if (numItems < MAX_ITEMS)
        inventory[numItems++] = "зелье лечения";
    else
        cout << "У вас уже слишком много предметов в рюкзаке. Больше не войдет.";

    cout << "\nВаши предметы:\n";
    for (int i = 0; i < numItems; i++)
        cout << i << ". " << inventory[i] << endl;

    return 0;
}