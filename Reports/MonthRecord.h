#pragma once
#include <iostream>
#include <string>
class MonthRecord
{
private:
	std::string itemName;
	int quantity;
	double sumOfOne;
public:
	MonthRecord(std::string itemName, std::string quantity, std::string sumOfOne) {
		this->itemName = itemName;
		this->quantity = stoi(quantity);
		this->sumOfOne = stod(sumOfOne);
	}
};

