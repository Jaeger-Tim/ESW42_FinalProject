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
	candidateB, candidateA,
	kyu9,
	candidateKyu8, kyu8, advancedKyu8,
	candidateKyu7, kyu7, advancedKyu7,
	candidateKyu6, kyu6, advancedKyu6,
	candidateKyu5, kyu5, advancedKyu5,
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

	void giveRank(RankEnum rank, std::string examiner);
	void giveRank(RankEnum rank, TJ::simpleDate date, std::string examiner);
	
	void setRankLog(std::vector<RankEntry> rankLog);
	std::vector<RankEntry> getRankLog();
};