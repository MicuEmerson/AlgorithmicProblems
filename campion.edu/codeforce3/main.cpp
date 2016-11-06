#include <iostream>
#include <algorithm>
using namespace std;

int isPermutare(int v[100000], int n)
{

    for(int i=1; i<=n; i++)
    {
        if(v[i]!=i)
        {
            return 1;
        }
    }
    return 0;

}

int gotAllElements(int f[100000], int n)
{

    for(int i=1; i<=n; i++)
    {
        if(f[i]!=1)
        {
            return 0;
        }
    }
    return 1;

}


void afisare(int v[100000], int n)
{

    for(int i=1; i<=n; i++)
    {
        cout<<v[i]<<" ";
    }


}


int main()
{
    int n,i,dimAll=0,k=0;
    int v[100000], all[100000], f[100000];
    cin>>n;
    if(n==1)
    {
        cout<<"1";
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            cin>>v[i];
            f[v[i]]=0;
            f[v[i]]++;
        }

        for(i=1; i<=n; i++)
        {
            if(f[i]==0)
            {
                dimAll++;
                all[dimAll]=i;
            }
        }


        if(gotAllElements(f,n)==1)
        {

            if(isPermutare(v,n)==1)
            {
                afisare(v,n);
            }
            else
            {
                swap(v[1],v[2]);
                afisare(v,n);
            }
        }
        else
        {

            for(i=1; i<=n; i++)
            {
                if(v[i]==i)
                {
                    k++;
                    v[i]=all[k];
                }
            }
            afisare(v,n);

        }

    }

}
