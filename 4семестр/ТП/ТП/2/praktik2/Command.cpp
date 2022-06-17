#include <iostream>
#include <string>
#include "File.cpp"

void CommandCheck(string command);
void CommnadCheckGet(string command);
void CommandCheckFilter(string command);
void CommandCheckHelp(string command);
void CommandCheckAdd(string command);
 
static void getHelp() {
	std::cout << "get {{name}} прочитать содержимое файла где {{name}}- имя файла\n";
	std::cout << "save {{name}} добавить запись в файл где {{name}}- имя файла\n";
	std::cout << "filter {{name}} new {{new_name}} добавить запись в файл где {{name}}- имя файла а {{new_name}} имя нового файла\n";
 
}
static void CommandCheck(string command) {
	CommandCheckHelp(command);
	CommnadCheckGet(command);
	CommandCheckAdd(command);
	CommandCheckFilter(command);
}
static void CommnadCheckGet(string command) {
	if (command[0] == 'g' && command[1] == 'e' && command[2] == 't') {
		string fileName = command.substr(4, command.length());
		system("cls");
		loadFile(fileName);
	}
}
static void CommandCheckHelp(string command) {
	if (command == "help") {
		getHelp();
	}
}
static void CommandCheckFilter(string command) {
	if (command[0] == 'f' && command[1] == 'i' && command[2] == 'l' && command[3] == 't' && command[4] == 'e' && command[5] == 'r') {
		std::string file = command.substr(5, command.length());
		filterFile(file);
 
	}
}
static void CommandCheckAdd(string command) {
	if (command[0] == 's' && command[1] == 'a' && command[2] == 'v' && command[3] == 'e') {
		std::string file = command.substr(5, command.length());
		saveFile(file);
	}
}