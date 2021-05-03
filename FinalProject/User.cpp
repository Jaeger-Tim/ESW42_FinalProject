#include "User.h"

long User::count = 0;

User::User() {
	User::count++;
	UUID = User::count;
	this->clubID = 0;
	this->name = "Unnamed";
	this->dob = { 1,1,1 };
}

User::User(std::string name, long clubID, TJ::simpleDate dob) {
	User::count++;
	this->UUID = User::count;
	this->name = name;
	this->clubID = clubID;
	this->dob = dob;
	this->rank = Rank();
	this->activities = {};
}

User::User(std::string name, long clubID, TJ::simpleDate dob, Rank rank, std::vector<Activity> activities) {
	User::count++;
	this->UUID = User::count;
	this->name = name;
	this->clubID = clubID;
	this->dob = dob;
	this->rank = rank;
	this->activities = activities;
}

User::~User() {
}

void User::setUUID(long UUID) {
	this->UUID = UUID;
}

long User::getUUID() {
	return this->UUID;
}

void User::setName(std::string name) {
	this->name = name;
}

std::string User::getName() {
	return this->name;
}

void User::setClubID(long clubID) {
	this->clubID = clubID;
}

long User::getClubID() {
	return this->clubID;
}

void User::setDob(TJ::simpleDate dob) {
	this->dob = dob;
}

TJ::simpleDate User::getDob() {
	return this->dob;
}

void User::setRank(Rank rank) {
	this->rank = rank;
}

void User::giveRank(RankEntry rankEntry) {
	this->rank.giveRank(rankEntry);
}

void User::giveRank(RankEnum rank, std::string examiner) {
	this->rank.giveRank(rank, examiner);
}

void User::giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner) {

	this->rank.giveRank(rank, date, examiner);
}

Rank User::getRank() {
	return this->rank;
}

void User::setActivities(std::vector<Activity> activities) {
	this->activities = activities;
}

void User::addActivity(Activity activity) {
	this->activities.push_back(activity);
}

std::vector<Activity> User::getActivities() {
	return activities;
}

User TJ::createUser() {
	User user;
	std::string tmp;
	TJ::breakSection('=');
	std::cout << "Name: ";

	std::cin >> tmp;

	while (std::cin.fail()) {
		std::cin.clear(); // Reset the Cin flags
		std::cin.ignore(100, '\n'); // Clear the buffer
		std::cout << "Invalid input!" << std::endl;
		std::cin >> tmp;
	}

	user.setName(tmp);
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
