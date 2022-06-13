#include <string>
#include <iostream>
static bool checkNumberConsole(std::string str) {
	bool IsBreak = true;
	for (int i = 0; str[i] != '\0'; i++) //как вариант можно использовать i<strlen(str) в условии цикла
		if (str[i] < 48 || str[i]>57) { 
			IsBreak = false; 
			break; 
		}
	return IsBreak;
}