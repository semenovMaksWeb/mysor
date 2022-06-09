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
	std::cout << "Введите логин:";
	std::cin >> login;
	std::cout << "Введите Пароль:";
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
	std::cout << "0 - Назад\n";
	std::cout << "Укажите № новости для её чтения\n";
	if (client_admin == 1) {
		std::cout << "+ - Создать новость\n";
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
	std::cout << "0 - Назад\n";
	if (client_admin == 1) {
		std::cout << "1 - удалить запись\n";
	}
	string index_vvod;
	std::cin >> index_vvod;
	if (index_vvod == "0") {
		ViewNewsName();
	}
	if (index_vvod == "1" && client_admin == 1) {
		DeleteFileIndex(index);
		ViewNewsName();
	}
}

static void menuMain() {
	system("cls");
	std::string index;
	std::cout << "1 - Зайти как гость\n";
	std::cout << "2 - Зайти админ\n";
	std::cin >> index;
	if (index == "1") {
		client_admin = 0;
		ViewNewsName();
		// сразу выводить новости!
		
	}
	else if (index == "2") {
		menuBxodAdmin();
	}
	else {
		menuMain();
	}

}
 