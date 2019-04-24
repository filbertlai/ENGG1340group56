#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    string name = "Apple";
    int num_of_x = (60-name.length())/2;
    while (True){
        cout<<setfill('x')<<setw(60)<<"x"<<endl;
        cout<<x*num_of_x<<"Welcome back! "<<name<<"What can we help you?"<<x*num_of_x<<endl;
    return 0;
    }
}
