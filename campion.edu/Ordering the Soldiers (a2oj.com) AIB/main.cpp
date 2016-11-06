#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("text.txt");


int isAll0(int v[100], int n)
{

    for(int i=1; i<=n; i++)
    {
        if(v[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}

void afisare( int v[100] , int n){

 for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

int main()
{

    int n,v[100],verifica[100],b[100],j,mx=-999,i,poz;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        verifica[i]=0;
        fin>>v[i];
        b[i]=i;
    }

    while(isAll0(v,n)==0)
    {
        mx=0;
        for(j=1; j<=n; j++)
        {
            if(v[j]>mx)
            {
                mx=v[j];
                poz=j;
            }
        }

        if(verifica[poz-mx]==0 && mx!=0)
        {
            verifica[poz-mx]=1;
            swap(b[j],b[poz-mx]);
            v[poz]=0;
        }

        afisare(b,n);
    }



}
