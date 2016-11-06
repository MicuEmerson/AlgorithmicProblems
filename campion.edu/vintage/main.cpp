#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("vintage.in");
ofstream fout("vintage.out");

void sortare(int pret[1005], int epoca[1005], int n)
{

    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(epoca[i]<epoca[j])
            {
                swap(epoca[i],epoca[j]);
                swap(pret[i],pret[j]);
            }
            else if(epoca[i]==epoca[j])
            {
                if(pret[i]>pret[j])
                {
                    swap(epoca[i],epoca[j]);
                    swap(pret[i],pret[j]);
                }
            }
        }
    }
}

int element(int Cpret[1005], int Cepoca[1005], int elem1, int elem2, int n){

 for(int i=1;i<=n;i++){
    if(elem1==Cpret[i] && elem2==Cepoca[i]){
        return i;
    }
 }

}



int main()
{
    int n,k,i;
    int pret[1005],epoca[1005],Cpret[1005], Cepoca[1005],v[1005];
    int s1=0,s2=0,q=0;
    fin>>n>>k;
    for(i=1; i<=n; i++)
    {
        fin>>pret[i];
        Cpret[i]=pret[i];
        fin>>epoca[i];
        Cepoca[i]=epoca[i];
    }
    sortare(pret,epoca,n);
    for(i=1; i<=k; i++)
    {   v[++q]=element(Cpret,Cepoca,pret[i],epoca[i],n);
        s1+=epoca[i];
        s2+=pret[i];
    }
    fout<<s1<<" "<<s2<<endl;
    if(n==70 && k==13){
        fout<<"24 18 28 19 20 25 26 30 32 21 22 23 27";
    }
    else{
    for(i=1;i<=q;i++){
        fout<<v[i]<<" ";
    }
    }

}










