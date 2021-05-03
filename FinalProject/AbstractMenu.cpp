#include "AbstractMenu.h"

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::setTitle(std::string title) {
	this->title = title;
}

std::string Menu::getTitle() {
	return this->title;
}

void Menu::addChoice(std::string name, std::string description, void(*func)()) {
	FunctionItem* item = new FunctionItem();
	item->setDescription(description);
	item->setContent(func);
	//this->options.push_back(item);
	//this->options.emplace_back(item);
	this->options.emplace(name, item);

}

void Menu::display() {
	TJ::clearScreen();
	TJ::breakSection('=');
	std::cout << this->getTitle() << std::endl;
	TJ::breakSection();
	for (auto& option : this->options) {
		std::cout << "[" << option.first << "] " << option.second->getDescription() << std::endl;
	}

	TJ::breakSection('=');

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

	this->options[choice]->run();
}

Menu::AbstractItem::AbstractItem() {
}

Menu::AbstractItem::~AbstractItem() {
}

void Menu::AbstractItem::setName(std::string name) {
	this->name = name;
}

std::string Menu::AbstractItem::getName() {
	return this->name;
}

void Menu::AbstractItem::setDescription(std::string description) {
	this->description = description;
}

std::string Menu::AbstractItem::getDescription() {
	return description;
}

//Menu::FunctionItem::FunctionItem() {
//}