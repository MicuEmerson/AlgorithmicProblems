#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;
ifstream fin("secv4.in");
ofstream fout("secv4.out");

const int MAXN=1e5+5;

int n,X,Y;
double v[MAXN],s[MAXN];

int main()
{
    cin>>n>>X>>Y;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+abs(log10(v[i]));
        if(v[i]>0)
    }
    for(int i=1;i<=n;i++){
        cout<<s[i]<<" ";
    }















}
