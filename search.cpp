#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int method_of_searching;

int search_by_date()
{
    cout<<"1) Search in Year"<<endl;
    cout<<"2) Search in Month"<<endl;
    cout<<"3) Search in Day"<<endl;
    cout<<"4) Search in exact day"<<endl;
    cout<<"Please enter 1/2/3/4: ";
    cin>>method_of_searching;
    return method_of_searching;
}

int search_by_amount()
{
    cout<<"1) Search by exact amount"<<endl;
    cout<<"2) Search by a range"<<endl;
    cout<<"3) Search by upper limit"<<endl;
    cout<<"4) Search by lower limit"<<endl;
    cout<<"Please enter 1/2/3/4: ";
    cin>>method_of_searching;
    return method_of_searching;
}

int income_type()
{
    cout<<"1) Basic Salary"<<endl;
    cout<<"2) Bonus"<<endl;
    cout<<"3) Investment"<<endl;
    cout<<"4) Pocket Money"<<endl;
    cout<<"5) Gifts"<<endl;
    cout<<"6) Lottery Prizes"<<endl;
    cout<<"Please enter 1/2/3/4/5/6: ";
    cin>>method_of_searching;
    return method_of_searching;
}

int expense_type()
{
    cout<<"01) Household"<<endl;
    cout<<"02) Household - Internet"<<endl;
    cout<<"03) Household - Phone"<<endl;
    cout<<"04) Household - Water"<<endl;
    cout<<"05) Household - Electricity"<<endl<<endl;
    cout<<"06) Transport"<<endl<<endl;
    cout<<"07) Personal Care"<<endl;
    cout<<"08) Personal Care - Medical / Dental"<<endl;
    cout<<"09) Personal Care - Beauty / Fitness"<<endl;
    cout<<"10) Personal Care - Hairdressing"<<endl<<endl;
    cout<<"11) Food & Beverage"<<endl;
    cout<<"12) Food & Beverage - Breakfast"<<endl;
    cout<<"13) Food & Beverage - Lunch"<<endl;
    cout<<"14) Food & Beverage - Tea"<<endl;
    cout<<"15) Food & Beverage - Dinner"<<endl;
    cout<<"16) Food & Beverage - Snacks"<<endl<<endl;
    cout<<"17) Lifestyle"<<endl;
    cout<<"18) Lifestyle - Entertainments"<<endl;
    cout<<"19) Lifestyle - Celecbrations"<<endl;
    cout<<"20) Lifestyle - Holiday"<<endl;
    cout<<"21) Lifestyle - InterestCall/Hobbies"<<endl<<endl;
    cout<<"22) Shopping"<<endl;
    cout<<"23) Shopping - Houshold Goods"<<endl;
    cout<<"24) Shopping - Health Supplements"<<endl;
    cout<<"25) Shopping - Electrical Appliances"<<endl;
    cout<<"26) Shopping - Clothing / Footwear"<<endl;
    cout<<"27) Shopping - Cosmetics / Skin Care Products"<<endl<<endl;
    cout<<"28) Investment"<<endl<<endl;
    cout<<"29) Gifts"<<endl<<endl;
    cout<<"30) Others"<<endl;
    cout<<"Please enter the number: ";
    cin>>method_of_searching;
    return method_of_searching;
}

int main()
{
    cout<<"Welcome to search for specific record(s)!"<<endl;
    int income_or_expense,search_what,search,search_1,search_2;
    cout<<"1) Search for income"<<endl;
    cout<<"2) Search for expense"<<endl;
    cout<<"Please enter 1/2: ";
    cin>>income_or_expense;
    cout<<"1) Search by data"<<endl;
    cout<<"2) Search by types"<<endl;
    cout<<"3) Search by amount"<<endl;
    cout<<"4) Search by description"<<endl;
    cout<<"Please enter 1/2/3/4: ";
    cin>>search_what;
    if (search_what==1)
    {
        string filename;
        method_of_searching=search_by_date();
        if (income_or_expense==1)
        {
            filename="income.txt";
        }
        else if (income_or_expense=2)
        {
            filename="expense.txt";
        }
        
        ifstream fin;
        fin.open(filename);
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
        }
        if (method_of_searching==1)
        {
            cout<<"The year you want to search: ";
            cin>>search;
            string line;
            int year;
            while(getline(fin,line))
            {
                year=stoi(line.substr(0,4));
                if (search==year)
                {
                    cout<<line<<endl;
                }
            }
        }
        
        else if (method_of_searching==2)
        {
            cout<<"The month you want to search: ";
            cin>>search;
            string line;
            int month;
            while(getline(fin,line))
            {
                month=stoi(line.substr(5,2));
                if (search==month)
                {
                    cout<<line<<endl;
                }
            }
            }
        
        else if (method_of_searching==3)
        {
            cout<<"The day you want to search: ";
            cin>>search;
            int day;
            string line;
            while(getline(fin,line))
            {
                day=stoi(line.substr(8,2));
                if (search==day)
                {
                    cout<<line<<endl;
                }
            }
            }
        
        else if (method_of_searching==4)
        {
            cout<<"The year you want to search: ";
            cin>>search;
            cout<<"The month you want to search: ";
            cin>>search_1;
            cout<<"The day you want to search: ";
            cin>>search_2;
            string line;
            while(getline(fin,line))
            {
                int year=stoi(line.substr(0,4));
                int month=stoi(line.substr(5,2));
                int day=stoi(line.substr(8,2));
                if (search==year&&search_1==month&&search_2==day)
                {
                    cout<<line<<endl;
                }
            }
        }
            cout<<"End of Search!"<<endl;
            fin.close();
    }
}
