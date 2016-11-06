#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");
const int MAXN=1500000;
int n;
int e[MAXN];

void eratostene()
{
    for(int  i=2; i<MAXN; i++) e[i]=1;

    for(int i=2; i<MAXN; i++)
        if(e[i]==1)
        {
            n--;
            if(n==-1)
            {
                fout<<1LL* i*1LL * i;
                break;
            }
            for(int j=i+i; j<MAXN; j+=i)
                e[j]=0;
        }
}

int main()
{
    fin>>n;
    eratostene();
}
