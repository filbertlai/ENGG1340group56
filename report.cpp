#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
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
        num=stoi(line.substr(pos_open));
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
    
}
