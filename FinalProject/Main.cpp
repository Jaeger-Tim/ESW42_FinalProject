#include <iostream>

#include "TJ.h" // TJ namespace

//#include "MainMenu.h"
#include "User.h"
#include <string>

int main() {
	//MainMenu menu;
	//menu.run();

	User user1;
	std::cout << user1.getActivities().size() << " | " << user1.getClubID() << " | " << user1.getDob().day << " | " << user1.getDob().month << " | " << user1.getDob().year << " | " << user1.getName() << " | " << user1.getRank().getRankLog().size() << " | " << user1.getUUID() << std::endl;

	User user2("Tim Jaeger", 1010, {2, 4, 2001});
	std::cout << user2.getActivities().size() << " | " << user2.getClubID() << " | " << user2.getDob().day << " | " << user2.getDob().month << " | " << user2.getDob().year << " | " << user2.getName() << " | " << user2.getRank().getRankLog().size() << " | " << user2.getUUID() << std::endl;

	Rank rank3;
	rank3.giveRank(RankEnum::kyu2, "My favorite examiner");
	User user3("Tim Jaeger", 1010, { 2, 4, 2001 }, rank3, {Activity()});
	std::cout << user3.getActivities().size() << " | " << user3.getClubID() << " | " << user3.getDob().day << " | " << user3.getDob().month << " | " << user3.getDob().year << " | " << user3.getName() << " | " << user3.getRank().getRankLog().size() << " | " << user3.getUUID() << std::endl;

	User user4;
	user4.setActivities({Activity(), Activity()});
	user4.addActivity(Activity("Activity description", "It's location", {9, 6, 1966}, "VKF"));
	user4.setClubID(1930);
	user4.setDob({25, 2, 1966});
	user4.setName("Tom");
	user4.setRank(Rank());
	user4.giveRank(RankEnum::shodan, "Other instructor");
	user4.setUUID(9999);
	std::cout << user4.getActivities().size() << " | " << user4.getClubID() << " | " << user4.getDob().day << " | " << user4.getDob().month << " | " << user4.getDob().year << " | " << user4.getName() << " | " << user4.getRank().getRankLog().size() << " | " << user4.getUUID() << std::endl;
	return 0;
}