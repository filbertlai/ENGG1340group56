#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

//input the choice: sorted by date or amount
//output the decision
string Date_or_amount() {
	string choice2;
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
	return choice2;
}

//input unsorted list of dates (array)
//output sorted list of dates to temp_sorted_date.txt
void sort_date(Date income_date[], int size, string sorted[]) {
	int max = size - 1;
	for (int i = 0; i < max; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (income_date[i].year > income_date[j].year)
			{
				Date temp1;
				temp1 = income_date[i];
				income_date[i] = income_date[j];
				income_date[j] = temp1;
			}
			else if (income_date[i].year == income_date[j].year && income_date[i].month > income_date[j].month)
			{
				Date temp;
				temp = income_date[i];
				income_date[i] = income_date[j];
				income_date[j] = temp;
			}
			else if (income_date[i].year == income_date[j].year
				&& income_date[i].month == income_date[j].month && income_date[i].day > income_date[j].day)
			{
				Date temporary;
				temporary = income_date[i];
				income_date[i] = income_date[j];
				income_date[j] = temporary;
			}
		}
	}
	for (int p = 0; p < size; p++){
		if ((income_date[p].month < 10) && (income_date[p].day < 10)) {
			sorted[p] = to_string(income_date[p].year) + " " + "0" + to_string(income_date[p].month) + " " + "0" + to_string(income_date[p].day);
		}
		else if (income_date[p].month < 10) {
			sorted[p] = to_string(income_date[p].year) + " " + "0" + to_string(income_date[p].month) + " " + to_string(income_date[p].day);
		}
		else if (income_date[p].day < 10) {
			sorted[p] = to_string(income_date[p].year) + " " + to_string(income_date[p].month) + " " + "0" + to_string(income_date[p].day);
		}
	}
}

//input the unsorted amount array
//output the sorted amount array
void sort_amount(double amount[], int i) {
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


//input the sorted amount array
//output a sorted list of records
void output_sorted_income_amount(double amount[],int i) {
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
			cout << str << " " << amount[w] << endl;
			if (str == amount[w]) {
				cout << line << endl;
				cout << amount[w];
			}
		}
	}
	fin.close();
}

void output_sorted_expense_amount(double amount[], int i) {
	ifstream fin;
	fin.open("expense.txt");
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
				cout << amount[w];
			}
		}
	}
	fin.close();
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
		string choice2 = Date_or_amount(); //line 16

		//Sorting by date
		if (choice2 == "1") {
			ifstream fin;
			fin.open("income.txt");
			if (fin.fail()) {
				cout << "Invalid! You don't have any income records!" << endl;
			}
			Date income_date[1000];
			int n = 0;
			string line;
			while (getline(fin, line)) {
				fin >> income_date[n].year >> income_date[n].month >> income_date[n].day;
				n = n + 1;
			}
			int size = n + 1;
			string sorted[1000];
			sort_date(income_date, size, sorted); //line34

			ifstream income;
			income.open("income.txt");
			string line_from_data;
			for (int g = 0;g < size;g++) {
				while (getline(income, line_from_data)) {
					string str = line_from_data.substr(0, 10);
					cout << str << " sorted:" << sorted[g] << endl;
					if (str == sorted[g]) {
						cout << line_from_data << endl;
					}
				}
				income.close();
			}
			//Sorting by amount
			if (choice2 == "2") {
				ifstream fin;
				fin.open("income.txt");
				if (fin.fail()) {
					cout << "Invalid! You don't have any income records!" << endl;
				}
				//input all unsorted records from income.txt/expense.txt
				//output an array amount[] that store all amounts
				int pos_open, i = 0;
				double amount[1000];
				string line;
				while (getline(fin, line)) {
					pos_open = line.find('$') + 1;
					amount[i] = stod(line.substr(pos_open));
					i = i + 1;
				}
				fin.close();
				sort_amount(amount, i);
				output_sorted_income_amount(amount, i);
			}
		}
	}
}

int main() {
	sort();
	cout << "end" << endl;
	return 0;
}
