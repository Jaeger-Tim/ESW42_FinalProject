#include "User.h"

long User::count = 0; // On launch, initialize the usercount

/* Constructors and destructor */

User::User() {
	User::count++;		// Everytime the constructor is called, this increases, therefore counting the
	UUID = User::count;	// instances created and ensuring that the UUID stays unique
	this->name = "Unnamed";
	this->dob = { 1,1,1 };
}

User::User(std::string name, long clubID, TJ::simpleDate dob) {
	User::count++;
	this->UUID = User::count;
	this->name = name;
	this->dob = dob;
	this->rank = Rank();
	this->activities = {};
}

User::User(std::string name, long clubID, TJ::simpleDate dob, Rank rank, std::vector<Activity> activities) {
	User::count++;
	this->UUID = User::count;
	this->name = name;
	this->dob = dob;
	this->rank = rank;
	this->activities = activities;
}

User::~User() {
}

/* Getters and setters and additive functions */

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