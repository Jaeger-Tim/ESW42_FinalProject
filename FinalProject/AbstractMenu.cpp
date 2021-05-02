#include "AbstractMenu.h"

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::addChoice(std::string name, std::string description, void(*func)()) {
	FunctionItem item;
	item.setDescription(description);
	item.setContent(func);
	this->options.push_back(item);
}

void Menu::display() {
	/*for (auto& option : this->options) {
		std::cout << "[" << option.first << "] " << option.second.getDescription();
	}*/
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