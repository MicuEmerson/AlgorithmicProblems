#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("numere12.in");
ofstream fout("numere12.out");

int isSpecial(int n){

 int cn=n;
 while(n>0){
    if(n%10!=0 && cn%(n%10)!=0){
        return 0;
    }
    n/=10;
 }
 return 1;


}

int main()
{

     int a,b,c=0;
     fin>>a>>b;
     for(int i=a;i<=b;i++){
        if(isSpecial(i)==1){
            c++;
        }
     }
     fout<<c;

}
