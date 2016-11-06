#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;
/*
ifstream fin("text.txt");
ofstream fout("vintage.out");

 long long nrDivComuni(long long x, int n){
  int nr=0;
  for(int i=1;i<=n;i++){
    if(x%i==0){
        nr++;
    }
  }
  return nr;

 }


int main()
{
    int n;
    long long x;
    cin>>n>>x;
    if(n<x){
         cout<<nrDivComuni(x,n)-1;
    }
    else{
    cout<<nrDivComuni(x,n);
    }
}
*/

long long n,x,cate;

int main()
{
    cin>>n>>x;
    for (int i=1; i<=n; i++)
    {
        if(x%i==0 && x/i<=n)
        {
            cate++;
        }
    }
    cout<<cate;
}
#include < iostream >
using namespace std;

unsigned short int sumaCifre ( int n )
{
    unsigned short int s=0;
    while(n!=0)
    {
        s=s+n%10;
        n=n/10;
    }
    return s;
}
int main()
{
    int n;
    cout<< "n=";
    cin>> n;
    cout<<"suma cifrelor:" << sumaCifre (n) ;
    return 0;
}


