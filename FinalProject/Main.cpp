#include <iostream>

#include "TJ.h" // TJ namespace

//#include "MainMenu.h"
#include "Activity.h"

int main() {
	//MainMenu menu;
	//menu.run();

	Activity activity;
	std::cout << activity.getDate().day << " | " << activity.getDate().month << " | " << activity.getDate().year << " | " << activity.getDescription() << " | " << activity.getLocation() << " | " << activity.getOrganizer() << std::endl;
	
	Activity activity2("Some description", "Not nowhere", { 02,04,2001 }, "Someone");
	std::cout << activity2.getDate().day << " | " << activity2.getDate().month << " | " << activity2.getDate().year << " | " << activity2.getDescription() << " | " << activity2.getLocation() << " | " << activity2.getOrganizer() << std::endl;
	
	Activity activity3;
	activity3.setDescription("Some other description");
	activity3.setLocation("Anywhere");
	activity3.setDate({ 20, 9, 1921 });
	activity3.setOrganizer("A person");
	std::cout << activity3.getDate().day << " | " << activity3.getDate().month << " | " << activity3.getDate().year << " | " << activity3.getDescription() << " | " << activity3.getLocation() << " | " << activity3.getOrganizer();

	return 0;
}