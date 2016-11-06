#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subsecv.in");
ofstream fout("subsecv.out");


typedef struct
{

    int f;
    int poz;

} freg;

freg ff[10];

int main()
{
    int n,i;
    int v[10000],r;
    long long s[10000];
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    s[1]=v[1];
    ff[s[1]%n].f++;
    r=s[1]%n;
    if(r==0){
        cout<<"1 1";
    }
    else{
    for(i=2; i<=n; i++)
    {
        s[i]=v[i]+s[i-1];
        r=s[i]%n;
        if(r==0)
        {
            fout<<"1"<<" "<<i;
            break;
        }
        if(ff[s[i]%n].f==1)
        {
            fout<<ff[s[i]%n].poz+1<<" "<<i;
            break;
        }
        ff[s[i]%n].f++;
        ff[s[i]%n].poz=i;
    }
    }
}
