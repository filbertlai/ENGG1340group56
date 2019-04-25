#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    double income_sum=0,expense_sum=0;
    int pos_open,pos_close;
    fin.open("income.txt");
    if(fin.fail()){cout<<"Error in file opening!"<<endl;exit(1);}
    string line;
    while(getline(fin,line)){pos_open=line.find('$'+1),income_sum+=stoi(line.substr(pos_open))}
    cout<<income_sum;
}
