
#include <iostream>
#include "monthlyReport.cpp"
#include "MonthRecord.cpp"
#include "yearlyReport.cpp"
#include "YearRecord.cpp"
#include "MonthlyList.h"
#include <Windows.h>
#include <fstream>
#include <string>

std::string getText(std::string path) {
	std::ifstream in(path);
	std::string str;
	std::string resultText="";
	if (in.is_open()) {
		while (getline(in, str)) {
			resultText += str;
			//std::cout <<"size: "<< str.size() << std::endl;
			resultText += '\n';
		}
		
		resultText.erase(resultText.size() - 1,1);
	}
	in.close();
	return resultText;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MonthlyList list;
	list.addMonth(getText("src\\m.202101.csv"));
	list.addMonth(getText("src\\m.202102.csv"));
	list.addMonth(getText("src\\m.202103.csv"));
	YearlyReport year1(getText("src\\y.2021.csv"));
	bool flag = true;
	for (int i = 0; i < list.size(); i++) {
		if (year1.getIncome(0) != list[0].getIncome()
			|| year1.getOutcome(0) != list[0].getOutcome()) {
			std::cout << i + 1 << " month:\n";
			std::cout << "yearReport income: " << year1.getIncome(0) << "   yearReport outcome: " << year1.getOutcome(0)<<std::endl;
			std::cout << "montlyReport income: " << list[0].getIncome() << "   montlyReport outcome: " << list[0].getOutcome() << std::endl;

			flag = false;
		}
	}
	std::cout << flag;



	//MonthlyReport month1("item_name,is_expense,quantity,sum_of_one\nКоньки,TRUE,50,2000\nНовогодняя ёлка,TRUE,1,100000\nЛарёк с кофе,TRUE,3,50000\nАренда коньков,FALSE,1000,180\nПродажа билетов,FALSE,3500,300\nПродажа кофе,FALSE,2421,150");
	/*month1.showAll();
    std::cout<<month1.getIncome()<<std::endl;
	std::cout << month1.getOutcome()<<std::endl;*/
	/*year1.showAll();
	std::cout << year1.getIncome() << std::endl;
	std::cout << year1.getOutcome() << std::endl;*/
}

