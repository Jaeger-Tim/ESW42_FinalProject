#include <iostream>

#include "TJ.h" // TJ namespace

#include <string>
#include <vector>
#include <functional>

#include"Menu.h"
#include "User.h"

int main() {
	std::vector<User> users;

	Menu createUser;
	Menu manageUsers;
	Menu mainMenu;

	mainMenu.setTitle("Main menu");
	mainMenu.addChoice("M", "Manage users", &manageUsers);
	mainMenu.addChoice("EXIT", "", []() {});

	manageUsers.setTitle("Manage users");
	manageUsers.addChoice("L", "List all users", [&]() { TJ::listUsers(users);  });
	manageUsers.addChoice("C", "Create a user", [&]() { users.push_back(TJ::createUser()); });
	manageUsers.addChoice("D", "Delete a user", &createUser);
	manageUsers.addChoice("E", "Edit user", &createUser);

	createUser.setTitle("Create user");

	createUser.addChoice("Cancel", "", &mainMenu);

	while (1) {
		mainMenu.display();
	}
	return 0;
}