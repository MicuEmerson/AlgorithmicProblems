#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("energii.in");
ofstream fout("energii.out");

const int MAXG=5e3+5;
int n,g,energie,cost;
int a[MAXG],b[MAXG];

int main()
{
    fin>>n>>g;
    while(n--)
    {
        fin>>cost>>energie;

        for(int j=1; j<=g; j++)
        {
            a[j]=b[j];

            if(j>=cost)
            {
                a[j]=max( a[j],  b[j-cost] + energie);
            }
        }

        for(int j=1; j<=g; j++) b[j]=a[j];
    }

    if(b[g]<g) fout<<"-1";
    else fout<<b[g];

    return 0;
}
