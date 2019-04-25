#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void add() {
	cout << setfill('x') << setw(50) << "x" << endl;
	char choice = 'A';
	while (choice != 'I' && choice != 'E') {
		cout << "Income or Expense? Please type in I or E" << endl;
		cin >> choice;
	}
	if (choice == 'I') {
		string catergories, description;
		int Year, Month, Day, num_of_categories, amount;
		ofstream fout;
		fout.open("income.txt", ios::app);
		if (fout.fail()) {
			cout << "Error!" << endl;
		}
		cout << "Year:";
		cin >> Year;
		cout << "Month:";
		cin >> Month;
		cout << "Day:";
		cin >> Day;
		while (Day > 31) {
			cout << "Invalid day! Please input again. Day: ";
			cin >> Day;
		}
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
			cout << "Incorrect number!Please input a number from 1 to 6: ";
			cin >> num_of_categories;
		}
		//input the categories rather than just the number
		switch (num_of_categories) {
		case '1':
			catergories == "1.Basic Salary";
			break;
		case '2':
			catergories == "2.Bonus";
			break;
		case '3':
			catergories == "3.Investment";
			break;
		case '4':
			catergories == "4.Pocket Money";
			break;
		case '5':
			catergories == "5.Gifts";
			break;
		case '6':
			catergories == "6.Lottery prizes";
			break;
		}
		cout << "Description:";
		cin >> description;
		cout << "Amount(in HKD $):";
		cin >> amount;
		cout << endl;
		fout << Year << " " << Month << " " << Day << " " << catergories << " " << description << " " << amount << endl;
	}
	if (choice == 'E') {
		string catergories, description;
		int Year, Month, Day, num_of_categories, amount;
		ofstream expense;
		expense.open("expense.txt", ios::app);
		if (expense.fail()) {
			cout << "Error!" << endl;
		}
		cout << "Year:";
		cin >> Year;
		cout << "Month:";
		cin >> Month;
		cout << "Day:";
		cin >> Day;
		while (Day > 31) {
			cout << "Invalid day! Please input again." << endl;
			cin >> Day;
		}
		cout << "Please choose the catergory from the below choices:" << endl;
		cout << "1. Food & Beverage" << endl;
		cout << "2. Transport" << endl;
		cout << "3. Personal care" << endl;
		cout << "4. Food & Beverage" << endl;
	}
}

int main(){
    add();
    cout<<"end"<<endl;
    return 0;
}
