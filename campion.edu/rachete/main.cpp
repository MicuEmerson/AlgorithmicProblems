#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
using namespace std;

ifstream fin("rachete.in");
ofstream fout("rachete.out");


int main()
{

    int n,i,unu=0,doi=0,trei=0,x;
   fin>>n;
   for(i=1;i<=n;i++){
    fin>>x;
    if(x==1){
        unu++;
    }
    else if(x==2){
        doi++;
    }
    else{
        trei++;
    }
   }

   i=1;
   while(i<=unu){
    fout<<"1"<<" ";
    i++;
   }
   i=1;
   while(i<=doi){
    fout<<"2"<<" ";
    i++;
   }
   i=1;
   while(i<=trei){
    fout<<"3"<<" ";
    i++;
   }


}
