/*
#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

const int MAXN=3e4+5;
int n,X,Y,v[MAXN],t[MAXN],s1[MAXN],s2[MAXN];
float maxy=-((1<<31)-1);
deque <int> deq1,deq2;

void insert1(int poz){

   while(!deq1.empty() && s1[deq1.back()] >= s1[poz] ) deq1.pop_back();
   deq1.push_back(poz);
}

int get_min1(int poz){

   while(!deq1.empty() && deq1.front() <= poz) deq1.pop_front();
   return s1[deq1.front()];
}

void insert2(int poz){

    while(!deq2.empty() && s2[deq2.back()] <= s2[poz] ) deq2.pop_back();
    deq2.push_back(poz);
}

int get_max2(int poz){

   while(!deq2.empty() && deq2.front() <= poz) deq2.pop_front();
   return s2[deq2.front()];
}

bool functie(int dimSec){

   while(!deq1.empty()) deq1.pop_back();
   while(!deq2.empty()) deq2.pop_back();


   for(int i=dimSec;i<=n;i++){





   }





}

int cautare_binara()
{
    int st=X, dr=Y, m, last=-1;

    while(st<=dr)
    {
        m=(st+dr)/2;
        if( functie(m) )
        {
            last=m;
            st=m+1;
        }
        else dr=m-1;
    }

    return last;
}


int main()
{
    cin>>n>>X>>Y;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
        s1[i]=s1[i-1]+v[i];
    }
    for(int i=1; i<=n; i++)
    {
        fin>>t[i];
        s2[i]=s2[i-1]+t[i];
    }
}
*/



#include<bits/stdc++.h>
using namespace std;

int i,n,u,l,a[30005],b[30005],deq[30005];
double st,dr=1000,pivot,rs,aux[30005];

bool Check(double x) {
    int st=1,dr=0,i;

    for(i=1;i<=n;++i) aux[i]=aux[i-1]+a[i]-x*b[i];

    for(i=l;i<=n;++i)
    {
      while(st<=dr && aux[deq[dr]]>=aux[i-l]) --dr;
      deq[++dr]=i-l;
      if(deq[st]<i-u) ++st;
      if(aux[i]>=aux[deq[st]]) return 1;
    }

    return 0;
}

int main()
{
  ifstream cin("secv3.in");
  ofstream cout("secv3.out");

  ios_base::sync_with_stdio(0); cin.tie(0);

  cin>>n>>l>>u;
  for(i=1;i<=n;++i) cin>>a[i];
  for(i=1;i<=n;++i) cin>>b[i];

  while(st<=dr)
  {
    pivot=(st+dr)/2.0;
    if(Check(pivot)) rs=pivot,st=pivot+0.01;
    else dr=pivot-0.01;
  }

  cout<<setprecision(2)<<fixed<<rs<<'\n';

 return 0;
}
