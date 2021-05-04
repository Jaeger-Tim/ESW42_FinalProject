#pragma once

/**
* Dependencies:
*	- iostream
*	- TJ
*	- vector
*/

#include <iostream>
#include "TJ.h"

#include <vector>

enum class RankEnum {
	noRank=0, candidateB=1, candidateA,
	kyu9,
	candidateKyu8, kyu8, advancedKyu8,
	candidateKyu7, kyu7, advancedKyu7,
	candidateKyu6, kyu6, advancedKyu6,
	candidateKyu5, kyu5, advancedKyu5,
	candidateKyu4, kyu4,
	candidateKyu3, kyu3,
	candidateKyu2, kyu2,
	candidateKyu1, kyu1,
	shodan, nidan, sandan, yondan,
	godan, rokudan, nanadan, hachidan,
	kyudan, judan
};

struct RankEntry {
	RankEnum rank;
	TJ::simpleDate date;
	std::string examiner;
};

class Rank {
private:
	std::vector<RankEntry> rankLog;
public:
	Rank();
	~Rank();
	
	void giveRank(RankEntry rankEntry);
	void giveRank(RankEnum rank, std::string examiner);
	void giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner);
	
	static std::string toString(RankEnum rank);

	void setRankLog(std::vector<RankEntry> rankLog);
	std::vector<RankEntry> getRankLog();
};