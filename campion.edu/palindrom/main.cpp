#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
//ifstream fin("text.txt");
//ofstream fout("text1.txt");

typedef struct
{

    int nr;
    int cate;


} vvv;


int n,catePare,cateImpare,panaLa,dim,dimF;
int f[10],maxy=-999,gasit,cateNrImpareMax;
vvv v[10005];
int  FINAL[10005];

int cmp(vvv a, vvv b)
{

    if(a.nr>b.nr)
    {
        return 1;
    }
    return 0;


}

int main()
{
    int i,x;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;

        f[x]++;
    }

    for(i=0; i<=9; i++)
    {
        if(f[i] % 2==0 && f[i]!=0)
        {
            catePare++;
        }
        if(f[i] % 2 !=0)
        {
            cateImpare++;
        }
    }


    //cazul I
    if(catePare==0)
    {
        for(i=1; i<=9; i++)
        {
            maxy=max(maxy,f[i]);
        }

        for(i=9; i>=1 && gasit==0 ; i--)
        {
            if(f[i]==maxy)
            {
                while(f[i]>0)
                {
                    fout<<i;
                    f[i]--;
                }
                gasit=1;
            }
        }
    }

    else
    {
        //cazul II
        for(i=9; i>=0; i--)
        {

            if(f[i]%2==0 && f[i]>0)
            {

                dim++;
                v[dim].nr=i;
                v[dim].cate=f[i];

            }
        }


        for(i=9; i>=0; i--)
        {
            if(f[i]%2!=0)
            {
                if(f[i]>maxy)
                {
                    maxy=f[i];
                    cateNrImpareMax=i;
                }

            }
        }
        if(maxy!=-999)
        {
            dim++;
            v[dim].cate=maxy;
            v[dim].nr=cateNrImpareMax;
        }



        sort(v+1,v+dim+1,cmp);

        for(i=1; i<=dim; i++)
        {

            v[i].cate/=2;
            while(v[i].cate>0)
            {
                FINAL[++dimF]=v[i].nr;
                v[i].cate--;
            }

        }
        FINAL[++dimF]=cateNrImpareMax;

        for(i=dimF-1; i>=1; i--)
        {

            FINAL[++dimF]=FINAL[i];

        }

        //cazul cu 0
        if(FINAL[i]==0)
        {
            int cate0=0;
            while(FINAL[i]==0)
            {
                cate0++;
                i++;
            }
            cate0--;
            for(i=cate0+1; i<=dimF-cate0; i++)
            {
                fout<<FINAL[i];
            }

        }
        else{

            for(i=1;i<=dimF;i++){
                fout<<FINAL[i];
            }

        }


    }








}
