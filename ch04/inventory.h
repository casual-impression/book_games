// inventory.h
#pragma once

#include <vector>
#include <string>
#include <iostream>

class Inventory {
    public:
        void add_item(std::string item_name);
        void add_items(const std::vector<std::string>& items);
        void remove_item(int pos);
        void set_item(int pos, std::string item_name);
        void clear() { inventory.clear(); };
        bool is_empty() { return inventory.empty(); };
        void show_data();
    private:
        std::vector<std::string> inventory;
};

void Inventory::add_item(std::string item_name) {
    inventory.push_back(item_name);
}

void Inventory::add_items(const std::vector<std::string>& items) {
    for (const auto& item : items) {
        inventory.push_back(item);
    }
}

void Inventory::remove_item(int pos) {
    if (pos >= 0 && pos < inventory.size()) {
        inventory.erase(inventory.begin() + pos);
    }
}

void Inventory::set_item(int pos, std::string item_name) {
    if (pos >= 0 && pos < inventory.size()) {
        inventory[pos] = item_name;
    }
}

void Inventory::show_data() {
    for (const auto& item : inventory) {
        std::cout << item << std::endl;
    }
}