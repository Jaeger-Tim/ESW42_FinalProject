#pragma once

/**
* Dependencies:
*	- iostream
*	- TJ
*/

#include <iostream>
#include "TJ.h"

class Activity {
private:
	std::string description;
	std::string location;
	TJ::simpleDate date;
	std::string organizer;
public:
	Activity();
	Activity(std::string description, std::string location, TJ::simpleDate date, std::string organizer);
	~Activity();

	void setDescription(std::string description);
	std::string getDescription();

	void setLocation(std::string location);
	std::string getLocation();

	void setDate(TJ::simpleDate date);
	void setDate(int day, int month, int year);
	TJ::simpleDate getDate();

	void setOrganizer(std::string organizer);
	std::string getOrganizer();
};

