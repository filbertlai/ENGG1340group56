#include "add.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//input I/E, year, month, day, catergory, dsecription, amount
//output the record to income.txt / expense.txt
void add() {
	//Choosing income or expense
	cout << setfill('x') << setw(56) << "x" << endl;
	string choice = "A";
	while (choice != "I" && choice != "E") {
		cout << "Income or Expense? Please type in I or E: ";
		cin >> choice;
	}
	//For income
	if (choice == "I") {
		string catergories, description;
		int Year, Month, Day, num_of_categories = 1;
		double amount;
		ofstream fout;
		fout.open("income.txt", ios::app);
		if (fout.fail()) {
			cout << "Error!" << endl;
		}
		cout << "Year:";
		cin >> Year;
		while ((Year > 3000) || (Year < 1500)) {
			cout << "Invalid year! Please input again. Year: ";
			cin >> Year;
		}
		cout << "Month:";
		cin >> Month;
		while ((Month > 12) || (Month < 1)) {
			cout << "Invalid month! Please input again. Month: ";
			cin >> Month;
		}
		cout << "Day:";
		cin >> Day;
		while ((Day > 31) || (Day < 1)) {
			cout << "Invalid day! Please input again. Day:";
			cin >> Day;
		}
		//Choosing category
		cout << setfill('x') << setw(50) << "x" << endl;
		cout << "Please choose the catergory from the below choices:" << endl;
		cout << "1.Basic Salary" << endl;
		cout << "2.Bonus" << endl;
		cout << "3.Investment" << endl;
		cout << "4.Pocket Money" << endl;
		cout << "5.Gifts" << endl;
		cout << "6.Lottery prizes" << endl;
		cout << "Please indicate your choice in 1-6: ";
		cin >> num_of_categories;
		// Check whether the input number is in the range of 1-6
		while ((num_of_categories > 6) || (num_of_categories < 1)) {
			cout << "Incalid number!Please input a number from 1 to 6: ";
			cin >> num_of_categories;
		}
		//input the categories rather than just the number
		switch (num_of_categories)
		{
		case 1:
			catergories = "BasicSalary";
			break;
		case 2:
			catergories = "Bonus";
			break;
		case 3:
			catergories = "Investment";
			break;
		case 4:
			catergories = "PocketMoney";
			break;
		case 5:
			catergories = "Gifts";
			break;
		case 6:
			catergories = "LotteryPrizes";
			break;
		}
		cout << "Description (if no description, please press 0) :";
		cin >> description;
		cout << "Amount(in HKD $): ";
		cin >> amount;
		while (amount < 1) {
			cout << "Invalid amount! Please input a positive number. Amount(in HKD $): ";
			cin >> amount;
		}
		//if there are no description, input "" to the txt file instead of "0"
		if (description == "0") {
			description = "";
		}
		cout << endl;
		//if month/day only have one digit, add a zero in front of the number
		if ((Month < 10) && (Day < 10)) {
			fout << Year << " " << "0" << Month << " " << "0" << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		if (Month < 10) {
			fout << Year << " " << "0" << Month << " " << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		else if (Day < 10) {
			fout << Year << " " << Month << " " << "0" << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		fout.close();
	}

	//For expense
	if (choice == "E") {
		string catergories, description;
		int Year, Month, Day, num_of_categories = 1;
		double amount;
		ofstream expense;
		expense.open("expense.txt", ios::app);
		if (expense.fail()) {
			cout << "Error!" << endl;
		}
		cout << "Year:";
		cin >> Year;
		while ((Year > 3000) || (Year < 1500)) {
			cout << "Invalid year! Please input again. Year: ";
			cin >> Year;
		}
		cout << "Month:";
		cin >> Month;
		while ((Month > 12) || (Month < 1)) {
			cout << "Invalid month! Please input again. Month: ";
			cin >> Month;
		}
		cout << "Day:";
		cin >> Day;
		while ((Day > 31) || (Day < 1)) {
			cout << "Invalid day! Please input again. Day:";
			cin >> Day;
		}
		cout << setfill('x') << setw(56) << "x" << endl;
		cout << "Please choose the catergory from the below choices:" << endl;
		cout << "1.Household" << endl;
		cout << "2.Transport" << endl;
		cout << "3.Personal care" << endl;
		cout << "4.Food & Beverage" << endl;
		cout << "5.Lifestyle" << endl;
		cout << "6.Shopping" << endl;
		cout << "7.Investment" << endl;
		cout << "8.Gifts" << endl;
		cout << "9.Others" << endl;
		cout << "Please indicate your choice in 1-9: ";
		cin >> num_of_categories;
		while ((num_of_categories > 9) || (num_of_categories < 1)) {
			cout << "Incorrect number!Please input a number from 1 to 9: ";
			cin >> num_of_categories;
		}
		char type;
		switch (num_of_categories) {
		case 1:
			cout << setfill('x') << setw(56) << "x" << endl;
			cout << "Please choose the catergory from the below choices:" << endl;
			cout << "a)Internet" << endl;
			cout << "b)Mobile phone" << endl;
			cout << "c)Water" << endl;
			cout << "d)Electricity" << endl;
			cout << "Please indicate your choice in a-d: ";
			cin >> type;
			while ((type > 'd') || (type < 'a')) {
				cout << "Incorrect number!Please input a character from a to d: ";
				cin >> type;
			}
			if (type == 'a') {
				catergories = "Household-Internet";
			}
			else if (type == 'b') {
				catergories = "Household-Phone";
			}
			else if (type == 'c') {
				catergories = "Household-Water";
			}
			else if (type == 'd') {
				catergories = "Household-Electricity";
			}
			break;
		case 2:
			catergories = "Transport";
			break;
		case 3:
			cout << setfill('x') << setw(56) << "x" << endl;
			cout << "Please choose the catergory from the below choices:" << endl;
			cout << "a)Medical/Dental" << endl;
			cout << "b)Beauty/Fitness" << endl;
			cout << "c)Hairdressing" << endl;
			cout << "Please indicate your choice in a-c: ";
			cin >> type;
			while ((type > 'c') || (type < 'a')) {
				cout << "Incorrect number!Please input a character from a to c: ";
				cin >> type;
			}
			if (type == 'a') {
				catergories = "Personalcare-Medical/Dental";
			}
			else if (type == 'b') {
				catergories = "Personalcare-Beauty/Fitness";
			}
			else if (type == 'c') {
				catergories = "Personalcare-Hairdressing";
			}
			break;
		case 4:
			cout << setfill('x') << setw(56) << "x" << endl;
			cout << "Please choose the catergory from the below choices:" << endl;
			cout << "a)Breakfast" << endl;
			cout << "b)Lunch" << endl;
			cout << "c)Tea" << endl;
			cout << "d)Dinner" << endl;
			cout << "e}Snacks" << endl;
			cout << "Please indicate your choice in a-e: ";
			cin >> type;
			while ((type > 'e') || (type < 'a')) {
				cout << "Incorrect number!Please input a character from a to e: ";
				cin >> type;
			}
			if (type == 'a') {
				catergories = "Food&Beverage-Breakfast";
			}
			else if (type == 'b') {
				catergories = "Food&Beverage-Lunch";
			}
			else if (type == 'c') {
				catergories = "Food&Beverage-Tea";
			}
			else if (type == 'd') {
				catergories = "Food&Beverage-Dinner";
			}
			else if (type == 'e') {
				catergories = "Food&Beverage-Snacks";
			}
			break;
		case 5:
			cout << setfill('x') << setw(56) << "x" << endl;
			cout << "Please choose the catergory from the below choices:" << endl;
			cout << "a)Entertainments" << endl;
			cout << "b)Celebrations" << endl;
			cout << "c)Holiday" << endl;
			cout << "d)Interest call / Hobbies" << endl;
			cout << "Please indicate your choice in a-d: ";
			cin >> type;
			while ((type > 'd') || (type < 'a')) {
				cout << "Incorrect number!Please input a character from a to d: ";
				cin >> type;
			}
			if (type == 'a') {
				catergories = "Lifestyle-Entertainments";
			}
			else if (type == 'b') {
				catergories = "Lifestyle-Celebrations";
			}
			else if (type == 'c') {
				catergories = "Lifestyle-Holiday";
			}
			else if (type == 'd') {
				catergories = "Lifestyle-InterestCall/Hobbies";
			}
			break;
		case 6:
			cout << setfill('x') << setw(56) << "x" << endl;
			cout << "Please choose the catergory from the below choices:" << endl;
			cout << "a)Household goods" << endl;
			cout << "b)Health supplements" << endl;
			cout << "c)Electronical appliances" << endl;
			cout << "d)Clothing / Footwear" << endl;
			cout << "e}Cosmetics / Skincare products" << endl;
			cout << "Please indicate your choice in a-e: ";
			cin >> type;
			while ((type > 'e') || (type < 'a')) {
				cout << "Incorrect number!Please input a character from a to e: ";
				cin >> type;
			}
			if (type == 'a') {
				catergories = "Shopping-HouseholdGoods";
			}
			else if (type == 'b') {
				catergories = "Shopping-HealthSupplements";
			}
			else if (type == 'c') {
				catergories = "Shopping-ElectricalAppliances";
			}
			else if (type == 'd') {
				catergories = "Shopping-Clothing/Footwear";
			}
			else if (type == 'e') {
				catergories = "Shopping-Cosmetics/SkincareProducts";
			}
			break;
		case 7:
			catergories = "Investment";
			break;
		case 8:
			catergories = "Gifts";
			break;
		case 9:
			catergories = "Others";
			break;
		}
		cout << setfill('x') << setw(56) << "x" << endl;
		cout << "Description (if no description, please press 0) :";
		cin >> description;
		cout << "Amount(in HKD $): ";
		cin >> amount;
		while (amount < 1) {
			cout << "Invalid amount! Please input a positive number. Amount(in HKD $): ";
			cin >> amount;
		}
		cout << endl;
		int v, f;
		if (description == "0") {
			description = "";
		}
		if ((Month < 10)&&(Day<10)) {
			expense << Year << " " << "0" << Month << " " << "0" << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		if (Month < 10) {
			expense << Year << " " << "0" << Month << " " << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		else if (Day < 10) {
			expense << Year << " " << Month << " " << "0" << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		int sum = 0;
		ifstream check;
		check.open("expense.txt");
		string line;
		while (getline(check, line)) {
			int pos_open = line.find('$') + 1;
			sum += stoi(line.substr(pos_open));
		}
		check.close();
		ifstream bud;
		bud.open("budget.txt");
		while (getline(bud, line)) {
			int open = line.find('$') + 1;
			int budget_from_plan = stoi(line.substr(open));
			if (sum > budget_from_plan) {
				cout << "********* ! ! ! ~~~ A L E R T ~~~ ! ! ! ***********" << endl;
				cout << "*********Alert! You have exceed your budget!!******" << endl;
				cout << "*********You have EXCEED your budget!!*************" << endl;
				cout << " " << endl;
			}
		}
		bud.close();
	}
}
