#pragma once
#include "YearRecord.h"
#include <vector>

class YearlyReport
{
private:
	std::vector <YearRecord>  income;
	std::vector <YearRecord> outcome;
public:
	YearlyReport(std::string str) {
		std::vector<std::string> array = splitString(str, '\n');
		for (int i = 1; i < array.size(); i++) {
			addRecord(array[i]);
		}

	}
	void addRecord(std::string str) {
		std::vector<std::string> array = splitString(str, ',');
		if (array[2] == "true")
			outcome.push_back(YearRecord(array[0], array[1]));
		else if (array[2] == "false")
			income.push_back(YearRecord(array[0], array[1]));
	}

	double getIncome() {
		double summ = 0;
		for (int i = 0; i < income.size(); i++) {
			summ += income[i].amount;
		}
		return summ;
	}

	double getIncome(int i) {
		return income[i].amount;
	}
	double getOutcome() {
		double summ = 0;
		for (int i = 0; i < outcome.size(); i++) {
			summ += outcome[i].amount;
		}
		return summ;
	}
	double getOutcome(int i) {
		return outcome[i].amount;
	}
	void showAll() {
		std::cout << "OUTCOME:" << std::endl;
		for (int i = 0; i < outcome.size(); i++) {
			std::cout << "month: " << outcome[i].month;
			std::cout << "   amount: " << outcome[i].amount << std::endl;

		}
		std::cout << std::endl;
		std::cout << "INCOME:" << std::endl;
		for (int i = 0; i < income.size(); i++) {
			std::cout << "month: " << income[i].month;
			std::cout << "   amount: " << income[i].amount << std::endl;
		}
	}
private:
	std::vector<std::string> splitString(std::string str, char sep) {
		std::string buf = "";
		std::vector<std::string> array;
		for (int i = 0; i <= str.size(); i++) {
			if (str[i] == sep || str[i] == '\0') {
				std::cout << buf << std::endl;
				array.push_back(buf);
				buf = "";
			}
			else buf += str[i];
		}
		return array;
	}

};

