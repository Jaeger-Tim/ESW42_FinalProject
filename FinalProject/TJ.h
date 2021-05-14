#ifndef TJ_H    // To prevent multiple instatiations
#define TJ_H

/**
* Author: Tim Jäger
* Email: tim.jager2001@gmail.com
*
* Content:
*	- simpleDate (struct)
* 
*	- ignore (function)
*	- clearScreen (function)
*	- breakSection (function)
*
* Dependencies:
*	- iostream
*
* simpleData: this is a struct that doesn't have any fancy things going on, simple a day, month and year as integers
* 
* ignore: this is a function that implements the std::cin.ignore function without having to type it everytime
* 
* clearScrean: this function prints 50 empty lines which virtually clears the screen
* 
* breakSection: this is a function with multiple different parameters, which is used to print one or more lines of the same characters
*/

#include <iostream>

namespace TJ {
	struct simpleDate {
		int day,
			month,
			year;
	};

	void ignore(void);
	void clearScreen(void); // Prints 50 empty lines, which virtually clears the screen
	void breakSection(void); // Print a line of 50 '-' signs
	void breakSection(char sign); // Print a line of 50 times the specified sign
	void breakSection(int lines, char sign); // Print an amount of lines using specific signs
	void breakSection(int lines, int width, char sign); // Print an amount of lines using a specific sign, with the option to choose the length
}

#endif