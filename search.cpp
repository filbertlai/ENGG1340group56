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
            cout<<"End of Search!"<<endl;
            fin.close();
    }
    
    
    
    
    
    if (search_what==2)
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
            cout<<"End of searching!"<<endl;
            fin.close();
        }
    }
    
    
    
    if (search_what==3)
    {
        method_of_searching=search_by_amount();
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
            while (getline(fin,line))
            {
                pos_open=line.find('$')+1;
                n=stod(line.substr(pos_open));
                if (n<up&&n>low)
                {
                    cout<<line<<endl;
                }
                
            }
        }
        else if (method_of_searching==3)
        {
            cout<<"The upper limit of the amount you want to search: ";
            cin>>up;
            while (getline(fin,line))
            {
                pos_open=line.find('$')+1;
                n=stod(line.substr(pos_open));
                if (n<up)
                {
                    cout<<line<<endl;
                }
                
            }
        }
        else if (method_of_searching==4)
        {
            cout<<endl<<"The lower limit of the amount you want to search: ";
            cin>>low;
            while (getline(fin,line))
            {
                pos_open=line.find('$')+1;
                n=stod(line.substr(pos_open));
                if (n>low)
                {
                    cout<<line<<endl;
                }
                
            }
        }
    }
    
    
    
    if (search_what==4)
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
        cout<<"End of searching!"<<endl;
    }    
    
}
