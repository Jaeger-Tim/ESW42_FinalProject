#include <iostream>

#include "TJ.h" // TJ namespace

#include"AbstractMenu.h"
#include <string>

int main() {

	Menu menu;
	menu.setTitle("Test menu");
	menu.addChoice("A", "Some description", []() {std::cout << "!!! I did it !!!" << "\n";});
	menu.addChoice("HALLELUJAH", "This is line 2 and it works :)", []() {std::cout << "And for once I know why it works ;)" << "\n"; });
	menu.display();

	return 0;
}