#include <iostream>

#include "TJ.h" // TJ namespace

#include"AbstractMenu.h"
#include <string>

int main() {

	/*void f() {
		std::cout << "!!!I RAN!!!";
	}*/

	Menu menu;
	menu.addChoice("A", "Some description", []() {std::cout << "!!! I did it !!!" << "\n";});
	menu.display();

	return 0;
}