#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("bile2.in");
ofstream fout("bile2.out");

char c[10000];
int n,v[2005],dim,x,i=1;
queue < int > Q;
stack < int > S;
bool gasit=true;
int main()
{

    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        Q.push(x);
    }
    for(int i=1; i<=n; i++) cin>>v[i];


    while(!Q.empty() || !S.empty())
    {
        if(S.empty() || S.top()!=v[i])
        {
            while(!Q.empty() && Q.front()!=v[i])
            {
                c[++dim]='I';
                S.push(Q.front());
                Q.pop();
            }
            if(!Q.empty() && Q.front()==v[i])
            {
                c[++dim]='I';
                c[++dim]='O';
                Q.pop();
            }
            else
            {
                gasit=false;
                break;
            }
        }
        else
        {
            c[++dim]='O';
            S.pop();
        }
        i++;
    }

    if(!gasit) fout<<"imposibil";
    else for(int i=1; i<=dim; i++) fout<<c[i];


}
