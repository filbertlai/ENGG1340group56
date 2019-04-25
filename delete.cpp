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
		}
		temp.close();
		old.close();

		//input back from temp to expense.txt
		ifstream temp2;
		ofstream result;
		result.open("income.txt");
		temp2.open("tempi.txt");
		string finish;
		while (getline(temp2, finish)) {
			result << finish << endl;
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

		//open new file to store temperary
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
		}
		temp.close();
		old.close();

		//input back from temp to expense.txt
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
int main() {
	delet();
	return 0;
}
