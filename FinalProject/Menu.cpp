#include "Menu.h"

/**
* Display the actual menu in the format:
*
* ==================================================
* Title
* --------------------------------------------------
* [1] Description for 1
* [A] Description for A
* [OTHER] Description for OTHER
* ==================================================
**/
void Menu::display() {

	/* Clear the screen and display the title */
	TJ::clearScreen();
	TJ::breakSection('=');

	std::cout << this->getTitle() << std::endl;

	TJ::breakSection();

	/* Loop through all options and display them */
	for (auto& option : this->options) {
		std::cout << "[" << option.first << "] " << option.second->getDescription() << std::endl;
	}

	TJ::breakSection('=');

	/* Get the users choise */
	std::string choice;

	bool valid = false;
	while (!valid) {
		std::cin >> choice;

		while (std::cin.fail()) {
			std::cin.clear(); // Reset the Cin flags
			std::cin.ignore(100, '\n'); // Clear the buffer
			std::cout << "Invalid input." << std::endl;
			std::cin >> choice;
		}

		if (this->options.find(choice) != this->options.end())
			valid = true;
		else
			std::cout << "Please choose one of the given options." << std::endl;
	}


	// Preform the option that the user chose
	this->options[choice]->run();
}

/* Getters and setters */

void Menu::setTitle(std::string title) {
	this->title = title;
}

std::string Menu::getTitle() {
	return this->title;
}

void Menu::AbstractItem::setDescription(std::string description) {
	this->description = description;
}

std::string Menu::AbstractItem::getDescription() {
	return description;
}

void Menu::addChoice(std::string name, std::string description, std::function<void(void)> func) {
	FunctionItem* item = new FunctionItem();
	item->setDescription(description);
	item->setContent(func);
	this->options.emplace(name, item);

}

void Menu::addChoice(std::string name, std::string description, Menu* menu) {
	MenuItem* item = new MenuItem();
	item->setDescription(description);
	item->setContent(menu);
	this->options.emplace(name, item);
}