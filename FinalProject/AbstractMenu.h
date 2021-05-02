#pragma once

#include <iostream>
#include <vector>

class AbstractMenu {
private:
	std::string title;

	class Item {
	private:

	public:
		Item();
		~Item();

		int run();
		int display();
	};

	std::vector<Item> Choices;
public:
	AbstractMenu();
	~AbstractMenu();

	AbstractMenu& addChoice();
	AbstractMenu& display();
};