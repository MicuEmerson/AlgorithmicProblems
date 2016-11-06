#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("secvsummax.in");
ofstream fout("secvsummax.out");



int main()
{
   int n,x,i,poz,rez=-999999,poz2;
   int s[100005];
   fin>>n;
   for(i=1;i<=n;i++){
    fin>>x;
    if(i==1){
        s[i]=x;
    }
    else{
        s[i]=x;
        if(s[i-1]>0){
            s[i]+=s[i-1];
        }
    }
   }

   for(i=1;i<=n;i++){
     if(s[i]>rez){
        rez=s[i];
        poz=i;
     }
   }
   poz2=poz;
   while(s[poz2]>0){
    poz2--;
   }
   poz2++;

   fout<<poz2<<" "<<poz;



}
