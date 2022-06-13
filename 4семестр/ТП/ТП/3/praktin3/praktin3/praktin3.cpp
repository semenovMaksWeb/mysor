// praktin3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

std::string checkNumber();

int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Введите a\n";
    std::string a = checkNumber();
    std::cout << "Введите b\n";
    std::string b = checkNumber();
    std::cout << "Введите c\n";
    std::string c = checkNumber();
    std::cout << "Введите d\n";
    std::string d = checkNumber();
    stoi(a) - 1 >= stoi(c) && stoi(b) - 1 >= stoi(d) ? std::cout << "Войдет" : std::cout << "Не войдет";
}




bool isUint(const std::string& s) {
    return s.find_first_not_of("0123456789") == std::string::npos;
}

std::string checkNumber() {
    std::string str;
    while (true) {
        
        getline(std::cin, str);
        if (!str.empty() && isUint(str)) {
            break;
        }
        else {
            std::cout << "указать нужно число!\n";
        }
    }
    return str;
}


 