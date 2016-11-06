#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("orase.in");
ofstream fout("orase.out");

const int MAXN=5e4+5;
pair <int , int> v[MAXN];
int n,m,maxy=-1,poz,sol=-1;

int main()
{

    fin>>m>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i].first>>v[i].second;
        if(v[i].first+v[i].second>maxy)
        {
            maxy=v[i].first+v[i].second;
            poz=i;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(sol<v[poz].second + v[i].second + abs(v[poz].first - v[i].first) && i!=poz)
            sol=v[poz].second + v[i].second + abs(v[poz].first - v[i].first);
    }
    fout<<sol;




}







