#pragma once

/**
* Author: Tim Jäger
* Email: tim.jager2001@gmail.com
* 
* Content:
*	Activity class definition
* 
* Dependencies:
*	- iostream
*	- TJ
* 
* Activity is a class that is used to store any karate activities one partakes in, but is general enough
* to be reused for most activities in general.
* This class keeps track of the following details:
*	- description: this stores what the activity was about
*	- location: this is where the activity took place
*	- date: this is the date on which the activity took place
*	- organizer: this is the person or organization that was responsible for the activity
* 
*/

#include <iostream>
#include "TJ.h"

class Activity {
private:
	/* Private variables */
	std::string description;
	std::string location;
	TJ::simpleDate date;
	std::string organizer;

public:
	/* Constructors and destructors */
	Activity();
	Activity(std::string description, std::string location, TJ::simpleDate date, std::string organizer);
	~Activity();

	/* Getters and setters */
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

