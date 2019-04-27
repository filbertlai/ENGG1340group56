#include "budget.h"
#include<iostream>
#include<fstream>
using namespace std;

//This is a function to set monthly budget
//User is required to input year, month and budget
//A text file named "budget.txt" will be generated to record the budget plan then
//For example, if a user want to set a budget of $1000 in April, 2019.
//Then, the user is required to input (2019 -> 4 -> 1000)
//After the input, "budget.txt" will be generated with content (2019 4 $1000)

int budget()
{
    int year, month, day;
    double budget;
    cout<<"Welcome to set your monthly budget!"<<endl;
    cout<<"The year of the budget plan: ";
    cin>>year;
    while ((year > 3000) || (year < 1500)) {
			cout << "Invalid year! Please input again. Year: ";
			cin >> year;
		}
    cout<<"The month of the budget plan: ";
    cin>>month;
		while ((month > 12) || (month < 1)) {
			cout << "Invalid month! Please input again. Month: ";
			cin >> month;
		}
    cout<<"The amount of budget of the month you inputted: ";
    cin>>budget;
    ofstream fout;
    fout.open("budget.txt");
    if (fout.fail())
    {
        cout<<"Error in setting the file!"<<endl;
        exit(1);
    }
    fout<<year<<" "<<month<<" $"<<budget;
    fout.close();
    cout<<endl<<"XXX Budget setted successfully! XXX"<<endl;
    cout<<"The budget you setted is: $"<<budget<<" in Month "<<month<<" of "<<year<<"."<<endl;
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        day=31;
    }
    else if (month==2&&year%4==0)
    {
        day=29;
    }
    else if (month==2&&year%4!=0)
    {
        day=28;
    }
    else if (month==4||month==6||month==9||month==11)
    {
        day=30;
    }
    cout<<"Month "<<month<<" in year "<<year<<" has "<<day<<" days."<<endl;
    cout<<"Therefore, you have $"<<budget<<"/"<<day<<" = $"<<budget/day<<" daily budget in average!"<<endl;
    
    
    
}
