#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("test2.in");
ofstream fout("test2.out");

typedef struct
{

    int nr[10];
    int ok[10];


} vvv;

int n,x,poz,numar;
vvv v[1005];

int main()
{

    int i,j,k;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        j=0;
        while(x>0)
        {
            v[i].nr[0]++;
            v[i].nr[++j]=x%10;
            x/=10;
        }
        k=v[i].nr[0];
        for(j=1; j<=v[i].nr[0]/2; j++)
        {
            swap(v[i].nr[j],v[i].nr[k]);
            k--;
        }

    }


    for(i=1; i<=n; i++)
    {
        if(i<=v[i].nr[0])
        {
            poz=v[i].nr[0]-i+1;
        }
        else
        {
            poz=i%v[i].nr[0];
            if(poz==0){
                poz=1;
            }
            else{
            poz=v[i].nr[0]-poz+1;
            }
        }
        v[i].ok[poz]=1;

    }


    for(i=1; i<=n; i++)
    {
        numar=0;

        for(j=1; j<=v[i].nr[0]; j++)
        {
            if(v[i].ok[j]==0)
            {
                numar=numar*10+v[i].nr[j];
            }


        }
        fout<<numar<<" ";

    }














}


























