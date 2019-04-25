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
		fin.open("income.txt", ios::app);
		if (fin.fail()) {
			cout << "Error!" << endl;
		}
		string line;
		int i = 1;
		while (getline(fin,line)) {
			cout << i << ". " << line << endl;
			i += 1;
		}
	}
}
int main() {
	delet();
	return 0;
}
