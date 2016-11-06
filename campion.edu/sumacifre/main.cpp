#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("sumacifre.in");
ofstream fout("sumacifre.out");

int s,n;

void suma(int &n)
{
    int v[10],dim=0;

    while(n>0)
    {
        v[++dim]=n%10;
        n/=10;
    }

    for(int i=dim; i>1; i--)
    {
        n=n*10+abs(v[i]-v[i-1]);

    }
    s+=n;
}


int main()
{
    int k;
    fin>>n>>k;

    while(k--)
    {
        if(n>9)
        {
            suma(n);
        }
        else
        {
            s+=n*(k+1);
            k=0;
        }
    }
    fout<<s;


}
