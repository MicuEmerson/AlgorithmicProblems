#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("text.txt");
ofstream fout("cladiri1.out");

typedef struct
{

    int suma;
    int cantitate;

} carte;

void sortare(carte v[1005], int n)
{

    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(v[i].suma < v[j].suma)
            {
                swap(v[i],v[j]);
            }
        }
    }
}


void eliminare(carte v[1005], int &n, int poz)
{

    int i;
    for(i=poz; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;

}

void fuzionare(carte v[1005], int &n)
{

    int i,j;
    for(i=1; i<n; i++)
    {
        j=i+1;
        if(v[i].suma==v[j].suma)
        {
            while(v[i].suma==v[j].suma)
            {
                v[i].cantitate+=v[j].cantitate;
                eliminare(v,n,j);
            }
        }

    }
}

int main()
{

    int n,cate,x,i;
    char y;
    char myvec[255];
    myvec.clear();
    carte b[1005],s[1005];
    int dimB=0,dimS=0;
    cin>>n>>cate;
    for(i=1; i<=n; i++)
    {
        cin>>y;

        if(y=='B')
        {
            cin>>x;
            dimB++;
            b[dimB].suma=x;
            cin>>x;
            b[dimB].cantitate=x;
        }
        else
        {
            cin>>x;
            dimS++;
            s[dimS].suma=x;
            cin>>x;
            s[dimS].cantitate=x;
        }
    }
    sortare(s,dimS);
    sortare(b,dimB);
    fuzionare(s,dimS);
    fuzionare(b,dimB);
    if(dimS<cate && dimB>=cate)
    {
        for(i=1; i<=dimS; i++)
        {
            cout<<"S "<<s[i].suma<<" "<<s[i].cantitate<<endl;
        }
        for(i=1; i<=cate; i++)
        {
            cout<<"B "<<b[i].suma<<" "<<b[i].cantitate<<endl;
        }
    }
    else if(dimS>=cate && dimB<cate)
    {
        for(i=1; i<=cate; i++)
        {
            cout<<"S "<<s[i].suma<<" "<<s[i].cantitate<<endl;
        }
        for(i=1; i<=dimB; i++)
        {
            cout<<"B "<<b[i].suma<<" "<<b[i].cantitate<<endl;
        }
    }
    else if(dimS<cate && dimB<cate)
    {
        for(i=1; i<=dimS; i++)
        {
            cout<<"S "<<s[i].suma<<" "<<s[i].cantitate<<endl;
        }
        for(i=1; i<=dimB; i++)
        {
            cout<<"B "<<b[i].suma<<" "<<b[i].cantitate<<endl;
        }
    }
    else
    {
        for(i=1; i<=cate; i++)
        {
            cout<<"S "<<s[i].suma<<" "<<s[i].cantitate<<endl;
        }
        for(i=1; i<=cate; i++)
        {
            cout<<"B "<<b[i].suma<<" "<<b[i].cantitate<<endl;
        }
    }















}

















