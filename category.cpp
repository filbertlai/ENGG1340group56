#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "start.h"
using namespace std;

// show all the records for user to choose which record to delete
// input the line number of the record to be deleted
// output the new list of records back to income.txt / expense.txt
void delet() {
	cout << setfill('x') << setw(50) << "x" << endl;
	string choice = "A";
	while (choice != "I" && choice != "E") {
		cout << "Income or Expense? Please type in I or E: ";
		cin >> choice;
	}
	string category;

	//For income
	if (choice == "I") {
		int num_of_categories;
		cout << setfill('x') << setw(50) << "x" << endl;
		cout << "Please choose the category from the below choices:" << endl;
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
			category = "BasicSalary";
			break;
		case 2:
			category = "Bonus";
			break;
		case 3:
			category = "Investment";
			break;
		case 4:
			category = "PocketMoney";
			break;
		case 5:
			category = "Gifts";
			break;
		case 6:
			category = "LotteryPrizes";
			break;
		}
		ifstream fin;
		fin.open("income.txt");
		if (fin.fail()) {
			cout << "Error!" << endl;
		}
		string str, line;
		int pos_open, pos_close;
		while (getline(fin, line)) {
			pos_open = line.find('[') + 1;
			pos_close = line.find(']');
			str = line.substr(pos_open, pos_close - pos_open);
			if (str == category) {
				cout << line << endl;
			}
		}
		fin.close();
	}

	//For expense:
	if (choice == "E") {
		int num_of_categories;
		cout << setfill('x') << setw(50) << "x" << endl;
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
		switch (num_of_categories) {
		case 1:
			category = "Household";
			break;
		case 2:
			category = "Transport";
			break;
		case 3:
			category = "Personalcare";
			break;
		case 4:
			category = "Food&Beverage";
			break;
		case 5:
			category = "Lifestyle";
			break;
		case 6:
			category = "Shopping";
			break;
		case 7:
			category = "Investment";
			break;
		case 8:
			category = "Gifts";
			break;
		case 9:
			category = "Others";
			break;
		}
		ifstream ex;
		ex.open("expense.txt");
		if (ex.fail()) {
			cout << "You don't have any records in expense!" << endl;
		}
		string str, line;
		int pos_open, pos_close;
		while (getline(ex, line)) {
			pos_open = line.find('[') + 1;
			if ((num_of_categories == 2) || (num_of_categories == 7) || 
				(num_of_categories == 8) || (num_of_categories == 9)) {
				pos_close = line.find(']');
			}
			else {
				pos_close = line.find('-');
			}
				str = line.substr(pos_open, pos_close-pos_open);
			if (str == category) {
				cout << line << endl;
			}
		}
		ex.close();
	}
}
