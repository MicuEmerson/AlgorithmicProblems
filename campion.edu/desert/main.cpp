#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
using namespace std;

ifstream fin("desert.in");
ofstream fout("desert.out");

int n;
double k,p;

double f(int n)
{
    double d;
    if(n==1)
    {
        return k*100.0/p;
    }
    if(n==2)
    {
        return 2*k*100.0/p;
    }
    d=k*100.0/p/(2*n-3);
    return d+f(n-1);
}



int main()
{
    fin>>n>>k>>p;
    fout<<fixed<<setprecision(3)<<f(n);



}
