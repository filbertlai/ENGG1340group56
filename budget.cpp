#include<iostream>
#include<fstream>
using namespace std;

//This is a function to set monthly budget
//User is required to input year, month and budget
//A text file named "budget.txt" will be generated to record the budget plan then
//For example, if a user want to set a budget of $1000 in April, 2019.
//Then, the user is required to input (2019 -> 4 -> 1000)
//After the input, "budget.txt" will be generated with content (2019 4 $1000)

int main()
{
    int year, month;
    double budget;
    cout<<"Welcome to set your monthly budget!"<<endl;
    cout<<"The year of the budget plan: ";
    cin>>year;
    cout<<"The month of the budget plan: ";
    cin>>month;
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
    cout<<"Budget setted successfully!"<<endl;
    cout<<"The budget you setted is: $"<<budget<<" in "<<month<<"(Month in number) of "<<year<<"."<<endl;
}
