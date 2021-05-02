#ifndef TJ_H    // To prevent multiple instatiations
#define TJ_H

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