#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void add(){
    cout<<setfill('x')<<setw(50)<<"x"<<endl;
    char choice = 'A';
    while (choice!='I' && choice!='E') {
    cout<<"Income or Expense? Please type in I or E"<<endl;
    cin>>choice;
    }
    if (choice == 'I') {
        string Year,Month,Day,catergories,desceiption;
        int num_of_categories,amount;
        ofstream fout;
        fout.open("income.txt",ios::app);
        if (fout.fail() ) {
            cout<<"Error!"<<endl;
        cout<<"Year:"<<endl;
        cin>>Year;
        cout<<"Month:"<<endl;
        cin>>Year;
        cout<<"Day:"<<endl;
        cin>>Day;
        cout<<"Catergories:"<<endl;
        cout<<left<<setw(10)<<"1.Basic Salary"<<"2.Bonus"<<setw(10)<<"3.Investment"<<endl;
        cout<<left<<setw(10)<<"4.Pocket Money"<<"5.Gifts"<<setw(10)<<"6.Lottery prizes"<<endl;
        cin>>num_of_categories;
        // Check whether the input number is in the range of 1-6
        while ( (num_of_categories > 6 ) || (num_of_categories < 1 )) {
            cout<<"Incorrect number!Please input a number from 1 to 6"<<endl;
            cin>>num_of_categories;
        }
        //input the categories rather than just the number
        switch(num_of_categories) {
            case '1':
                catergories == "1.Basic Salary";
                break;
            case '2':
                catergories == "2.Bonus";
                break;
            case '3':
                catergories == "2.Bonus";
                break;
            case '4':
                catergories == "2.Bonus";
                break;
            case '5':
                catergories == "2.Bonus";
                break;
            case '6':
                catergories == "2.Bonus";
                break;
        }
        cout<<"Short Desceiption:"<<endl;
        cin>>desceiption;
        cout<<"Amount(in HKD $):"<<endl;
        cin>>amount;
        fout<<Year<<Month<<Day<<catergories<<desceiption<<amount<<endl;
        }
    }
}
add()
