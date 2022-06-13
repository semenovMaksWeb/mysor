#include <windows.h>
#include <string>
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <conio.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>
#include "libs.cpp"
using namespace std;

static struct Reis
{
    std::string AutoMarka;
    std::string AutoNumber;
    std::string Adress;
    std::string height;
    std::string price;
    std::string stoimost;
};
static Reis readReas(string text) {
    Reis reis;
    std::size_t AutoMarka = text.find(";");
    reis.AutoMarka = text.substr(0, AutoMarka);
    string text2 = text.substr(AutoMarka + 1, text.length());
    std::size_t AutoNumber = text2.find(";");
    reis.AutoNumber = text2.substr(0, AutoNumber);
    string text3 = text2.substr(AutoNumber + 1, text2.length());
    std::size_t Adress = text3.find(";");
    reis.Adress = text3.substr(0, Adress);
    string text4 = text3.substr(Adress + 1, text3.length());
    std::size_t height = text4.find(";");
    reis.height = text4.substr(0, height);
    string text5 = text4.substr(height + 1, text4.length());
    std::size_t price = text5.find(";");
    reis.price = text5.substr(0, price);
    string text6 = text5.substr(height + 1, text5.length());
    reis.stoimost = text6.substr(1, text6.length());
    return reis;
}
static void loadFile(string filename) {
    system("cls");
    std::string text;
    std::fstream fs;
    fs.open("file/" + filename, std::fstream::in | std::fstream::out | std::fstream::app);
    int count = 0;
    cout << setw(2) << "%|" << setw(15) << "марка авто" 
         << setw(17) << "номер авто"   << setw(15) << "п.н."
         << setw(20) << "грузоподъемность" << setw(30) << "стоимость ед. г."
         << setw(20) << "стоимость" << "\n";
    while (getline(fs, text)) {
        count++;
        Reis reis;
        reis = readReas(text);
        cout << setw(2) << count << setw(15) << reis.AutoMarka
            << setw(17) << reis.AutoNumber << setw(15) << reis.Adress
            << setw(20) << reis.height << setw(30) << reis.price
            << setw(20) << reis.stoimost << "\n";
    }
}
static void saveFile(string filename) {
    bool checkHeight = false;
    bool checkPrice = false;
    system("cls");
    static Reis reis;
    cin.ignore();
    std::cout << "Введите марку авто:";
    getline(std::cin, reis.AutoMarka);
    std::cout << "Введите номер авто: ";
    getline(std::cin, reis.AutoNumber);
    std::cout << "пункт назначения:";
    getline(std::cin, reis.Adress);
    std::cout << "грузоподъемность:";;
    getline(std::cin, reis.height);
    std::cout << "стоимость единицы груза:";
    getline(std::cin, reis.price);
    float height = stoi(reis.height);
    int price = stoi(reis.price);
    int stoimost = price * height;
    reis.stoimost = std::to_string(stoimost);
    std::fstream fs;
    fs.open("file/" + filename, std::fstream::in | std::fstream::out | std::fstream::app);
    fs << reis.AutoMarka << ";" << reis.AutoNumber << ";"<< reis.Adress << ";" << reis.height << ";" << reis.price << ";" << reis.stoimost << "\n";
    fs.close(); //  
}
static void filterFile(string filename) {
    system("cls");
    std::string textFile;
    std::string fileNews;
    std::string text;
    std::fstream fs;
    fs.open("file/" + filename, std::fstream::in | std::fstream::out | std::fstream::app);
    int count = 0;
    while (getline(fs, text)) {
        Reis reis;
        reis = readReas(text);
        if (stoi(reis.height) > 2) {
            textFile += text + "\n";
        }
    }
    fs.close();
    std::cout << "Введите имя нового файла: ";
    std::cin >> fileNews;

    fs.open("file/" + fileNews, std::fstream::in | std::fstream::out | std::fstream::app);
    fs << textFile;
    fs.close();
}