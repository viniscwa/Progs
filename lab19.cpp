#include <iostream>
#include <vector>
#include <string>

struct Bus {
    int number;
    std::string driver;
    int route;
};

int main() {
    std::vector<Bus> park, route;
    
    // начальное формирование данных
    park.push_back({1, "Иванов И.И.", 10});
    park.push_back({2, "Петров П.П.", 5});
    
    int choice, busNumber;
    
    do {
        std::cout << "1. Автобус выезжает из парка\n";
        std::cout << "2. Автобус въезжает в парк\n";
        std::cout << "3. Сведения об автобусах в парке\n";
        std::cout << "4. Сведения об автобусах на маршруте\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Введите номер автобуса для выезда из парка: ";
                std::cin >> busNumber;
                
                for (int i = 0; i < park.size(); i++) {
                    if (park[i].number == busNumber) {
                        route.push_back(park[i]);
                        park.erase(park.begin() + i);
                        break;
                    }
                }
                break;
            case 2:
                std::cout << "Введите номер автобуса для въезда в парк: ";
                std::cin >> busNumber;
                
                for (int i = 0; i < route.size(); i++) {
                    if (route[i].number == busNumber) {
                        park.push_back(route[i]);
                        route.erase(route.begin() + i);
                        break;
                    }
                }
                break;
            case 3:
                std::cout << "Сведения об автобусах в парке:\n";
                for (const auto& bus : park) {
                    std::cout << "Номер: " << bus.number << ", Водитель: " << bus.driver << ", Маршрут: " << bus.route << std::endl;
                }
                break;
            case 4:
                std::cout << "Сведения об автобусах на маршруте:\n";
                for (const auto& bus : route) {
                    std::cout << "Номер: " << bus.number << ", Водитель: " << bus.driver << ", Маршрут: " << bus.route << std::endl;
                }
                break;
            case 0:
                std::cout << "Выход из программы\n";
                break;
            default:
                std::cout << "Ошибка! Некорректный ввод.\n";
        }
        
    } while (choice != 0);

    return 0;
}