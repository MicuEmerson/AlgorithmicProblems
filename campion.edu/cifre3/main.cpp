#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("cifre3.in");
ofstream fout("cifre3.out");

int fA[100],fB[100];



int main()
{
    int a,b,v[100],dimV=0,i;
    fin>>a>>b;

    if(a==0)
    {
        v[++dimV]=a%10;
        fA[a%10]++;
    }
    else
    {
        while(a>0)
        {

            v[++dimV]=a%10;
            fA[a%10]++;
            a/=10;

        }
    }

    if(b==0)
    {
        v[++dimV]=b%10;
        fB[b%10]++;
    }
    else
    {
        while(b>0)
        {
            v[++dimV]=b%10;
            fB[b%10]++;
            b/=10;
        }
    }

    for(i=0;i<=9;i++){
        if(fA[i]>0 && fB[i]>0){
            fout<<i<<" ";
        }
    }
    fout<<endl;


    sort(v+1,v+1+dimV);
    for(i=dimV;i>=1;i--){
        fout<<v[i];
    }



}
