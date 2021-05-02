#include <iostream>

#include "TJ.h" // TJ namespace

//#include "MainMenu.h"
#include "Activity.h"

int main() {
	//MainMenu menu;
	//menu.run();

	Activity activity("Some description", "Not nowhere", {02,04,2001}, "Someone");
	std::cout << activity.getDate().day << " | " << activity.getDate().month << " | " << activity.getDate().year << " | " << activity.getDescription() << " | " << activity.getLocation() << " | " << activity.getOrganizer();

	return 0;
}