#include "Activity.h"

Activity::Activity() {
	this->description = "Unknown";
	this->location = "Unknown";
	this->date = { 0, 0, 0 };
	this->organizer = "Unknown";
}

Activity::Activity(std::string description, std::string location, TJ::simpleDate date, std::string organizer) {
	this->description = description;
	this->location = location;
	this->date = date;
	this->organizer = organizer;
}

Activity::~Activity() {
}

void Activity::setDescription(std::string description) {
	this->description = description;
}

std::string Activity::getDescription() {
	return this->description;
}

void Activity::setLocation(std::string location) {
	this->location = location;
}

std::string Activity::getLocation() {
	return this->location;
}

void Activity::setDate(TJ::simpleDate date) {
	this->date = date;
}

void Activity::setDate(int day, int month, int year) {
	this->date = { day, month, year };
}

TJ::simpleDate Activity::getDate() {
	return this->date;
}

void Activity::setOrganizer(std::string organizer) {
	this->organizer = organizer;
}

std::string Activity::getOrganizer() {
	return this->organizer;
}
