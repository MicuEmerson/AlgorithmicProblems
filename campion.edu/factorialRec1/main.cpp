#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
#include <set>
#include <queue>
#include <stack>a
#include <deque>
#include <iomanip>
using namespace std;
ifstream fin("text.txt");
ofstream fout("secv3.out");
const int MAXN=100005;
int t,h1,h2,a1,a2;
long long d1,d2;
int e[MAXN];

void eratostene()
{

    for(int i=2; i<=MAXN; i++) e[i]=1;
    for(int i=2; i<=MAXN; i++)
        if(e[i])
            for(int j=i+i; j<=MAXN; j+=i)
                e[j]=0;
}

bool start1(int h1,int a1, long long d1, int h2, int a2, long long  d2)
{
    long long runda=1;
    while(1)
    {
        int c_d1=d1;
        int c_d2=d2;
        if(e[runda]==1)
        {
            d1*=runda;
            d2*=runda;
        }

        if(d1-a2>0) h2-=(d1-a2);
        if(h2<1) return true;
        if(d2-a1>0) h1-=(d2-a1);
        if(h1<1) return false;

        d1=c_d1;
        d2=c_d2;
        runda++;
        if(a1)a1--;
        if(a2)a2--;

    }
}

int main()
{

    eratostene();

    cin>>t;
    while(t--)
    {

       cin>>h1>>a1>>d1>>h2>>a2>>d2;

        bool incepePrimul=start1(h1,a1,d1,h2,a2,d2);
        bool incepeAlDoilea=start1(h2,a2,d2,h1,a1,d1);

        if(incepePrimul==true && incepeAlDoilea==false) cout<<"1\n";
        else if(incepePrimul==false && incepeAlDoilea==true) cout<<"2\n";
        else cout<<"3\n";

    }

  return 0;
}

