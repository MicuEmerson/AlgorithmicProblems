#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

typedef struct
{

    int factori;
    int puteri;



} vvv;

vvv v[1000];

int n,m,nr,ok,dim,j;
long long s=1;

int isInVector(int elem)
{

    for(int i=1; i<=n; i++)
    {
        if(elem==v[i].factori)
        {
            return i;
        }
    }
    return -1;

}

int cmp(vvv a, vvv b)
{

    if(a.factori<b.factori)
    {
        return 1;
    }
    return 0;




}

void factoriPrimi(int numar)
{

    int i=0,nr=2,p;

    while(numar>1)
    {
        if(numar%nr==0)
        {
            p=0;
            while(numar%nr==0)
            {

                numar/=nr;
                p++;

            }
            int plm=isInVector(nr);
            if(plm==-1)
            {
                dim++;
                v[dim].factori=nr;
                v[dim].puteri=p;
            }
            else
            {
                v[plm].puteri+=p;
            }
        }
        nr++;
    }
}

int main()
{

    fin>>m>>n;

    for(int i=1; i<=n; i++)
    {
        int xx;
        fin>>xx;
        factoriPrimi(xx);

    }


    for(j=1 ; j<=dim ; j++)
    {
        if(v[j].puteri % m != 0)
        {
            ok=1;
        }
    }

    if(ok==0)
    {
        fout<<"1"<<endl;
        sort(v+1,v+dim+1,cmp);

        for( j=1; j<=dim; j++)
        {

            fout<<v[j].factori<<" "<<v[j].puteri/m<<endl;
        }
    }
    else
    {
        fout<<"0";
    }




}
