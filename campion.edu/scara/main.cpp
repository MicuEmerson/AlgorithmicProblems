#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("scara.in");
ofstream fout("scara.out");



int main(){


 long n;
 fin>>n;
 int x,y;
 y=(n-1)/4;
 if(y%2==0){
        x=(n-1)%4+y;

 }
 else{
    x=3-(n-1)%4+y;
 }
 fout<<x<<" "<<y;

}

