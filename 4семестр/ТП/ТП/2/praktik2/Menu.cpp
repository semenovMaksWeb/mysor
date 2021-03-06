#include <windows.h>
#include <iostream>
#include "File.cpp"
#include <regex>
#include "Command.cpp"
static std::string filename;
void menuFile();
void MenuCommand();
void menuMain();

static void menuType() {
	std::cout << "1-????? ??????\n";
	std::cout << "2-????? ???????\n";
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
	cin.ignore();
	std::string command;
	getline(std::cin, command);
	CommandCheck(command);
	MenuCommand();
}


static void menuMain() {
	system("cls");
	std::cout << "??????? ??? ?????:  \n";
	std::cin >> filename;
	menuFile();
}
static void perexodInMenuFile() {
	std::string index;
	std::cout << "0 - ?????\n";
	std::cin >> index;
	if (index == "0") {
		menuFile();
	}
}
static void menuFile() {
	system("cls");
	std::string index;
	std::cout << "??? ?????????? ?????" << filename << "\n";
	std::cout << "0 - ??????? ?????? ????\n";
	std::cout << "1-????????? ????\n";
	std::cout << "2-???????? ?????? ? ????\n";
	std::cout << "3-????? ??????? ??? ???? ?????? 2 ????\n";
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