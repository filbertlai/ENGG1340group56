#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

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
		cout << setfill('x') << setw(50) << "x" << endl;
		cout << "Sorting methods are stated below" << endl;
		cout << "1.Date" << endl;
		cout << "2.Amount" << endl;
		cout << "Please choose 1 or 2: ";
		cin >> choice2;

		if (choice2 != "1" && choice2 != "2") {
			cout << "Invalid choice! Please choose 1 or 2: ";
			cin >> choice2;
		}

		//Output income records sorted by amount
		if (choice2 == "2") {
			ifstream fin;
			fin.open("income.txt");
			if (fin.fail()) {
				cout << "Error!" << endl;
			}

			//input all unsorted records from income.txt(fin)
			//output an array amount[] that store all amounts
			int pos_open, i = 0;
			double amount[1000];
			string line;
			while (getline(fin, line)) {
				pos_open = line.find('$') + 1;
				amount[i] = stod(line.substr(pos_open));
				i = i + 1;
			}
			sort_amount(amount, i);
			for (int v = 0;v < i + 1;v++) {
				cout << amount[v];
			}
		}

		//Output income records sorted by date
		if (choice2 == "1") {
			cout << "NG";
		}
	}
	//Expense
}

int main() {
	sort();
	return 0;
}
