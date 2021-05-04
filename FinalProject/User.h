#pragma once

/**
* Author: Tim Jäger
* E-Mail: tim.jager2001@gmail.com
* 
* Description:
*	This file contains a user class, used to store
*	the details of a karate practitioner.
* 
* External dependencies:
*	- iostream
*	- ctime
*	- Vector
*	- iomanip
*	- string
* 
* User-defined dependencies:
*	- TJ (namespace)
*	- Activity
*	- Rank
*/

#include <iostream>
#include "TJ.h"

#include <ctime>
#include <vector>
#include <iomanip>
#include <string>
#include "Activity.h"
#include "Rank.h"

class User {
private:
	static long count; // Amount of users that have been initialized
	long UUID; // This is set during the object initialization, hence the set function is private
	std::string name; // This is the users real name, first and last name
	TJ::simpleDate dob; // Date of birth
	Rank rank; // The karate rank, in our style this is a set of every rank you ever got, see Rank.h for details
	std::vector<Activity> activities; // This stores all mandatory/voluntary karate activities
	
	/* Private getters and setters */
	void setUUID(long UUID);
public:
	User();
	User(std::string name, long clubID, TJ::simpleDate dob); // New practitioners have no rank, so this sets an empty rank
	User(std::string name, long clubID, TJ::simpleDate dob, Rank rank, std::vector<Activity> activities);

	~User(); // This is currently the default destructor
		
	/* Getters and setters */
	long getUUID(); // Only getter is public for the afore mentioned reason

	void setName(std::string name);
	std::string getName();

	void setDob(TJ::simpleDate dob);
	TJ::simpleDate getDob();

	void setRank(Rank rank);
	void giveRank(RankEntry rankEntry); // giveRank(...) adds a rank to the list
	void giveRank(RankEnum rank, std::string examiner);
	void giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner);
	Rank getRank();

	void setActivities(std::vector<Activity> activities);
	void addActivity(Activity activity); // This adds an activity to the list
	std::vector<Activity> getActivities();
};