#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int cmd;
    
    while (1)
    {
        cout<<setfill('x')<<setw(56)<<"x"<<endl;
        for(int i=0;i<10;i++){cout<<"x";}
        cout<<" Welcome back to Accounting System! ";
        for(int i=0;i<10;i++){if(i==9){cout<<"x"<<endl; break;}cout<<"x";}
        cout<<setfill('x')<<setw(56)<<"x"<<endl;
        
        cout<<endl<<"*******Changing the records of income or expense*******"<<endl;
        cout<<"1)  Add a record"<<endl;
        cout<<"2)  Delete a record"<<endl;
        cout<<"3)  Edit a record"<<endl;
        cout<<endl<<"****Looking for specific record(s)/statistic report****"<<endl;
        cout<<"4)  View records of specific category or account"<<endl;
        cout<<"5)  View records sorted by date or amount"<<endl;
        cout<<"6)  Search for specific record(s)"<<endl;
        cout<<"7)  Show Statistic report of financial state"<<endl;
        cout<<endl<<"*****************Preset budget/records*****************"<<endl;
        cout<<"8)  Set a budget for the next month"<<endl;
        cout<<"11) Preset the regular income or expenses"<<endl;
        cout<<endl<<"************************Setting************************"<<endl;
        cout<<"9)  Editing password"<<endl;
        cout<<"10) Customize style"<<endl;
        cout<<endl<<"Please enter the number of command: ";
        cin>>cmd;
        if (cmd==1){}
        
        else if (cmd==2){}
        
        else if (cmd==3){}
        
        else if (cmd==4){}
        
        else if (cmd==5){}
        
        else if (cmd==6){}
        
        else if (cmd==7){}
        
        else if (cmd==8){}
        
        else if (cmd==9){}
        
        else if (cmd==10){}
    
    
    }
    return 0;
}
