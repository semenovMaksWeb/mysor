#include <windows.h>
#include <iostream>
#include "File.cpp"
#include <regex>
static std::string filename;
void menuFile();
void MenuCommand();
void menuMain();
void CommandCheck(std::string command);
void CommandCheckHelp(std::string command);
void CommnadCheckGet(std::string command);
void CommandCheckAdd(std::string command);
void CommandCheckFilter(std::string command);

static void menuType() {
	std::cout << "1-режим текста\n";
	std::cout << "2-режим команды\n";
	std::string index;
	std::cin >> index;
	if (index == "1") {
		menuMain();
	}
	else if (index == "2") {
		MenuCommand();
	}
}
static void MenuCommand() {
	std::string command;
	getline(std::cin, command);
	CommandCheck(command);
}
static void menuMain() {
	system("cls");
	std::cout << "Введите имя файла:  \n";
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
	std::cout << "Имя выбранного файла" << filename << "\n";
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
	else if (index == "0") {
		menuMain();
	}
	else {
		menuFile();
	}
}
static void getHelp() {
	std::cout << "get {{name}} прочитать содержимое файла где {{name}}- имя файла\n";
	std::cout << "save {{name}} добавить запись в файл где {{name}}- имя файла\n";
	std::cout << "filter {{name}} добавить запись в файл где {{name}}- имя файла\n";

}
static int status = 0;
static void CommandCheck(std::string command) {
	status = 0;
	CommandCheckHelp(command);
	CommnadCheckGet(command);
	CommandCheckAdd(command);
	CommandCheckFilter(command);
	if (status == 0) {
		getHelp();
		MenuCommand();
	}

}
static void CommnadCheckGet(std::string command) {
	if (command[0] == 'g' && command[1] == 'e' && command[2] == 't') {
		std::string fileName = command.substr(4, command.length());
		system("cls");
		loadFile(fileName);
		status = 1;
		MenuCommand();
	}
}
static void CommandCheckHelp(std::string command) {
	if (command == "help") {
		getHelp();
		status = 1;
		MenuCommand();
	}
}
static void CommandCheckFilter(std::string command) {

	if (command[0] == 'f' && command[1] == 'i' && command[2] == 'l' && command[3] == 't' && command[4] == 'e' && command[5] == 'r') {
		std::string file = command.substr(7, command.length());
		filterFile(file);
			std::cout << file << "\n";
		status = 1;
		MenuCommand();

	}
}
static void CommandCheckAdd(string command) {
	if (command[0] == 's' && command[1] == 'a' && command[2] == 'v' && command[3] == 'e') {
		std::string file = command.substr(5, command.length());
		saveFile(file);
		status = 1;
		MenuCommand();
	}
}