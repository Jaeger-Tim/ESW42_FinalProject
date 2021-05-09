#pragma once

#include <iostream>
#include "TJ.h"

#include <map>
#include <vector>

#include <functional>

/**
* This class is an interactive menu.
* It stores options (ie. functions or other menus) and can display and run them.
* The menu will look as follow:
* 
* ==================================================
* Title
* --------------------------------------------------
* [1] Description for 1
* [A] Description for A
* [OTHER] Description for OTHER
* ==================================================
* // You can then type here your answer
* 
**/
class Menu {
public:
	// These classes are defined in Menu to avoid to need to maintain backwards compatibility whenever the Menu class is updated

	/**
	* All options in the Menu are stored in so "items". These contain all needed details, like
	* its description, a function to execute its content and a function to get its content
	* 
	* As items can store different things like other menus and functions there is an abstract item class
	* and some derived classes which contain the specifics. These derived classes their content can be identified
	* by calling the "content()" function.
	**/
	class AbstractItem {
	private:
		std::string description; // This contains a description of the content, which the menu class uses to dislay info

	public:
		// To make the content type clearer there is an enumerator, this has little to no other impact
		enum class ItemType { fuction = 0, menu = 1 };

		/* Getters and setters */
		void setDescription(std::string description);
		std::string getDescription();

		/* Pure virtual functions */
		virtual ItemType content() = 0; // Function to identify the content type
		virtual void run() = 0; // This executes the centent, ie. a function will be executed or a menu will be shown
	};

	/**
	* This is the derived class from "AbstractItem" that stores functions.
	**/
	class FunctionItem : public AbstractItem {
	private:
		std::function<void(void)> storedFunction;

	public:
		ItemType content() override { return ItemType::fuction; }

		void run() override { storedFunction(); }

		void setContent(std::function<void(void)> func) { storedFunction = func; }
	};

	/**
	* This is the derived class from "AbstractItem" that stores menus.
	**/
	class MenuItem : public AbstractItem {
	private:
		Menu* menu;

	public:
		ItemType content() override { return ItemType::menu; }

		void run() override { this->menu->display(); }

		void setContent(Menu* menu) { this->menu = menu; }
	};

private:
	std::string title; // The title of the meny that will be displayed
	std::map<std::string, std::unique_ptr<Menu::AbstractItem>> options; // This stores all options the menu will show

public:

	/* Getters and setters */
	void setTitle(std::string title);
	std::string getTitle();

	/* Other functions */
	void addChoice(std::string name, std::string description, std::function<void(void)> func); // Function to add a function as option
	void addChoice(std::string name, std::string description, Menu* menu); // Function to add a menu as option
	
	void display(); // Function to display the meny in the console. It has an interface, making it also handle the option selection and execution.
};