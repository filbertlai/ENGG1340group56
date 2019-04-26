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
    if(fin.fail()){cout<<"You have not made any record on income!"<<endl;exit(1);}
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
    double BasicSalary_percentage=0; if (BasicSalary_sum!=0){BasicSalary_percentage=BasicSalary_sum/income_sum*100;}
    double Bonus_percentage=0; if (Bonus_sum!=0){Bonus_percentage=Bonus_sum/income_sum*100;}
    double Investment_percentage=0; if (Investment_sum!=0){Investment_percentage=Investment_sum/income_sum*100;}
    double PocketMoney_percentage=0; if (PocketMoney_sum!=0){PocketMoney_percentage=PocketMoney_sum/income_sum*100;}
    double Gifts_percentage=0; if (Gifts_sum!=0){Gifts_percentage=Gifts_sum/income_sum*100;}
    double LotteryPrizes_percentage=0; if (LotteryPrizes_sum!=0){LotteryPrizes_percentage=LotteryPrizes_sum/income_sum*100;}
    cout<<"Sum of income:                     $"<<income_sum<<endl;
    cout<<"Sum of income in Basic Salary:     $"<<BasicSalary_sum<<" ,which is "<<BasicSalary_percentage<<" % in total income."<<endl;
    cout<<"Sum of income in Bonus:            $"<<Bonus_sum<<" ,which is "<<Bonus_percentage<<" % in total income."<<endl;
    cout<<"Sum of income in Investment:       $"<<Investment_sum<<" ,which is "<<Investment_percentage<<" % in total income."<<endl;
    cout<<"Sum of income in Pocket Money:     $"<<PocketMoney_sum<<" ,which is "<<PocketMoney_percentage<<" % in total income."<<endl;
    cout<<"Sum of income in Gifts:            $"<<Gifts_sum<<" ,which is "<<Gifts_percentage<<" % in total income."<<endl;
    cout<<"Sum of income in Lottery Prizes:   $"<<LotteryPrizes_sum<<" ,which is "<<LotteryPrizes_percentage<<" % in total income."<<endl;
    fin.close();
    fin.open("expense.txt");
    if(fin.fail()){cout<<"You have not made any record on income!"<<endl;exit(1);}
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
    }
    double EHousehold_percentage=0; if (EHousehold_sum!=0){EHousehold_percentage=EHousehold_sum/expenses_sum*100;}
    double ETransport_percentage=0; if (ETransport_sum!=0){ETransport_percentage=ETransport_sum/expenses_sum*100;}
    double EPersonalcare_percentage=0; if (EPersonalcare_sum!=0){EPersonalcare_percentage=EPersonalcare_sum/expenses_sum*100;}
    double EFoodandBeverage_percentage=0; if (EFoodandBeverage_sum!=0){EFoodandBeverage_percentage=EFoodandBeverage_sum/expenses_sum*100;}
    double ELifestyle_percentage=0; if (ELifestyle_sum!=0){ELifestyle_percentage=ELifestyle_sum/expenses_sum*100;}
    double EShopping_percentage=0; if (EShopping_sum!=0){EShopping_percentage=EShopping_sum/expenses_sum*100;}
    double EInvestment_percentage=0; if (EInvestment_sum!=0){EInvestment_percentage=EInvestment_sum/expenses_sum*100;}
    double EGifts_percentage=0; if (EGifts_sum!=0){EGifts_percentage=EGifts_sum/expenses_sum*100;}
    double EOthers_percentage=0; if (EOthers_sum!=0){EOthers_percentage=EOthers_sum/expenses_sum*100;}
    cout<<"Sum of expenses:                   $"<<expenses_sum<<endl;
    cout<<"Sum of expenses in Household:      $"<<EHousehold_sum<<" ,which is "<<EHousehold_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Transport:      $"<<ETransport_sum<<" ,which is "<<ETransport_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Personal Care:  $"<<EPersonalcare_sum<<" ,which is "<<EPersonalcare_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Food & Beverage:$"<<EFoodandBeverage_sum<<" ,which is "<<EFoodandBeverage_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Lifestyle:      $"<<ELifestyle_sum<<" ,which is "<<ELifestyle_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Shopping:       $"<<EShopping_sum<<" ,which is "<<EShopping_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Investment:     $"<<EInvestment_sum<<" ,which is "<<EInvestment_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Gifts:          $"<<EGifts_sum<<" ,which is "<<EGifts_percentage<<" % in total expenses."<<endl;
    cout<<"Sum of expenses in Others:         $"<<EOthers_sum<<" ,which is "<<EOthers_percentage<<" % in total expenses."<<endl;
}
