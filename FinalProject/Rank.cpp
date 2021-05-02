#include "Rank.h"

Rank::Rank() {
	this->rankLog = {};
}

Rank::~Rank() {
}

void Rank::giveRank(RankEnum rank, std::string examiner) {
	struct tm currentDate;
	time_t now = time(0);
	localtime_s(&currentDate, &now);

	this->giveRank(rank, {currentDate.tm_mday, currentDate.tm_mon + 1, currentDate.tm_year+1900}, examiner);
}

void Rank::giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner) {
	this->rankLog.push_back({ rank, date, examiner });
}

void Rank::setRankLog(std::vector<RankEntry> rankLog) {
	this->rankLog = rankLog;
}

std::vector<RankEntry> Rank::getRankLog() {
	return this->rankLog;
}
