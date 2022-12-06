#pragma once
#include "MonthRecord.h"
#include <vector>
class MonthlyReport
{
private:
	std::vector<MonthRecord*> income;
	std::vector<MonthRecord*> outcome;
public:
	MonthlyReport() {

	}
	void addRecord(std::string str) {
		std::vector<std::string> array = splitString(str, ',');
		if (array[1] == "TRUE")
			outcome.push_back(new MonthRecord(array[0], array[2], array[3]));
		else if (array[1] == "FALSE")
			income.push_back(new MonthRecord(array[0], array[2], array[3]));
	}
private:
	std::vector<std::string> splitString(std::string str, char sep) {
		std::string buf = "";
		std::vector<std::string> array;
		for (int i = 0; str[i] != '\n' || str[i] != '\0'; i++) {
			if (str[i] == sep) {
				array.push_back(buf);
				buf = "";
			}
			else buf += str[i];
		}
		return array;
	}
	

	int getIncome();
	int getOutcome();
	void showAll();
};

