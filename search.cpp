#include "search.h"
#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;

//Global variables that will be used in different functions
int method_of_searching,income_or_expense,search_what,search,search_1,search_2;


//It is a function for the user to select the method of search by date
//User can choose search in year, month, day or exact day
//User is then required to input a number represent the method
//For example, if the user want to search records in year 2019
//Then,the user should input (1)
//The function will return the number represent the method
int search_by_date_method()
{
    cout<<"1) Search in Year"<<endl;
    cout<<"2) Search in Month"<<endl;
    cout<<"3) Search in Day"<<endl;
    cout<<"4) Search in exact day"<<endl;
    cout<<"Please enter 1/2/3/4: ";
    cin>>method_of_searching;
    return method_of_searching;
}


//It is a function for the user to select the method of search by amount
//User can choose search by exact amount,inclusive range,upper limit or lower limit
//User is then required to input a number represent the method
//For example, if the user want to search records in a range of amount
//Then,the user should input (2)
//The function will return the number represent the method
int search_by_amount_method()
{
    cout<<"1) Search by exact amount"<<endl;
    cout<<"2) Search by a inclusive range"<<endl;
    cout<<"3) Search by upper limit"<<endl;
    cout<<"4) Search by lower limit"<<endl;
    cout<<"Please enter 1/2/3/4: ";
    cin>>method_of_searching;
    return method_of_searching;
}


//It is a function for the user to select the method of search by income
//User can choose search by different categories in income
//User is then required to input a number represent the category
//For example, if the user want to search records in Basic Salary
//Then,the user should input (1)
//The function will return the number represent the category
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


//It is a function for the user to select the method of search by expense
//User can choose search by different categories in expense
//User is then required to input a number represent the category
//For example, if the user want to search records in Transport
//Then,the user should input (6)
//The function will return the number represent the category
int expense_type()
{
    cout<<endl<<"01) Household"<<endl;
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
    cout<<"30) Others"<<endl<<endl;
    cout<<"Please enter the number: ";
    cin>>method_of_searching;
    return method_of_searching;
}


//This is function to search the records according to the method of searching that the user has chosen in the function<search_by_date_method()>
//User is required to input the information to search
//For example, if the user wants to search the records in 2019
//Then, the user should input (2019)
//The function will then output records in year 2019 
void search_by_date()
{
    string filename;
    method_of_searching=search_by_date_method();
    
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
        exit(1);
    }
    
    if (method_of_searching==1)
    {
        cout<<"The year you want to search: ";
        cin>>search;
        string line;
        int year;
        cout<<"Start Searching: "<<endl;
        
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
        cout<<"Start Searching: "<<endl;
        
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
        cout<<"Start Searching: "<<endl;
        
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
        cout<<"Start Searching: "<<endl;
       
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
    
    cout<<"End of Searching!"<<endl;
    fin.close();
}


