#include <iostream>
#include <algorithm>
#include <deque>
#include <fstream>
using namespace std;
ifstream fin("secv2.in");
ofstream fout("secv2.out");

const int MAXN=50005;
int n,k,v[MAXN],s[MAXN],miny = ((1<<30)-1),maxy=-((1<<30)-1),st,dr,stMin;


int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
        s[i]+=s[i-1]+v[i];
    }

    for(int i=k; i<=n; i++)
    {

        if(s[i-k]<miny)
        {
            miny=s[i-k];
            stMin=i-k+1;
        }

        if(maxy<s[i]-miny)
        {
            maxy=s[i]-miny;
            st=stMin;
            dr=i;
        }
    }
    fout<<st<<" "<<dr<<" "<<maxy;


}
