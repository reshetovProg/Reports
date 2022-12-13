
#include <iostream>
#include "monthlyReport.cpp"
#include "MonthRecord.cpp"
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
    MonthlyReport month1(getText("src\\m.202101.csv"));
	//MonthlyReport month1("item_name,is_expense,quantity,sum_of_one\nКоньки,TRUE,50,2000\nНовогодняя ёлка,TRUE,1,100000\nЛарёк с кофе,TRUE,3,50000\nАренда коньков,FALSE,1000,180\nПродажа билетов,FALSE,3500,300\nПродажа кофе,FALSE,2421,150");
	month1.showAll();
    std::cout<<month1.getIncome()<<std::endl;
	std::cout << month1.getOutcome()<<std::endl;
}

