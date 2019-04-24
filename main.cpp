#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string name = "Test";
    int number_of_x=50,num_of_x = (50-name.length()-36)/2;;
    if ((50-name.length()-36)%2==1) {number_of_x--;}
    while (1)
    {
        cout<<setfill('x')<<setw(number_of_x)<<"x"<<endl;
        for(int i=0;i<num_of_x;i++)
        {
            cout<<"x";
        }
        cout<<"Welcome back! "<<name<<" What can we help you?";
        for(int i=0;i<num_of_x;i++)
        {
            if(i==num_of_x-1){cout<<"x"<<endl; break;}
            cout<<"x";
            
        }
    }
    return 0;
}
