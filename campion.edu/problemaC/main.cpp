#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdlib>

using namespace std;

ifstream fin("text.txt");

void copiere(char c[300005], char copie[300005], int n)
{

    for(int i=1; i<=n; i++)
    {
        copie[i]=c[i];
    }
}

void copiere2(char c[300005], char copie[300005], int n)
{

    for(int i=1; i<=n; i++)
    {
        c[i]=copie[i];
    }
}


int main()
{
    int n,m,i,j,poz,contor,x;
    char c[300005];
    char copie[300005];
    char l;
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>c[i];

    }

    for(i=1; i<=m; i++)
    {
        copiere(c,copie,n);
        cin>>x;
        cin>>l;
        copie[x]=l;
        copiere2(c,copie,n);

        contor=0;
        for(j=1; j<n; j++)
        {
            if(copie[j]=='.' && copie[j+1]=='.')
            {
                strcpy(copie+j,copie+j+1);
                contor++;
                j--;
            }
        }
        cout<<contor<<endl;

    }


}










