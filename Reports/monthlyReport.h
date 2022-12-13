#pragma once
//class MonthRecord;
//class MonthlyReport;
#include "MonthRecord.h"
#include <vector>

class MonthlyReport
{
	
private:
	std::vector <MonthRecord>  income;
	std::vector <MonthRecord> outcome;
public:
	MonthlyReport(std::string str) {
		std::vector<std::string> array = splitString(str, '\n');
		for (int i = 1; i < array.size(); i++) {
			addRecord(array[i]);
		}

	}
	void addRecord(std::string str) {
		std::vector<std::string> array = splitString(str, ',');
		if (array[1] == "TRUE")
			outcome.push_back(MonthRecord(array[0], array[2], array[3]));
		else if (array[1] == "FALSE")
			income.push_back(MonthRecord(array[0], array[2], array[3]));
	}

	double getIncome() {
		double summ = 0;
		for (int i = 0; i < income.size(); i++) {
			summ += income[i].sumOfOne * income[i].quantity;
		}
		return summ;
	}
	double getOutcome() {
		double summ = 0;
		for (int i = 0; i < outcome.size(); i++) {
			summ += outcome[i].sumOfOne * outcome[i].quantity;
		}
		return summ;
	}
	void showAll() {
		std::cout << "OUTCOME:" << std::endl;
		for (int i = 0; i < outcome.size(); i++) {
			std::cout << "name: " << outcome[i].itemName;
			std::cout << "   quantity: " << outcome[i].quantity << std::endl;
			std::cout << "   sum of one: " << outcome[i].sumOfOne << std::endl;
		}
		std::cout<<std::endl;
		std::cout << "INCOME:" << std::endl;
		for (int i = 0; i < income.size(); i++) {
			std::cout << "name: " << income[i].itemName;
			std::cout << "   quantity: " << income[i].quantity << std::endl;
			std::cout << "   sum of one: " << income[i].sumOfOne << std::endl;
		}
	}
private:
	std::vector<std::string> splitString(std::string str, char sep) {
		std::string buf = "";
		std::vector<std::string> array;
		for (int i = 0; i<=str.size(); i++) {
			if (str[i] == sep || str[i]=='\0') {
				std::cout << buf<<std::endl;
				array.push_back(buf);
				buf = "";
			}
			else buf += str[i];
		}
		return array;
	}
	

	
};

