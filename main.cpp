#include "add.h"
#include "delete.h"
#include "edit.h"
#include "category.h"
#include "budget.h"
#include "report.h"
#include "search.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int cmd;

	while (1)
	{
		cout << setfill('x') << setw(56) << "x" << endl;
		for (int i = 0;i < 10;i++) { cout << "x"; }
		cout << " Welcome back to Accounting System! ";
		for (int i = 0;i < 10;i++) { if (i == 9) { cout << "x" << endl; break; }cout << "x"; }
		cout << setfill('x') << setw(56) << "x" << endl;

		cout << endl << "*******Changing the records of income or expense*******" << endl;
		cout << "1)  Add a record" << endl;
		cout << "2)  Delete a record" << endl;
		cout << "3)  Edit a record" << endl;
		cout << endl << "****Looking for specific record(s)/statistic report****" << endl;
		cout << "4)  View records of specific category or account" << endl;
		cout << "5)  Search for specific record(s)" << endl;
		cout << "6)  Show Statistic report of financial state" << endl;
		cout << endl << "*****************Preset budget/records*****************" << endl;
		cout << "7)  Set a budget for the next month" << endl;
		cout << endl << "Please enter the number of command: ";
		cin >> cmd;
		if (cmd == 1) { add(); }
		else if (cmd == 2) { delet(); }
		else if (cmd == 3) { edit(); }
		else if (cmd == 4) { category(); }
		else if (cmd == 5) { searchh(); }
		else if (cmd == 6) { report(); }
		else if (cmd == 7) { budget(); }
	}
}
