#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//input the sorted amount array
//output a sorted list of records
void checkmatch_amount(double amount[],int i) {
	ifstream fin;
	fin.open("income.txt");
	if (fin.fail()) {
		cout << "Error!" << endl;
	}
	int pos_open;
	string line;
	for (int w = 0;w < i + 1;w++) {
		while (getline(fin, line)) {
			pos_open = line.find('$') + 1;
			double str = stod(line.substr(pos_open));
			if (str == amount[w]) {
				cout << line << endl;
			}
		}
	}
	fin.close();
}

//input the choice: sorted by date or amount
//output the choice
void Date_or_amount(string &choice2) {
	cout << setfill('x') << setw(50) << "x" << endl;
	cout << "Sorting methods are stated below" << endl;
	cout << "1.Date" << endl;
	cout << "2.Amount" << endl;
	cout << "Please choose 1 or 2: ";
	cin >> choice2;

	while (choice2 != "1" && choice2 != "2") {
		cout << "Invalid choice! Please choose 1 or 2: ";
		cin >> choice2;
	}
}

//input the unsorted amount array
//output the sorted amount array
void sort_amount(double amount[],int i) {
	int a, b, idx;
	double min;
	int size = i + 1;
	for (a = 0;a < size;++i) {
		min = amount[a];
		idx = a;
		for (b = a + 1;b < size;++b) {
			if (amount[b] < min) {
				min = amount[b];
				idx = b;
			}
		}
		//swap the two numbers
		if (idx != a) {
			double temp = amount[a];
			amount[a] = amount[idx];
			amount[idx] = temp;
		}
	}
}

void sort() {
	cout << setfill('x') << setw(50) << "x" << endl;
	string choice = "A";
	while (choice != "I" && choice != "E") {
		cout << setfill('x') << setw(50) << "x" << endl;
		cout << "Income or Expense? Please type in I or E: ";
		cin >> choice;
	}
	if (choice == "I") {
		string choice2 = "A";
		Date_or_amount(choice2);

		//Sorting by date
		if (choice2 == "1") {
			cout << "NG";
		}

		//Sorting by amount
		if (choice2 == "2") {
			ifstream fin;
			fin.open("income.txt");
			if (fin.fail()) {
				cout << "Error!" << endl;
			}
			//input all unsorted records from income.txt/expense.txt
			//output an array amount[] that store all amounts
			int pos_open, i = 0;
			double amount[1000], m;
			string line;
			while (getline(fin, line)) {
				pos_open = line.find('$') + 1;
				m = stod(line.substr(pos_open));
				i = i + 1;
			}
			fin.close();
			cout << m;
			//sort_amount(amount, i);
			//checkmatch_amount(amount)
		}
	}
	//Expense
	if (choice == "E") {
		string choice2 = "A";
		Date_or_amount(choice2);

		//Output income records sorted by amount
		if (choice2 == "2") {
			ifstream ex;
			ex.open("expense.txt");
			if (ex.fail()) {
				cout << "Error!" << endl;
			}
			//input all unsorted records from income.txt/expense.txt
			//output an array amount[] that store all amounts
			int pos_open, i = 0;
			double amount[1000];
			string line;
			while (getline(ex, line)) {
				pos_open = line.find('$') + 1;
				amount[i] = stod(line.substr(pos_open));
				i = i + 1;
			}
			ex.close();
			sort_amount(amount, i);
			checkmatch_amount(amount, i);
		}

		//Output income records sorted by date
		if (choice2 == "1") {
			cout << "NG";
		}
	}
}

int main() {
	sort();
	return 0;
}
