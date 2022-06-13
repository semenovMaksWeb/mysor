#include <windows.h>
#include <iostream>
#include "File.cpp"
static std::string filename;
void menuFile();
static void menuMain() {
	system("cls");
	std::cout << "¬ведите им€ файла:  \n";
	std::cin >> filename;
	menuFile();
}
static void perexodInMenuFile() {
	std::string index;
	std::cout << "0 - назад\n";
	std::cin >> index;
	if (index == "0") {
		menuFile();
	}
}
static void menuFile() {
	system("cls");
	std::string index;
	std::cout << "»м€ выбранного файла" << filename << "\n";
	std::cout << "0 - выбрать другой файл\n";
	std::cout << "1-прочитать файл\n";
	std::cout << "2-добавить запись в файл\n";
	std::cout << "3-поиск записей где груз больше 2 тонн\n";
	std::cin >> index;
	if (index == "1") {
		loadFile(filename);
		perexodInMenuFile();
	}
	else if (index == "2") {
		saveFile(filename);
		menuFile();
	}
	else if (index == "3") {
		filterFile(filename);
		menuFile();
	}
	else if(index == "0") {
		menuMain();
	}
	else {
		menuFile();
	}
}