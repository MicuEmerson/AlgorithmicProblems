#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("text.txt");
ofstream fout("cladiri2.out");

int pal(int n)
{

    int nr=0;
    while(n>0)
    {
        nr=nr*10+n%10;
        n/=10;
    }
    return nr;
}

int cifraMax(int n)
{

    int c=0;
    while(n>0)
    {
        if(n%10>c)
        {
            c=n%10;
        }
        n/=10;
    }
    return c;

}

int isPal(int n)
{
    int cn;
    cn=n;
    cn=pal(n);
    if(n==cn)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare(int v[10000], int n){

 for(int i=1;i<=n;i++){
    cout<<v[i]<<" ";
 }
 cout<<endl;

}

int sCifre(int n){
 int  s=0;
 while(n>0){
    s+=n%10;
    n/=10;
 }
return s;
}

int celMaiApropiatPalindrom(int n){
int  cn=n;
 while(isPal(n)==0){
    n++;
 }
 cout<<n<<" "<<cn<<" ";
 n=n-cn;

 cout<<sCifre(n)<<endl;




}

int main()
{
    int n,i,k,cMax=0,nrTurnuriMax=0,nrAdaugari=0,numarPalindroame=0;
    int v[10000];
    int fata[10000];
    int nepal[10000],dimNe=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
        fata[i]=v[i];
        if(isPal(fata[i])==1){
            numarPalindroame++;
        }
        else{
             nepal[++dimNe]=fata[i];
        }

        if(cMax<cifraMax(v[i]))
        {
            cMax=cifraMax(v[i]);
        }
    }

    // nr turnuri max
    for(i=1; i<=n; i++)
    {
        if(cifraMax(v[i])==cMax)
        {
            nrTurnuriMax++;
        }
    }

    for(i=1;i<=dimNe;i++){
        nrAdaugari+=celMaiApropiatPalindrom(nepal[i]);
    }



    cout<<cMax<<" "<<nrTurnuriMax<<endl;
    cout<<numarPalindroame<<endl;
    cout<<nrAdaugari;

}
/*

int main(){

 int n;

 fin>>n;


}
*/




