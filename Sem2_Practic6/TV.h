#pragma once
#include<iostream>
#include<string>
class TV
{
private:
	std::string _model;
	int _displaySize;
	bool _hasWifi;
	void init(std::string model, int displaySize, bool hasWifi);
	
public:
	TV(std::string model = "Unknown", int displaySize = 20, bool hasWifi = false);
	TV(const TV& tv);

	std::string print();
	void setModel(std::string model);
};
 
std::ostream& operator<< (std::ostream& os, TV& person);
TV* createTV();
