#include <iostream>

#include "TJ.h" // TJ namespace

#include <string>
#include <vector>
#include <functional>

#include"Menu.h"
#include "User.h"
#include "TJUserFunctions.h"
#include "Attendance.h"

int main() {
	/* Variable declarations*/
	std::vector<User> users;
	std::vector<AttendanceStruct> attendance;

	// Menus
	Menu manageUsersMenu;
	Menu mainMenu;
	Menu attendanceMenu;

	/* Menu setup */
	mainMenu.setTitle("Main menu");
	mainMenu.addChoice("1", "Manage users", &manageUsersMenu);
	mainMenu.addChoice("2", "Attendance", [&]() { getAttendance(attendance, users); mainMenu.display(); }); // after the attendance function is run, start a new mainMenu
	mainMenu.addChoice("EXIT", "", []() {}); // If nothing happens, no new menu is shown and you just exit the menu

	manageUsersMenu.setTitle("Manage users");
	manageUsersMenu.addChoice("1", "List all users", [&]() { TJ::listUsers(users); manageUsersMenu.display(); });
	manageUsersMenu.addChoice("2", "Create a user", [&]() { users.push_back(TJ::createUser()); manageUsersMenu.display(); });
	manageUsersMenu.addChoice("3", "Delete a user", [&]() { TJ::deleteUser(users); manageUsersMenu.display(); });
	manageUsersMenu.addChoice("CANCEL", "", &mainMenu);
	manageUsersMenu.addChoice("EXIT", "", []() {});

	/* Run the program, just a menu in this case */
	mainMenu.display();

	return 0;
}