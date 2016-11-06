#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

ifstream fin("numar2.in");
ofstream fout("numar2.out");


long long cubPerfect(long long n)
{

    int nr=1;
    int i=1;
    long long rez;
    while(i<=n)
    {
        rez=nr*nr*nr;
        nr++;
        i++;
    }
    return rez;

}

int isCubPerfect(long long n)
{

    int nr=1;
    while(cubPerfect(nr)<n)
    {
        nr++;
    }
    if(cubPerfect(nr)==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




int isPal(long long n)
{
    long long cn,nr;
    cn=n;
    nr=0;
    while(n>0)
    {
        nr=nr*10+n%10;
        n/=10;
    }
    if(nr==cn)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}



int main()
{

    long long n,v[10]={0, 1, 8, 343, 1331, 1030301, 1367631, 1003003001};
    long long difMax=1003003001,x;
    int gasit=0;
    fin>>n;
    for(int i=0;i<8;i++){
        if(v[i]==n){
            fout<<v[i];
            gasit=1;
        }
        else if(n-v[i]<difMax && n>v[i]){
                difMax=n-v[i];
                x=v[i];
            }
    }

   if(gasit==0){
     fout<<x;
   }











}
