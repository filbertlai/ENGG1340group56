#include<iostream>
#include<fstream>
using namespace std;

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
        cout<<"Error!"<<endl;
        exit(1);
    }
    fout<<year<<" "<<month<<" $"<<budget;
    fout.close();
    cout<<"Budget setted successfully!"<<endl;
}
