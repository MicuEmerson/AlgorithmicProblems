#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("flori1.in");
ofstream fout("flori1.out");

int n,h,v[105],s,ok;

int main()
{

    int i,j;
    fin>>n>>h;

    for(i=1; i<=n; i++)
    {
        fin>>v[i];
        s+=v[i];
    }

    s+=(n*(n+1))/2;
    fout<<s<<endl;

    i=1;
    while(ok==0)
    {

        sort(v+1,v+n+1);
        for(j=1; j<=i && ok==0; j++)
        {
           v[j]++;
           if(v[j]==h){
            ok=1;
            break;
           }
        }
        if(ok==0){
        i++;

        }
    }
    fout<<i-1;



}

