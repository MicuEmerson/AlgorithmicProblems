#include <iostream>
#include <fstream>
#define MAX 333380
using namespace std;
ifstream fin("sume3.in");
ofstream fout("sume3.out");
int n,s[MAX];


int main()
{
    int ant=1,rez,i;

    fin>>n;
    n=n/3*3;
    s[0]=s[1]=s[2]=1;
    for(i=3;i<=n;i=i+3){

        rez=(ant + s[i/3])%1000000000;
        if(i<=MAX+3){
            s[i]=s[i+1]=s[i+2]=rez;
        }
        ant=rez;
    }
    if(n<=3896){
         fout<<rez;
    }
    else{

        for(i=100000000;i>=1;i=i/10){
            fout<<rez/i%10;
        }

    }
}
