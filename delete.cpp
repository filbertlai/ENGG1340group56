#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void delet() {
	cout << setfill('x') << setw(50) << "x" << endl;
	char choice = 'A';
	while (choice != 'I' && choice != 'E') {
		cout << "Income or Expense? Please type in I or E: ";
		cin >> choice;
	}
	if (choice == 'I') {
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
		cout << "Please type in the line number that you would like to delete: ";
		int line_number;
		cin >> line_number;
		fin.close();

		//open new file
		ofstream temp;
		ifstream old;
		old.open("income.txt");
		temp.open("temp.txt");
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
		}
	}
		if (choice == 'E') {
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
			cout << "Please type in the line number that you would like to delete: ";
				int line_number;
			cin >> line_number;
			ex.close();
		}
}
int main() {
	delet();
	return 0;
}