//This is function to search the records according to the method of searching that the user has chosen in the function<income_expense()>
//User is not required to input the information to search
//The function will then output records in the category that the user has chosen in the function<income_expense()> 
void search_by_type()
{
    int pos_open,pos_close;
    
    if (income_or_expense==1)
    {
        string type;
        method_of_searching=income_type();
        
        if (method_of_searching==1)
        {
            type="BasicSalary";
        }
        
        else if (method_of_searching==2)
        {
            type="Bonus";
        }
        
        else if (method_of_searching==3)
        {
            type="Investment";
        }
        
        else if (method_of_searching==4)
        {
            type="PocketMoney";
        }
        
        else if (method_of_searching==5)
        {
            type="Gifts";
        }
        
        else if (method_of_searching==6)
        {
            type="LotteryPrizes";
        }
        
        ifstream fin;
        fin.open("income.txt");
        
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
        
        string line,str;
        cout<<"Start Searching: "<<endl;
        
        while (getline(fin,line))
        {
            pos_open=line.find('[')+1;
            if (line.find('-')==-1)
            {
                pos_close=line.find(']');
            }
            
            else
            {
                pos_close=line.find('-');
            }
            str=line.substr(pos_open,pos_close-pos_open);
            
            if (str==type)
            {
                cout<<line<<endl;
            }
        }
        cout<<"End of searching!"<<endl;
        fin.close();
        }
        
    else if (income_or_expense=2)
    {
        string line,type;
        method_of_searching=expense_type();
        if (method_of_searching==1)
        {
            type="Household";
        }
        
        else if (method_of_searching==2)
        {
            type="Household-Internet";
        }
        
        else if (method_of_searching==3)
        {
            type="Household-Phone";
        }
        
        else if (method_of_searching==4)
        {
            type="Household-Water";
        }
        
        else if (method_of_searching==5)
        {
            type="Household-Electricity";
        }
        
        else if (method_of_searching==6)
        {
            type="Transport";
        }
        
        else if (method_of_searching==7)
        {
            type="Personalcare";
        }
        
        else if (method_of_searching==8)
        {
            type="Personalcare-Medical/Dental";
        }
        
        else if (method_of_searching==9)
        {
            type="Personalcare-Beauty/Fitness";
        }
        
        else if (method_of_searching==10)
        {
            type="Personalcare-Hairdressing";
        }
        
        else if (method_of_searching==11)
        {
            type="Food&Beverage";
        }
        
        else if (method_of_searching==12)
        {
            type="Food&Beverage-Breakfast";
        }
        
        else if (method_of_searching==13)
        {
            type="Food&Beverage-Lunch";
        }
        
        else if (method_of_searching==14)
        {
            type="Food&Beverage-Tea";
        }
        
        else if (method_of_searching==15)
        {
            type="Food&Beverage-Dinner";
        }
        
        else if (method_of_searching==16)
        {
            type="Food&Beverage-Snacks";
        }
        
        else if (method_of_searching==17)
        {
            type="Lifestyle";
        }
        
        else if (method_of_searching==18)
        {
            type="Lifestyle-Entertainments";
        }
        
        else if (method_of_searching==19)
        {
            type="Lifestyle-Celebrations";
        }
        
        else if (method_of_searching==20)
        {
            type="Lifestyle-Holiday";
        }
        
        else if (method_of_searching==21)
        {
            type="Lifestyle-InterestCall/Hobbies";
        }
        
        else if (method_of_searching==22)
        {
            type="Shopping";
        }
        
        else if (method_of_searching==23)
        {
            type="Shopping-HouseholdGoods";
        }
        
        else if (method_of_searching==24)
        {
            type="Shopping-HealthSupplements";
        }
        
        else if (method_of_searching==25)
        {
            type="Shopping-ElectricalAppliances";
        }
        
        else if (method_of_searching==26)
        {
            type="Shopping-Clothing/Footwear";
        }
        
        else if (method_of_searching==27)
        {
            type="Shopping-Cosmetics/SkincareProducts";
        }
        
        else if (method_of_searching==28)
        {
            type="Investment";
        }
        
        else if (method_of_searching==29)
        {
            type="Gifts";
        }
        
        else if (method_of_searching==30)
        {
            type="Others";
        }
        
        ifstream fin;
        fin.open("expense.txt");
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
        
        string str;
        cout<<"Start Searching: "<<endl;
        while (getline(fin,line))
        {
            pos_open=line.find('[')+1;
            pos_close=line.find(']');
            str=line.substr(pos_open,pos_close-pos_open);
            if (str==type)
            {
                cout<<line<<endl;
            }
            pos_close=line.find('-');
            str=line.substr(pos_open,pos_close-pos_open);
            if (str==type)
            {
                cout<<line<<endl;
            }
        }
        cout<<"End of Searching!"<<endl;
        fin.close();
    }
}

