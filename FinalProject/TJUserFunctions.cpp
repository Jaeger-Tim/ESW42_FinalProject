#include "TJUserFunctions.h"

User TJ::createUser() {
	User user;
	std::string tmpStr;

	TJ::breakSection('=');
	std::cout << "Name: ";
	TJ::ignore();
	std::getline(std::cin, tmpStr);
	user.setName(tmpStr);

	int tmpDay;
	std::cout << "Date of birth:\nDD: ";
	std::cin >> tmpDay;

	while (std::cin.fail()) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input." << std::endl;
		std::cin >> tmpDay;
	}

	int tmpMonth;
	std::cout << "MM: ";
	std::cin >> tmpMonth;

	while (std::cin.fail()) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input." << std::endl;
		std::cin >> tmpMonth;
	}

	int tmpYear;
	std::cout << "YYYY: ";
	std::cin >> tmpYear;

	while (std::cin.fail()) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input." << std::endl;
		std::cin >> tmpYear;
	}

	user.setDob({ tmpDay, tmpMonth, tmpYear });

	return user;
}

void TJ::listUsers(std::vector<User> users) {
	TJ::clearScreen();

	std::cout << std::setw(26) << "Name" << std::setw(19) << "Current rank" << std::setw(5) << "UUID" << std::endl;

	TJ::breakSection();

	for (User user : users) {
		std::cout << std::setw(26) << user.getName() << std::setw(19) << ((user.getRank().getRankLog().size() > 0) ? (Rank::toString(user.getRank().getRankLog().back().rank)) : "") << std::setw(5) << user.getUUID() << std::endl;
	}

	TJ::breakSection('=');

	std::cout << "Press enter to continue...";
	std::cin.ignore(100, '\n');
	std::getchar();
}

void TJ::deleteUser(std::vector<User>& users) {
	TJ::clearScreen();
	TJ::breakSection('=');
	std::cout << "User UUID: ";

	long UUID;
	std::cin >> UUID;

	while (std::cin.fail()) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input." << std::endl;
		std::cin >> UUID;
	}

	TJ::breakSection();

	std::cout << "Are you sure you want to delete this user:" << std::endl;
	std::cout << std::setw(26) << "Name" << std::setw(19) << "Current rank" << std::setw(5) << "UUID" << std::endl;

	User user;

	for (User tmpUser : users) {
		if (tmpUser.getUUID() == UUID) {
			std::cout << std::setw(26) << tmpUser.getName() << std::setw(19) << ((tmpUser.getRank().getRankLog().size() > 0) ? (Rank::toString(tmpUser.getRank().getRankLog().back().rank)) : "") << std::setw(5) << tmpUser.getUUID() << std::endl;
			user = tmpUser;
		}
	}

	TJ::breakSection();
	std::cout << "Type \"YES\" if you are sure: ";

	std::string tmpStr;
	TJ::ignore();
	std::getline(std::cin, tmpStr);

	std::string yesStr = "YES";
	if (tmpStr == yesStr) {
		for (int i = 0; i < users.size(); i++) {
			if (users.at(i).getUUID() == UUID) {
				users.erase(users.begin() + i);
				std::cout << "User has been removed" << std::endl;
			}
		}
	}

	TJ::breakSection('=');

	std::cout << "Press enter to continue..." << std::endl;
	TJ::ignore();
	std::getchar();
}