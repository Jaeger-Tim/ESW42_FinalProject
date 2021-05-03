#include <iostream>

#include "TJ.h" // TJ namespace

#include"AbstractMenu.h"
#include <string>

int main() {
	Menu submenu;
	submenu.setTitle("Submenu");
	submenu.addChoice("Count", "Counting on you", []() { for (int i = 0; i < 10; i++) std::cout << i << std::endl; });

	Menu mainMenu;
	mainMenu.setTitle("Main menu");
	mainMenu.addChoice("A", "Some description", []() {std::cout << "!!! I did it !!!" << "\n"; });
	mainMenu.addChoice("HALLELUJAH", "This is line 2 and it works :)", []() {std::cout << "And for once I know why it works ;)" << "\n"; });
	mainMenu.addChoice("Next", "Yes, there are more menus.", &submenu);
	mainMenu.display();

	return 0;
}