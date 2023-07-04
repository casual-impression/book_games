#include <iostream>
#include "score.h"

int main() {
    float values[] = {140.25, 230.50, 170.0}; 
    Score test_data(values);
    
    std::cout << "Значения: ";
    for (auto value: values) {
        std::cout << value << ' ';
    }

    std::cout << "\nСреднее: " << test_data.get_avg() << std::endl;
}