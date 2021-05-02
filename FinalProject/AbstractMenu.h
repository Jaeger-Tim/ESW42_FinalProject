#pragma once

/*
* __________
* \        /
*  \      /
*   \    /
*    \  /		Add a delete for the item vertor, items are created with the "new" method
*     \/
*	+----+
*   |    |
*   +----+
*/


#include <iostream>
#include <map>
#include <vector>

class Menu {
public:
	class AbstractItem {
	private:
		std::string name;
		std::string description;
	public:
		enum class ItemType { fuction = 0, object = 1 };

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

		void run() override { storedFunction();	}

		void setContent(void (*func)()) { storedFunction = func; }
	};

private:
	std::string title;
	//std::vector<std::unique_ptr<Menu::AbstractItem>> options;
	std::map<std::string, std::unique_ptr<Menu::AbstractItem>> options;

	//std::vector<AbstractItem> Choices;
public:
	Menu();
	~Menu();

	void addChoice(std::string name, std::string description, void (*func)());
	void display();
};