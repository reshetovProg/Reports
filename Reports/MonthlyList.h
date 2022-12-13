#pragma once
//#include "MonthlyReport.h"
#include <vector>
#include "monthlyReport.h"
class MonthlyList
{
	std::vector< MonthlyReport> list;
public:
	void addMonth(std::string str) {
		list.push_back(MonthlyReport(str));
	}
	MonthlyReport operator[](int i) {
		return list[i];
	}
	int size() {
		return list.size();
	}
};

