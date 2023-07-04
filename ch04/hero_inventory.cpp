#include "inventory.h"

int main() {
    Inventory obj;
    std::vector<std::string> items = {"меч", "броня", "щит"};

    printf("Ваш рюкзак содержит следующие вещи:\n");
    obj.add_items(items);
    obj.show_data();
    printf("\n");

    printf("Вы обменяли ваш меч на боевой топор. ");
    printf("Ваш рюкзак содержит следующие вещи:\n");
    obj.set_item(0, "боевой топор");
    obj.show_data();
    printf("\n");

    printf("Ваш щит был сломан в ожесточенной битве. ");
    printf("Ваш рюкзак содержит следующие вещи:\n");
    obj.remove_item(2);
    obj.show_data();
    printf("\n");

    printf("Все ваши предметы были украдены вором. ");
    printf("Ваш рюкзак содержит следующие вещи:\n");
    obj.clear();
    if (obj.is_empty()) {
        printf("Инвентарь пуст.\n");
    }
    else {
        printf("В инвентаре что-то лежит.\n");
    }
    printf("\n");

    return 0;
}