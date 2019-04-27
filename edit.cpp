#include "edit.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//chosse the specific record to edit
//input corrected year, month, day, catergory, dsecription, amount
//output the corrected record to income.txt / expense.txt
void edit() {
	cout << setfill('x') << setw(56) << "x" << endl;
	string choice = "A";
	while (choice != "I" && choice != "E") {
		cout << "Income or Expense? Please type in I or E: ";
		cin >> choice;
	}
	//For income
	if (choice == "I") {
		ifstream fin;
		fin.open("income.txt");
		if (fin.fail()) {
			cout << "Error!" << endl;
		}
		string line;
		int i = 1;
		while (getline(fin, line)) {
			cout << i << ". " << line << endl;
			i += 1;
		}
		fin.close();
		cout << "Please type in the line number that you would like to edit: ";
		int line_number;
		cin >> line_number;
		string catergories, description;
		int Year, Month, Day, num_of_categories = 1;
		double amount;
		cout << "Corrected Year:";
		cin >> Year;
		cout << "Correct Month:";
		cin >> Month;
		while (Month > 12) {
			cout << "Invalid month! Please input again. Corrected Month: ";
			cin >> Month;
		}
		cout << "Corrected Day:";
		cin >> Day;
		while (Day > 31) {
			cout << "Invalid day! Please input again. Corrected Day: ";
			cin >> Day;
		}
		cout << setfill('x') << setw(56) << "x" << endl;
		cout << "Please choose the catergory from the below choices:" << endl;
		cout << "1.Basic Salary" << endl;
		cout << "2.Bonus" << endl;
		cout << "3.Investment" << endl;
		cout << "4.Pocket Money" << endl;
		cout << "5.Gifts" << endl;
		cout << "6.Lottery prizes" << endl;
		cout << "Please indicate your corrected choice in 1-6: ";
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
		cout << "Corrected description (if no description, please press 0) :";
		cin >> description;
		cout << "Corrected Amount(in HKD $):";
		cin >> amount;
		cout << endl;

		//open a temporary file to store the new list of records (with the specific line deleted)
		ofstream temp;
		ifstream old;
		old.open("income.txt");
		temp.open("tempi.txt");
		if (temp.fail()) {
			cout << "Error!" << endl;
		}
		int max = i + 1, a = 0;
		string writing;
		while (getline(old, writing)) {
			a += 1;
			if (a != line_number) {
				temp << writing << endl;
			}
			else
				temp << Year << " " << Month << " " << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		temp.close();
		old.close();

		//input the record from tempi.txt back to expense.txt
		ifstream temp2;
		ofstream result;
		result.open("income.txt");
		temp2.open("tempi.txt");
		string finish;
		while (getline(temp2, finish)) {
			result << finish << endl;
		}
	}
	//For expense
	if (choice == "E") {
		ifstream ex;
		ex.open("expense.txt");
		if (ex.fail()) {
			cout << "Error!" << endl;
		}
		string line;
		int i = 1;
		while (getline(ex, line)) {
			cout << i << ". " << line << endl;
			i += 1;
		}
		cout << "Please type in the line number that you would like to edit: ";
		int line_number;
		cin >> line_number;
		ex.close();

		//Delete the record
		string catergories, description;
		int Year, Month, Day, num_of_categories = 1;
		double amount;
		cout << "Corrected year:";
		cin >> Year;
		cout << "Corrected month:";
		cin >> Month;
		while (Month > 12) {
			cout << "Invalid month! Please input again. Month: ";
			cin >> Month;
		}
		cout << "Corrected day:";
		cin >> Day;
		while (Day > 31) {
			cout << "Invalid day! Please input again. Day:";
			cin >> Day;
		}
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
				catergories = "Food & Beverage-Breakfast";
			}
			else if (type == 'b') {
				catergories = "Food & Beverage-Lunch";
			}
			else if (type == 'c') {
				catergories = "Food & Beverage-Tea";
			}
			else if (type == 'd') {
				catergories = "Food & Beverage-Dinner";
			}
			else if (type == 'e') {
				catergories = "Food & Beverage-Snacks";
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
				catergories = "Shopping-ElectricalAplliances";
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
		cout << " dorrectedDescription (if no description, please press 0) :";
		cin >> description;
		cout << "Corrected amount(in HKD $):";
		cin >> amount;
		cout << endl;

		//open new file to store the record temperarily
		ofstream temp; 
		ifstream old;
		old.open("expense.txt");
		temp.open("tempe.txt");
		if (temp.fail()) {
			cout << "Error!" << endl;
		}
		int max = i + 1, a = 0;
		string writing;
		while (getline(old, writing)) {
			a += 1;
			if (a != line_number) {
				temp << writing << endl;
			}
			else
				temp << Year << " " << Month << " " << Day << " " << "[" << catergories << "]" << " " << "(" << description << ")"
				<< " " << "$" << amount << endl;
		}
		temp.close();
		old.close();

		//input the record back from tempe.txt to expense.txt
		ifstream temp2;
		ofstream result;
		result.open("expense.txt");
		temp2.open("tempe.txt");
		string finish;
		while (getline(temp2, finish)) {
			result << finish << endl;
		}
	}
}
