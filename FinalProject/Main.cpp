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
	mainMenu.addChoice("1", "Manage users", &manageUsers);
	mainMenu.addChoice("EXIT", "", []() {});

	manageUsers.setTitle("Manage users");
	manageUsers.addChoice("1", "List all users", [&]() { TJ::listUsers(users); manageUsers.display(); });
	manageUsers.addChoice("2", "Create a user", [&]() { users.push_back(TJ::createUser()); manageUsers.display(); });
	manageUsers.addChoice("3", "Delete a user", [&]() { TJ::deleteUser(users); manageUsers.display(); });
	manageUsers.addChoice("4", "Edit user", [&]() { manageUsers.display(); });
	manageUsers.addChoice("EXIT", "", []() {});
	manageUsers.addChoice("MAIN", "", &mainMenu);

	createUser.setTitle("Create user");

	createUser.addChoice("Cancel", "", &mainMenu);

	mainMenu.display();

	return 0;
}