#include <iostream>

#include "TJ.h" // TJ namespace

#include <string>
#include <vector>
#include <functional>
//#include <string>

#include"Menu.h"
#include "User.h"
#include "TJUserFunctions.h"

struct AttendanceStruct {
	long userUUID;
	std::vector<TJ::simpleDate> attendanceDays;
};

int main() {
	/* Variable declarations*/
	std::vector<User> users;
	std::vector<AttendanceStruct> attendance;

	std::function<void()> getAttendance;

	// Menus
	Menu manageUsersMenu;
	Menu mainMenu;
	Menu attendanceMenu;

	/* Function definitions*/
	getAttendance = [&]() {
		std::vector<User> tmpUsers;
		std::string name;
		int choice;

		TJ::clearScreen();
		TJ::breakSection('=');
		std::cout << "Name (or anything to cancel): ";
		TJ::ignore();
		std::getline(std::cin, name);

		for (User user : users)
			if (user.getName() == name)
				tmpUsers.push_back(user);

		TJ::breakSection();

		if (tmpUsers.size() > 0)
			for (int i{ 0 }; i < tmpUsers.size(); i++)
				if (tmpUsers.at(i).getName() == name)
					std::cout << "[" << i << "] " << tmpUsers.at(i).getName() << "\t" << ((tmpUsers.at(i).getRank().getRankLog().size() > 0) ? (Rank::toString(tmpUsers.at(i).getRank().getRankLog().back().rank)) : "") << "\t" << tmpUsers.at(i).getUUID() << std::endl;
		std::cout << "[-1] CANCEL" << std::endl;

		TJ::breakSection('=');

		std::cin >> choice;

		while (std::cin.fail() || ((choice < -1 || choice >= tmpUsers.size()) && choice != -1 )) {
			std::cin.clear(); // Reset the Cin flags
			std::cin.ignore(100, '\n'); // Clear the buffer
			std::cout << "Invalid input." << std::endl;
			std::cin >> choice;
		}

		struct tm currentDate;
		time_t now = time(0);
		localtime_s(&currentDate, &now);

		bool match{ false };
		for (int i{ 0 }; i < attendance.size() && choice < tmpUsers.size(); i++) {
			std::cout << "LOOP";
			if (attendance.at(i).userUUID == tmpUsers.at(choice).getUUID()) {
				std::cout << "IF";
				match = true;

				attendance.at(i).attendanceDays.push_back({ currentDate.tm_mday, currentDate.tm_mon + 1, currentDate.tm_year + 1900 });

				getAttendance();

				std::cout << "next attendance";

			}
		}
		if (match == false && choice != -1) {
			attendance.push_back({ tmpUsers.at(choice).getUUID(), {{ currentDate.tm_mday, currentDate.tm_mon + 1, currentDate.tm_year + 1900 }} });

			getAttendance();
		}

	};

	/* Menu setup */
	mainMenu.setTitle("Main menu");
	mainMenu.addChoice("1", "Manage users", &manageUsersMenu);
	mainMenu.addChoice("2", "Attendance", [&]() {getAttendance(); mainMenu.display(); });
	mainMenu.addChoice("EXIT", "", []() {});

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