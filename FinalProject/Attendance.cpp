#include "Attendance.h"

void getAttendance(std::vector<AttendanceStruct>& attendance, std::vector<User>& users) {
	std::vector<User> tmpUsers; // This is used to list all users with that same name that is selected
	std::string name; // This stores the name of the user that has been chosen
	int choice; // This will store the index in the temporary array of the selected user

	/* Get the name */
	TJ::clearScreen();
	TJ::breakSection('=');
	std::cout << "Name (or anything to cancel): ";
	TJ::ignore();
	std::getline(std::cin, name);

	/* Store all users with the chosen name in the tmpUsers vector */
	for (User user : users)
		if (user.getName() == name)
			tmpUsers.push_back(user);

	/* Show a list of all users that fit the chosen name and the cancel option */
	TJ::breakSection();

	if (tmpUsers.size() > 0)
		for (int i{ 0 }; i < tmpUsers.size(); i++)
			if (tmpUsers.at(i).getName() == name)
				std::cout << "[" << i << "] " << tmpUsers.at(i).getName() << "\t" << ((tmpUsers.at(i).getRank().getRankLog().size() > 0) ? (Rank::toString(tmpUsers.at(i).getRank().getRankLog().back().rank)) : "") << "\t" << tmpUsers.at(i).getUUID() << std::endl;
	std::cout << "[-1] CANCEL" << std::endl;

	TJ::breakSection('=');

	/* Get the chosen user from the previously generated list */
	std::cin >> choice;

	while (std::cin.fail() || ((choice < -1 || choice >= tmpUsers.size()) && choice != -1)) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input." << std::endl;
		std::cin >> choice;
	}

	/* Get the current date */
	struct tm currentDate;
	time_t now = time(0);
	localtime_s(&currentDate, &now);

	/* Go trough the temporary list and update the attendance list */
	bool match{ false };
	for (int i{ 0 }; i < attendance.size() && choice < tmpUsers.size(); i++) { // Look if the user has already been registered in the attendance list and add them if they were
		std::cout << "LOOP";
		if (attendance.at(i).userUUID == tmpUsers.at(choice).getUUID()) {
			std::cout << "IF";
			match = true;

			attendance.at(i).attendanceDays.push_back({ currentDate.tm_mday, currentDate.tm_mon + 1, currentDate.tm_year + 1900 });

			getAttendance(attendance, users);

			std::cout << "next attendance";

		}
	}
	if (match == false && choice != -1) { // If the user didn't find a match and there was no cancel instruction, add the user to the attendance list
		attendance.push_back({ tmpUsers.at(choice).getUUID(), {{ currentDate.tm_mday, currentDate.tm_mon + 1, currentDate.tm_year + 1900 }} });

		getAttendance(attendance, users);
	}
};