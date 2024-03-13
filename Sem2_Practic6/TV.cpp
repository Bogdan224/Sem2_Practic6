#include "TV.h"

TV::TV(std::string model, int displaySize, bool hasWifi) {
	init(model, displaySize, hasWifi);
}

TV::TV(const TV& tv) {
	init(tv._model, tv._displaySize, tv._hasWifi);
}

void TV::init(std::string model, int displaySize, bool hasWifi) {
	if (displaySize < 10 || displaySize > 200)
		throw std::invalid_argument("Display size have wrong value!\n");
	_model = model;
	_displaySize = displaySize;
	_hasWifi = hasWifi;
}
std::string TV::print() {
	if (this == nullptr) {
		throw std::invalid_argument("Tv is nullptr\n");
	}
	std::string res = "Model: ";
	res += _model;
	res += "\nDisplay size: ";
	res += std::to_string(_displaySize);
	res += "\nHas wifi: ";
	if (_hasWifi)
		res += "Yes";
	else
		res += "No";
	res += "\n";
	return res;
}
void TV::setModel(std::string model) {
	if (this == nullptr) {
		throw std::invalid_argument("Tv is nullptr\n");
	}
	_model = model;
}

std::ostream& operator<< (std::ostream& out, TV& person) {
	out << person.print();
	return out;
}

TV* createTV() {
	std::string model;
	int displaySize;
	int hasWifi;
	std::cout << "Enter model, display size and has wifi(1-yes, 0-no)\n";
	std::cin >> model >> displaySize >> hasWifi;
	try {
		TV* tv = new TV(model, displaySize, hasWifi);
		return tv;
	}
	catch(std::exception e){
		std::cout << e.what() << "\nWhat to do?\n1 - Enter new values\nelse - Return nullptr\n";
		int choise;
		std::cin >> choise;
		std::cout << std::endl;
		switch (choise)
		{
			case 1:
				return createTV();
		default:
			return nullptr;
		}
	}
}
