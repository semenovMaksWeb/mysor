// otdelCMI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Menu.cpp"
int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menuMain();
}