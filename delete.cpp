#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void delet() {
	cout << setfill('x') << setw(50) << "x" << endl;
	char choice = 'A';
	while (choice != 'I' && choice != 'E') {
		cout << "Income or Expense? Please type in I or E" << endl;
		cin >> choice;
	}
	if (choice == 'I') {
		ifstream fin;
		fin.open("income.txt", ios::app);
		if (fin.fail()) {
			cout << "Error!" << endl;
		}
    fin >> year >> month >> day >> cetegory >> description >> amount
    cout << year << "/" << month << "/" << day << " " << cetegory << " " <<description << " " << "$" << amount <<endl;
