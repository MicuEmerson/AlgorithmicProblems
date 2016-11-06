#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("moretime.in");
ofstream fout("moretime.out");

const int MAXN=1e4+5;
int n,dim,maxy=-1,x,y,gasit=-999;
pair <int, int> a[MAXN];
pair <int, int> b[MAXN];
int suma[MAXN],rest[MAXN];

bool isOk(int n)
{
    int c=n%10;

    while(n>9)
    {
        n/=10;
    }
    if(c==n)
    {
        return true;
    }
    return false;
}


int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i].first>>a[i].second;
    }

    for(int i=1; i<=n; i++)
    {
        if(isOk(a[i].first))
        {
            dim++;
            b[dim].first=a[i].first;
            b[dim].second=a[i].second;
        }
    }
    for(int i=1; i<=dim; i++)
    {
        suma[i]=suma[i-1]+b[i].second;
        rest[i]=suma[i]%dim;
    }

    for(int i=1; i<=dim; i++)
    {
        if(rest[i]==0)
        {
            if(maxy<i-1)
            {
                maxy=i;
                x=1;
                y=i;
                gasit=1;
            }
        }
        else
        {
            for(int j=i+1; j<=n; j++)
            {
                if(rest[i]==rest[j]){
                    if(maxy<j-i+1){
                        maxy=j-i+1;
                        x=i+1;
                        y=j;
                        gasit=0;
                    }
                }
            }
        }
    }
    fout<<dim<<"\n";
    if(gasit==1){
        fout<<maxy<<"\n";
    }
    else{
        fout<<maxy-1<<"\n";
    }
    for(int i=x;i<=y;i++){
        fout<<b[i].first<<" ";
    }



}
