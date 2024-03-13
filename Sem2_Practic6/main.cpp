#include"TV.h"

int main() {
	TV tv1 = TV(), tv2 = TV("Sony", 35, true);
	std::cout << tv1 << std::endl << tv2 << std::endl;
	TV tv3 = TV(tv2);
	std::cout << tv3 << std::endl;
	
	try {
	tv1.setModel("Samsung");
	}
	catch (std::exception e) {
		std::cout << e.what();
	}

	std::cout << tv1 << std::endl;

	TV* tv4 = createTV(), * tv5 = createTV();

	try {
		std::cout << *tv4 << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what();
	}

	try {
		std::cout << *tv5 << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what();
	}

	delete tv4, tv5;
	return 0;
}