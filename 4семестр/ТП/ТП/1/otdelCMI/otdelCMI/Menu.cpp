#include <string>
#include <windows.h>
#include <iostream>
#include "FileNews.cpp"
void menuBxodAdmin();
void ViewNewsName();
void menuMain();
void ViewNewsFull(string index);
static int client_admin = 0;
static void menuBxodAdmin() {
	system("cls");
	std::string login;
	std::string password;
	std::cout << "??????? ?????:";
	std::cin >> login;
	std::cout << "??????? ??????:";
	std::cin >> password;
	if (login == "admin" && password == "12345") {
		client_admin = 1;
		ViewNewsName();
	}
	else {
		menuMain();
	}

}
static void ViewNewsName() {
	system("cls");
	std::string index;
	loadFileName();
	std::cout << "0 - ?????\n";
	std::cout << "??????? ? ??????? ??? ?? ??????\n";
	if (client_admin == 1) {
		std::cout << "+ - ??????? ???????\n";
	}
	std::cin >> index;
	if (index == "0") {
		menuMain();
	}
	if (index == "+" && client_admin == 1) {
		saveNews();
		ViewNewsName();
	}
	else {
		ViewNewsFull(index);
	}
}
static void ViewNewsFull(string index) {
	loadFileFullIndex(index);
	std::cout << "0 - ?????\n";
	if (client_admin == 1) {
		std::cout << "- ??????? ??????\n";
	}
	string index_vvod;
	std::cin >> index_vvod;
	if (index_vvod == "0") {
		ViewNewsName();
	}
	if (index_vvod == "-" && client_admin == 1) {
		DeleteFileIndex(index);
		ViewNewsName();
	}
}

static void menuMain() {
	system("cls");
	std::string index;
	std::cout << "1 - ????? ??? ?????\n";
	std::cout << "2 - ????? ?????\n";
	std::cin >> index;
	if (index == "1") {
		client_admin = 0;
		ViewNewsName();
		// ????? ???????? ???????!
		
	}
	else if (index == "2") {
		menuBxodAdmin();
	}
	else {
		menuMain();
	}

}
 