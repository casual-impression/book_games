// Программа Безумные Библиотекари
// Формирует краткую историю на основе пользовательского ввода
#include <iostream>
#include <limits>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main() {
    cout << "Добро пожаловать в историю Безумного Библиотекаря." << endl;
    cout << "Ответьте на следующие вопросы, чтобы помочь создать новый рассказ." << endl;
    string name = askText("Введите имя: ");
    string noun = askText("Введите существительное (ед. число): ");
    int number = askNumber("Введите целое число: ");
    string bodyPart = askText("Введите часть тела: ");
    string verb = askText("Введите глагол (ед. число): ");

    tellStory(name, noun, number, bodyPart, verb);

    return 0;
}

string askText(string prompt) {
    string text;
    do {
        cout << prompt;
        getline(cin, text);
    } while (text.empty());

    return text;
}

int askNumber(string prompt) {
    int number;
    bool correct_prompt = false;

    do {
        cout << prompt;
        cin >> number;

        if (cin.fail()) {
            cout << "Ошибка: некорректный ввод." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            correct_prompt = false;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            correct_prompt = true;
        }
    }
    while (!correct_prompt);

    
    return number;
}

void tellStory(string name, string noun, int number, string bodyPart, string verb) {
    cout << "\nТакова история:" << endl;
    cout << "Известный исследователь " << name;
    cout << " почти отказался от давнишнего стремления найти\n";
    cout << "Затерянный Город '" << noun << "'. ";
    cout << "Пока в один день " << noun << " не нашел исследователя.\n";
    cout << "Окруженный " << number << " существами " << noun << ", ";
    cout << "слеза упала на " << bodyPart << " бедолаги " << name << ".\n";
    cout << "После всего этого времени, квест по поиску был наконец завершен.\n";
    cout << "И затем, " << noun << " быстро проглотил приключенца под именем " << name;
    cout << ".\n" << "Мораль этой истории? Остерегайся того, что ты " << verb << ".\n";
    cout << endl;  
}
