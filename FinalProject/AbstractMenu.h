#pragma once

/*
* __________
* \        /
*  \      /
*   \    /
*    \  /		Add a delete for the item vertor and menu pointer, items are created with the "new" method
*     \/
*	+----+
*   |    |
*   +----+
*/

#include <iostream>
#include "TJ.h"

#include <map>
#include <vector>

class Menu {
public:
	class AbstractItem {
	private:
		std::string name;
		std::string description;
	public:
		enum class ItemType { fuction = 0, menu = 1 };

		AbstractItem();
		~AbstractItem();

		void setName(std::string name);
		std::string getName();

		void setDescription(std::string description);
		std::string getDescription();

		virtual ItemType content() = 0;
		virtual void run() = 0; // A function will be executed; a menu will be shown
	};

	class FunctionItem : public AbstractItem {
	private:
		void (*storedFunction) ();
	public:
		//FunctionItem() : AbstractItem() {}

		ItemType content() override { return ItemType::fuction; }

		void run() override { storedFunction(); }

		void setContent(void (*func)()) { storedFunction = func; }
	};

	class MenuItem : public AbstractItem {
	private:
		Menu* menu;
	public:
		//FunctionItem() : AbstractItem() {}

		ItemType content() override { return ItemType::menu; }

		void run() override { this->menu->display(); }

		void setContent(Menu* menu) { this->menu = menu; }
	};

private:
	std::string title;
	//std::vector<std::unique_ptr<Menu::AbstractItem>> options;
	std::map<std::string, std::unique_ptr<Menu::AbstractItem>> options;

	//std::vector<AbstractItem> Choices;
public:
	Menu();
	~Menu();

	void setTitle(std::string title);
	std::string getTitle();
	void addChoice(std::string name, std::string description, void (*func)());
	void addChoice(std::string name, std::string description, Menu* menu);
	void display();
};