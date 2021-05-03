#pragma once

#include <iostream>
#include "TJ.h"

#include <map>
//#include <unordered_map>
#include <vector>

#include <functional>

class Menu {
public:
	class AbstractItem {
	private:
		std::string description;
	public:
		enum class ItemType { fuction = 0, menu = 1 };

		void setDescription(std::string description);
		std::string getDescription();

		virtual ItemType content() = 0;
		virtual void run() = 0; // A function will be executed; a menu will be shown
	};

	class FunctionItem : public AbstractItem {
	private:
		std::function<void(void)> storedFunction;

	public:
		ItemType content() override { return ItemType::fuction; }

		void run() override { storedFunction(); }

		void setContent(std::function<void(void)> func) { storedFunction = func; }
	};

	class MenuItem : public AbstractItem {
	private:
		Menu* menu;

	public:
		ItemType content() override { return ItemType::menu; }

		void run() override { this->menu->display(); }

		void setContent(Menu* menu) { this->menu = menu; }
	};

private:
	std::string title;
	std::map<std::string, std::unique_ptr<Menu::AbstractItem>> options;

public:
	void setTitle(std::string title);
	std::string getTitle();
	void addChoice(std::string name, std::string description, std::function<void(void)> func);
	void addChoice(std::string name, std::string description, Menu* menu);
	void display();
};