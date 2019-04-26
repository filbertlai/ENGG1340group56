#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    cout<<"Welcome to the statistic report of your income and expense!"<<endl;
    double income_sum=0,BasicSalary_sum=0,Bonus_sum=0,Investment_sum=0,PocketMoney_sum=0,Gifts_sum=0,LotteryPrizes_sum=0,num;
    string str,line;
    int pos_open,pos_close;
    ifstream fin;
    fin.open("income.txt");
    if(fin.fail()){cout<<"Error in file opening!"<<endl;exit(1);}
    while(getline(fin,line))
    {
        pos_open=line.find('$')+1;
        num=stod(line.substr(pos_open));
        income_sum+=num;
        pos_open=line.find('[')+1;
        pos_close=line.find(']');
        str=line.substr(pos_open,pos_close-pos_open);
        if (str=="BasicSalary") {BasicSalary_sum+=num;}
        else if (str=="Bonus") {Bonus_sum+=num;}
        else if (str=="Investment") {Investment_sum+=num;}
        else if (str=="PocketMoney") {PocketMoney_sum+=num;}
        else if (str=="Gifts") {Gifts_sum+=num;}
        else if (str=="LotteryPrizes") {LotteryPrizes_sum+=num;}
    }
    cout<<"Sum of income:                   $"<<income_sum<<endl;
    cout<<"Sum of income in Basic Salary:   $"<<BasicSalary_sum<<" ,which is "<<BasicSalary_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Bonus:          $"<<Bonus_sum<<" ,which is "<<Bonus_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Investment:     $"<<Investment_sum<<" ,which is "<<Investment_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Pocket Money:   $"<<PocketMoney_sum<<" ,which is "<<PocketMoney_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Gifts:          $"<<Gifts_sum<<" ,which is "<<Gifts_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Lottery Prizes: $"<<LotteryPrizes_sum<<" ,which is "<<LotteryPrizes_sum/income_sum*100<<" % in total income."<<endl;
    fin.close();
    fin.open("expense.txt");
    if(fin.fail()){cout<<"Error in file opening!"<<endl;exit(1);}
    double expenses_sum=0,EHousehold_sum=0,ETransport_sum=0,EPersonalcare_sum=0,EFoodandBeverage_sum=0,ELifestyle_sum=0,EShopping_sum=0,EInvestment_sum=0,EGifts_sum=0,EOthers_sum=0;
    while(getline(fin,line))
    {
        pos_open=line.find('$')+1;
        num=stod(line.substr(pos_open));
        expenses_sum+=num;
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
        if (str=="Household") {EHousehold_sum+=num;}
        else if (str=="Transport") {ETransport_sum+=num;}
        else if (str=="Personalcare") {EPersonalcare_sum+=num;}
        else if (str=="Food & Beverage") {EFoodandBeverage_sum+=num;}
        else if (str=="Lifestyle") {ELifestyle_sum+=num;}
        else if (str=="Shopping") {EShopping_sum+=num;}
        else if (str=="Investment") {EInvestment_sum+=num;}
        else if (str=="Gifts") {EGifts_sum+=num;}
        else if (str=="Others") {EOthers_sum+=num;}
        cout<<"Sum of expenses:                   $"<<expenses_sum<<endl;
        cout<<"Sum of expenses in Household:      $"<<EHousehold_sum<<" ,which is "<<EHousehold_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Transport:      $"<<ETransport_sum<<" ,which is "<<ETransport_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Personal Care:  $"<<EPersonalcare_sum<<" ,which is "<<EPersonalcare_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Food & Beverage:$"<<EFoodandBeverage_sum<<" ,which is "<<EFoodandBeverage_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Lifestyle:      $"<<ELifestyle_sum<<" ,which is "<<ELifestyle_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Shopping:       $"<<EShopping_sum<<" ,which is "<<EShopping_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Investment:     $"<<EInvestment_sum<<" ,which is "<<EInvestment_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Gifts:          $"<<EGifts_sum<<" ,which is "<<EGifts_sum/expenses_sum*100<<" % in total expenses."<<endl;
        cout<<"Sum of expenses in Others:         $"<<EOthers_sum<<" ,which is "<<EOthers_sum/expenses_sum*100<<" % in total expenses."<<endl;
    }
}
