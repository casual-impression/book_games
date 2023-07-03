#include <iostream>
#include <string>

using namespace std;

struct data_needed 
{
    const int GOLD_PIECES = 1000;
    int total, killed;
    string leader;
};

// function definition
struct data_needed prepare_data() 
{
    struct data_needed Obj;
    int index = 0;

    string intro_msg[] = 
    {
        "Добро пожаловать в секцию 'Потерянный клад'.", 
        "Для персонализации данных, введите следующую информацию:",
        "Введите число (первоначальный отряд):",
        "Введите число (кол-во павших):",
        "Введите фамилию (лидер):"
    };

    for (auto next_msg: intro_msg) 
    {
        std::cout << next_msg << std::endl;

        switch (index)
        {
            case 2:
                cin >> Obj.total;
                break;
            case 3:
                cin >> Obj.killed;
                break;
            case 4:
                cin >> Obj.leader;
                break;
            default:
                break;
        }

        index++;
    }

    return Obj;
};


void tell_a_story(struct data_needed object) {
    int survived = object.total - object.killed;

    string plot_msg[] = 
    {
        "\nХрабрая группа из " +to_string(object.total)+ " направилась на приключение -- в поиске затерянного сокровища Древних Гномов.",
        "Группа была под руководством легендарного жулика. Звали его " +object.leader+ ".\n",
        "По пути, отряд огров-мародеров устроил этой группе засаду.",
        "Все сражались храбро под командоманием героя " +object.leader+ ", и в конечном счете огры были повержены. Но какой ценой!",
        "Из всех приключенцев, " +to_string(object.killed)+ " было побеждено. В группе в итоге осталось " +to_string(survived)+ " человек.\n",
        "Группа уже была готова потерять всякую надежду. Однако при упокоении усопших, они случайно наткнулись на зарытое состояние.",
        "Участники разделили все найденное сокровище между собой поровну: " +to_string(object.GOLD_PIECES)+  " слитков золота.",
        "Лидер группы прикарманил себе дополнительно '" +to_string(object.GOLD_PIECES % survived)+ "' кусков золота, чтобы сохранить разделение справедливым, естественно."
    };

    for (auto next_line: plot_msg) {
        std::cout << next_line << endl;
    }
};

int main() {
    tell_a_story(prepare_data());

    return 0;
}