//This is function to search the records according to the method of searching that the user has chosen in the function<search_by_amount_method()>
//User is required to input the information to search
//For example, if the user has chosen to use inclusive range, then the user should input the upper limit and the lower limit respectively
//The function will then output records within the condition that the user has chosen
void search_by_amount()
{
    method_of_searching=search_by_amount_method();
    double num,up,low,n;
    int pos_open,pos_close;
    string line;
    ifstream fin;
    if (income_or_expense==1)
    {
        fin.open("income.txt");
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
    }
    
    else if (income_or_expense==2)
    {
        fin.open("expense.txt");
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
    }
    
    if (method_of_searching==1)
    {
        cout<<"The exact amount you want to search: ";
        cin>>num;
        cout<<endl<<"Start Searching: "<<endl;
        while (getline(fin,line))
        {
            pos_open=line.find('$')+1;
            n=stod(line.substr(pos_open));
            if (n==num)
            {
                cout<<line<<endl;
            }
        }
    }
    
    else if (method_of_searching==2)
    {
        cout<<"The upper limit of the amount you want to search: ";
        cin>>up;
        cout<<endl<<"The lower limit of the amount you want to search: ";
        cin>>low;
        cout<<endl<<"Start Searching: "<<endl;
        while (getline(fin,line))
        {
            pos_open=line.find('$')+1;
            n=stod(line.substr(pos_open));
            if (n<=up&&n>=low)
            {
                cout<<line<<endl;
            }
        }
    }
    
    else if (method_of_searching==3)
    {
        cout<<"The upper limit of the amount you want to search: ";
        cin>>up;
        cout<<endl<<"Start Searching: "<<endl;
        while (getline(fin,line))
        {
            pos_open=line.find('$')+1;
            n=stod(line.substr(pos_open));
            if (n<=up)
            {
                cout<<line<<endl;
            }
        }
    }
    
    else if (method_of_searching==4)
    {
        cout<<endl<<"The lower limit of the amount you want to search: ";
        cin>>low;
        cout<<endl<<"Start Searching: "<<endl;
        while (getline(fin,line))
        {
            pos_open=line.find('$')+1;
            n=stod(line.substr(pos_open));
            if (n>=low)
            {
                cout<<line<<endl;
            }
        }
    }
    fin.close();
    cout<<"End of Searching!"<<endl;
}    

//This is function to search the records according to description
//User is required to input the keyword for desciption
//For example, if the user want to find a record with the desciption (I am so happy)
//The user can input keyword of the description, such as (happy)
//The function will then output records in the records with the desciption that contains the keywords that the user has inputted
void search_by_description()
{
    ifstream fin;
    string search,line,str;
    int pos_open,pos_close;
    cout<<"The keyword(s) you want to search in description: ";
    cin>>search;
    if (income_or_expense==1)
    {
        fin.open("income.txt");
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
    }
    
    else if (income_or_expense==2)
    {
        fin.open("expense.txt");
        if (fin.fail())
        {
            cout<<"You have not made any record yet!"<<endl;
            exit(1);
        }
    }
    cout<<"Start Searching: "<<endl;
    
    while (getline(fin,line))
    {
        pos_open=line.find('(')+1;
        pos_close=line.find(')');
        str=line.substr(pos_open,pos_close-pos_open);
        for (int i=0;i<(str.length()-search.length()+1);i++)
        {
            if (search==str.substr(i,search.length()))
            {
                cout<<line<<endl;
            }
            break;
        }
    }
    
    fin.close();
    cout<<"End of Searching!"<<endl;
}

//This is main function to process the whole program
//The user is required to input search for income or expense
//For example, if the user wants to search in the records of expenses
//then, the user should input (2)
//The function will then guide the user to different functions and eventually output the relevant records
int searchh()
{
    cout<<setfill('x')<<setw(56)<<"x"<<endl;
    cout<<"Welcome to search for specific record(s)!"<<endl;
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
        search_by_date();
    }
    
    
    else if (search_what==2)
    {
        search_by_type();
    }
    
    
    else if (search_what==3)
    {
        search_by_amount();
    }
    
    
    else if (search_what==4)
    {
        search_by_description();
    }
    
}
