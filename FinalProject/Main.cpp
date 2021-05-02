#include <iostream>

#include "TJ.h" // TJ namespace

//#include "MainMenu.h"
#include "Rank.h"
#include <string>

int main() {
	//MainMenu menu;
	//menu.run();

	Rank rank;
	for (int i = 0; i < 10; i++) {
		std::string instr = "MyInstructor";
		instr += std::to_string(i);
		rank.giveRank((RankEnum)i, instr);
	}

	for(RankEntry rankI : rank.getRankLog()) {
		std::cout << (int)rankI.rank << "\t" << rankI.examiner << "\t" << rankI.date.day << "\t" << rankI.date.month << "\t" << rankI.date.year << std::endl;
	}

	std::cout << std::endl << std::endl;

	Rank rank2;
	for (int i = 0; i < 10; i++) {
		std::string instr = "MyInstructor";
		instr += std::to_string(i);
		rank2.giveRank((RankEnum)i, {((int)(1.3*(1+i))), i+5, 10*i+1950}, instr);
	}

	for (RankEntry rankI2 : rank2.getRankLog()) {
		std::cout << (int)rankI2.rank << "\t" << rankI2.examiner << "\t" << rankI2.date.day << "\t" << rankI2.date.month << "\t" << rankI2.date.year << std::endl;
	}

	return 0;
}