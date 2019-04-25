#include<fstream>
using namespace std;

int main()
{
    cout<<"Welcome to the statistic report of your income and expense!"<<endl;
    ifstream fin;
    double income_sum=0,expense_sum=0,BasicSalary_sum=0,Bonus_sum=0,Investment_sum=0,PocketMoney_sum=0,Gifts_sum=0,LotteryPrize_sum=0,num;
    string str;
    int pos_open,pos_close;
    fin.open("income.txt");
    if(fin.fail()){cout<<"Error in file opening!"<<endl;exit(1);}
    string line;
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
        else if (str=="LotteryPrize") {LotteryPrize_sum+=num;}
    }
    cout<<"Sum of income: $"<<income_sum<<endl;
    cout<<"Sum of income in Basic Salary: $"<<BasicSalary_sum<<" ,which is "<<BasicSalary_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Bonus: $"<<Bonus_sum<<" ,which is "<<Bonus_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Investment: $"<<Investment_sum<<" ,which is "<<Investment_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Pocket Money: $"<<PocketMoney_sum<<" ,which is "<<PocketMoney_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in Gifts: $"<<Gifts_sum<<" ,which is "<<Gifts_sum/income_sum*100<<" % in total income."<<endl;
    cout<<"Sum of income in LotteryPrize: $"<<LotteryPrize_sum<<" ,which is "<<LotteryPrize_sum/income_sum*100<<" % in total income."<<endl;
}
