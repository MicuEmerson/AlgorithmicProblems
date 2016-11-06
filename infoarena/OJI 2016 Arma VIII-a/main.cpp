#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
ifstream fin("text.txt");
ofstream fout("secvente.out");
const int MAXN=45005;
int n,p,x,eratostene[MAXN],v[MAXN],dim;
long long rezTotal;


int cmmdc(int a, int b){

  if(a%b==0) return b;
  cmmdc(b,a%b);

}

int laPutere(int nr, int p){

   int rez=1;
   while(p--) rez*=nr;
   return rez;

}

void eratostene(){

 for(int i=2;i<=MAXN;i++) e[i]=1;
 for(int i=2;i<=MAXN;i++)
    if(e[i]){
        v[++dim]=i;
        for(int j=i+i;j<=MAXN;j+=i;)
             e[i]=0;
    }
}

void factoriPrimi(int n)
{

    int f[50000],p[50000];
    int putere,dim=0;

    for(int i=1; v[i] * v[i] <= n; i++)
    {
        if(n%v[i]==0)
        {
            putere=0;
            while(n%v[i]==0)
            {
                putere++;
                n/=v[i];
            }
            dim++;
            f[dim]=v[i];
            p[dim]=putere;
        }
    }
    if(n!=1)
    {
        dim++;
        f[dim]=n;
        p[dim]=1;
    }

    int divCom=p[1];
    for(int i=2;i<=dim;i++)
        divCom=cmmdc(divCom,p[i]);

    long long rez=1;
    for(int i=1;i<=dim;i++)
        rez*=laPutere(f[i],p[i]/divCom);

    cout<<divCom<<"\n";
    rezTotal+=rez;
}


int main()
{

   fin>>p>>n;
   for(int i=1;i<=n;i++){

        fin>>x;
        factoriPrimi(x);
   }
   cout<<endl<<rezTotal;



}
