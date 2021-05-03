#pragma once

/**
* Dependencies:
*	- iostream
*	- TJ
*	- ctime
*	- Vector
*	- Activity
*	- Rank
*/

#include <iostream>
#include "TJ.h"

#include <ctime>
#include <vector>
#include <iomanip>
#include "Activity.h"
#include "Rank.h"

class User {
private:
	static long count; // Amount of users that have been initialized
	long UUID;

	std::string name;

	long clubID;

	TJ::simpleDate dob; // Date of birth

	Rank rank;

	std::vector<Activity> activities;
public:
	User();
	User(std::string name, long clubID, TJ::simpleDate dob);
	User(std::string name, long clubID, TJ::simpleDate dob, Rank rank, std::vector<Activity> activities);

	~User();

	void setUUID(long UUID);
	long getUUID();

	void setName(std::string name);
	std::string getName();

	void setClubID(long clugID);
	long getClubID();

	void setDob(TJ::simpleDate dob);
	TJ::simpleDate getDob();

	void setRank(Rank rank);
	void giveRank(RankEntry rankEntry);
	void giveRank(RankEnum rank, std::string examiner);
	void giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner);
	Rank getRank();

	void setActivities(std::vector<Activity> activities);
	void addActivity(Activity activity);
	std::vector<Activity> getActivities();
};

namespace TJ {
	User createUser();
	void listUsers(std::vector<User> users);
}