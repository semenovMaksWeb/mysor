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
using namespace std;
static struct News
{
    std::string Name;
    std::string  Autor;
    std::string  Text;
};
static std::string  filename = "news.txt";
static void saveNews() {
    system("cls");
    static News news;
    cin.ignore();
    std::cout << "Название новости:";
    getline(std::cin, news.Name);
    std::cout << "Автор новости:";
    getline(std::cin, news.Autor);
    std::cout << "Текст новости:";
    getline(std::cin, news.Text);
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app); //параметры на считывания и записи и отмена перезаписи
    fs << "\n" << news.Name   << ";" << news.Autor << ";" << news.Text;
    fs.close(); // закрыть файл
}

static void loadFileName()
{
    std::string text;
    std::fstream fs;
    int count = 0;
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    std::cout << std::setw(4) << "№|" <<  setw(20) << "Название новости \n";

    while (getline(fs, text)) {
        count++;
        News news;
        std::size_t posName = text.find(";");
        news.Name = text.substr(0, posName);
        cout << setw(3) << count << "|" << setw(20) << news.Name << "\n";
    }
    fs.close(); // закрыть файл

}



static void DeleteFileIndex(std::string index)
{
    system("cls");
    std::string textFile;
    std::string text;
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    int count = 0;
    while (getline(fs, text)) {
        count++;
        std::cout << count << "\n";
        std::cout << index << "\n";
        if (std::to_string(count) != index) {
            textFile = textFile + text + "\n";
        }

    }
    std::cout << textFile << "\n";
    fs.close();
    fs.open(filename, std::ios::out);
    fs << textFile;
    fs.close(); 

}




static void loadFileFullIndex(std::string index)
{
    system("cls");
    std::string text;
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    int count = 0;
    while (getline(fs, text)) {
        count++;
        if (std::to_string(count) == index) {
            News news;
            std::size_t posName = text.find(";");
            news.Name = text.substr(0, posName);
            std::cout << "Название новости" << news.Name << "\n";
            string text2 = text.substr(posName + 1, text.length());
            std::size_t posAutor = text2.find(";");
            news.Autor = text2.substr(0, posAutor);
            std::cout << "Автор новости: " << news.Autor << "\n";
            string text3 = text2.substr(posAutor + 1, text2.length());
            news.Text = text3;
            std::cout << "Текст новости\n";
            std::cout << news.Text << "\n";

        }
    }
    fs.close(); // закрыть файл

}