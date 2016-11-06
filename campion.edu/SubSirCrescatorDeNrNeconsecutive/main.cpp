#include <iostream>

using namespace std;

void afisare(int v[100], int n)
{

    for(int i=1; i<=n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

}


int main()
{
    int v[100];
    int aux[100];
    int n,nrMax,gasit,i,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    aux[n]=1;
    for(i=n-1; i>=1; i--)
    {
        nrMax=-9999999;
        gasit=0;
        for(j=i+1; j<=n; j++)
        {
            if(v[i]<v[j])
            {
                if(aux[j]>nrMax)
                {
                    nrMax=aux[j];
                    gasit=1;
                }
            }
        }
        if(gasit==0)
        {
            aux[i]=1;
        }
        else
        {
            aux[i]=nrMax+1;
        }
    }


    afisare(v,n);
    afisare(aux,n);
}

