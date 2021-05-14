#pragma once

/**
* Author: Tim Jäger
* Email: tim.jager2001@gmail.com
*
* Content:
*	- RankEnum (enum)
*	- RankEntry (struct)
*	- Rank (class)
*
* Dependencies:
*	- iostream
*	- vector
*
*	- TJ
*
* RankEnum: this is a list of all available karate ranks in the right order.
*
* RankEntry: this is a struct that stores what rank has been obtained when and under whos supervision.
* 
* Rank: this is a class that keeps track of all ranks anyone has ever obtained and provides basic
* interaction with the list. It also has a function to convert RankEnum to a human readable format
* and has a stream operator.
*/

#include <iostream>
#include "TJ.h"

#include <vector>


/* Enumerators */
enum class RankEnum {
	noRank = 0, candidateB = 1, candidateA,
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

/* Structures */
struct RankEntry {
	RankEnum rank;
	TJ::simpleDate date;
	std::string examiner;
};


/* Classes */
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

	/* Operator overloading */
	Rank operator+(const Rank& rank);

	friend std::ostream& operator<<(std::ostream& os, const Rank& rank);
};

std::ostream& operator<<(std::ostream& os, const Rank& rank);