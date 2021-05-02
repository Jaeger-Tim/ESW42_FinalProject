#include "User.h"

long User::count = 0;

User::User() {
	struct tm currentDate;
	time_t now = time(0);
	localtime_s(&currentDate, &now);

	User::count++;
	UUID = User::count + 1;
	this->name = "Unnamed";
	this->registrationDate = { currentDate.tm_year, currentDate.tm_mon + 1, currentDate.tm_mday };
	this->dob = { 1,1,1 };
}

User::User(std::string name, TJ::simpleDate registrationDate, TJ::simpleDate dob) {
	User::count++;
	this->UUID = User::count + 1;
	this->name = name;
	this->registrationDate = registrationDate;
	this->dob = dob;
}

User::~User() {
}