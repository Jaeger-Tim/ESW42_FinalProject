#include "TJ.h"

namespace TJ {
	void ignore() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void clearScreen(void) {
		std::cout << std::string(50, '\n');
	}

	void breakSection(void) {
		std::cout << std::string(50, '-') << std::endl;
	}

	void breakSection(char sign) {
		breakSection(1, sign);
	}

	void breakSection(int lines, char sign) {
		breakSection(lines, 50, sign);
	}

	void breakSection(int lines, int width, char sign) {
		for (int i{ 0 }; i < lines; i++)
			std::cout << std::string(width, sign) << std::endl;
	}
}