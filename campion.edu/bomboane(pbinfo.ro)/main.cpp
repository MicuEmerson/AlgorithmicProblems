#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bomboane.in");
ofstream fout("bomboane.out");


typedef struct
{
    int elem;
    int poz;
} vct;

typedef struct
{
    int st;
    int dr;
    int cate;
} vct2;

vct v[1005];
vct2 aux[1005];
int i,j,n,s,pozCoada,pozInceput,nrAux;
void sortare(vct v[1005], int n)
{
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(v[i].elem>v[j].elem)
            {
                swap(v[i],v[j]);
            }
        }
    }
}

int main()
{

    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i].elem;
        v[i].poz=i;
        s+=v[i].elem;
    }
    sortare(v,n);

    if(s%n!=0)
    {
        fout<<"-1";
    }
    else
    {
        s/=n;
        if(v[1].elem==v[n].elem)
        {
            fout<<"0";
        }
        else
        {
            pozCoada=n;
            pozInceput=1;
            while(v[pozCoada].elem!=v[pozInceput].elem)
            {
                while(v[pozCoada].elem > v[pozCoada-1].elem )
                {
                    nrAux++;
                    aux[nrAux].cate=s-v[pozInceput].elem;
                    aux[nrAux].st=v[pozCoada].poz;
                    aux[nrAux].dr=v[pozInceput].poz;
                    v[pozCoada].elem-=aux[nrAux].cate;
                    v[pozInceput].elem+=aux[nrAux].cate;
                    if(v[pozInceput].elem!=s){
                        pozCoada--;
                    }
                    else{
                        pozInceput++;
                    }
                }
                pozCoada--;
            }
        }
    }
    fout<<nrAux<<endl;
    for(i=1;i<=nrAux;i++){
        fout<<aux[i].st<<" "<<aux[i].dr<<" "<<aux[i].cate<<endl;
    }
}

