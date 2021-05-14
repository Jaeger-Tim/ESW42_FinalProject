#include "Rank.h"

/* Constructors and destructors */

Rank::Rank() {
	this->rankLog = {};
}

Rank::~Rank() {
}

/* Other functions */
void Rank::giveRank(RankEntry rankEntry) {
	this->rankLog.push_back(rankEntry);
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

std::string Rank::toString(RankEnum rank) {
	switch (rank) { // This list has to be hardcoded
		case RankEnum::noRank: return "no rank"; break;
		case RankEnum::candidateB: return "candidate B"; break;
		case RankEnum::candidateA: return "candidate A"; break;
		case RankEnum::kyu9: return "9th kyu"; break;
		case RankEnum::candidateKyu8: return "candidate 8th kyu"; break;
		case RankEnum::kyu8: return "8th kyu"; break;
		case RankEnum::advancedKyu8: return "advanced 8th kyu"; break;
		case RankEnum::candidateKyu7: return "candidate 7th kyu"; break;
		case RankEnum::kyu7: return "7th kyu"; break;
		case RankEnum::advancedKyu7: return "advanced 7th kyu"; break;
		case RankEnum::candidateKyu6: return "candidate 6th kyu"; break;
		case RankEnum::kyu6: return "6th kyu"; break;
		case RankEnum::advancedKyu6: return "advanced 6th kyu"; break;
		case RankEnum::candidateKyu5: return "candidate 5th kyu"; break;
		case RankEnum::kyu5: return "5th kyu"; break;
		case RankEnum::advancedKyu5: return "advanced 5th kyu"; break;
		case RankEnum::candidateKyu4: return "candidate 4th kyu"; break;
		case RankEnum::kyu4: return "4th kyu"; break;
		case RankEnum::candidateKyu3: return "candidate 3rd kyu"; break;
		case RankEnum::kyu3: return "3rd kyu"; break;
		case RankEnum::candidateKyu2: return "candidate 2nd kyu"; break;
		case RankEnum::kyu2: return "2nd kyu"; break;
		case RankEnum::candidateKyu1: return "candidate 1st kyu"; break;
		case RankEnum::kyu1: return "1st kyu"; break;
		case RankEnum::shodan: return "shodan"; break;
		case RankEnum::nidan: return "nidan"; break;
		case RankEnum::sandan: return "sandan"; break;
		case RankEnum::yondan: return "yondan"; break;
		case RankEnum::godan: return "godan"; break;
		case RankEnum::rokudan: return "rokudan"; break;
		case RankEnum::nanadan: return "nanadan"; break;
		case RankEnum::hachidan: return "hachidan"; break;
		case RankEnum::kyudan: return "kyudan"; break;
		case RankEnum::judan: return "judan"; break;
		default: return "No existing rank"; break;
	}
}

/* Getters and setters */

void Rank::setRankLog(std::vector<RankEntry> rankLog) {
	this->rankLog = rankLog;
}

std::vector<RankEntry> Rank::getRankLog() {
	return this->rankLog;
}

/* Operator overloading */

Rank Rank::operator+(const Rank& rank) {
	Rank tempRank;
	std::vector<RankEntry> tempRankLog;
	
	tempRankLog.insert(tempRankLog.end(), rank.rankLog.begin(), rank.rankLog.end());
	tempRankLog.insert(tempRankLog.end(), this->rankLog.begin(), this->rankLog.end());
	
	tempRank.setRankLog(tempRankLog);

	return tempRank;
}

std::ostream& operator<<(std::ostream& os, const Rank& rank) {
	os << Rank::toString(rank.rankLog.at(rank.rankLog.size()-1).rank);

	return os;
}