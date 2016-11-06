#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("vanatoare.in");
ofstream fout("vanatoare.out");


int main()
{
    int fib[10000];
    int nrFib=-1;
    int rA,rB;

    fin>>rA;
    fin>>rB;

    fib[++nrFib]=1;
    fib[++nrFib]=1;

    while(fib[nrFib]/2+1<=rA && fib[nrFib]/2<=rB && fib[nrFib]%2==1 || fib[nrFib]/2<=rA && fib[nrFib]/2<=rB && fib[nrFib]%2==0)
    {

        if(fib[nrFib]%2==1)
        {
            rA=rA-fib[nrFib]/2-1;
            rB=rB-fib[nrFib]/2;
        }
        else
        {
            rA=rA-fib[nrFib]/2;
            rB=rB-fib[nrFib]/2;
        }

        //cout<<fib[nrFib]<<"  RA: "<<rA<<"  RB: "<<rB<<endl;


        fib[++nrFib]=fib[nrFib-1]+fib[nrFib-2];

    }

    fout<<--nrFib<<endl;
    fout<<rA<<endl;
    fout<<rB<<endl;






}
