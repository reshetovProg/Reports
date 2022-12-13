#pragma once
#include <iostream>
#include <string>
class YearRecord
{
	friend class YearlyReport;
	int month;
	double amount;
public:
	//YearRecord() {}
	YearRecord(std::string month, std::string amount) {
		this->month = stoi(month);
		this->amount = stod(amount);
	}
};

