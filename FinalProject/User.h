#pragma once

/**
* Dependencies:
*	- iostream
*	- TJ
*	- ctime
*	- Vector
*	- Activity
*/

#include <iostream>
#include "TJ.h"

#include <ctime>
/*#include <time.h>
#include <stdio.h>*/
#include <vector>
#include "Activity.h"

class User {
private:
	static long count; // Amount of users that have been initialized
	long UUID;

	std::string name;

	long clubID;
	std::string clubName;

	long bondCode;
	TJ::simpleDate registrationDate;

	long insuranceCode;

	TJ::simpleDate dob; // Date of birth

	//Rank rank;

	std::vector<Activity> activities;
public:
	User();
	User(std::string name, TJ::simpleDate registrationDate, TJ::simpleDate dob);

	~User();
};