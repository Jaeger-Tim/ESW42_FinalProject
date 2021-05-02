#include "MainMenu.h"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

int MainMenu::run() {
	/*
	* Returns code:
	* 0 - Code ran succesfully
	*/

	int choice = 0;

	while (choice == 0) {
		TJ::clearScreen();
		TJ::breakSection('=');
		std::cout << "Main menu" << std::endl;
		TJ::breakSection();
		std::cout << "[1] abcd" << std::endl;
		std::cout << "[2] hrhdd" << std::endl;
		std::cout << "[3] aeshsrh" << std::endl;
		std::cout << "[4] segsgd" << std::endl;
		TJ::breakSection('=');

		std::cin >> choice;
		while (std::cin.fail()) {
			std::cin.clear(); // Reset the Cin flags
			std::cin.ignore(100, '\n'); // Clear the buffer
			std::cout << "Please enter a number" << std::endl;
			std::cin >> choice;
		}

	}

	return 0;
}