/*

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("simetric.in");
ofstream fout("simetric.out");
int n,v[210];
int dim;


int isPal(int dim)
{

    int cn=dim;
    for(int i=1; i<=dim/2; i++)
    {
        if(v[i]!=v[cn])
        {
            return 0;
        }
        cn--;
    }
    return 1;

}


int main()
{
    int k=0;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    dim=n;
    if(isPal(n)==1)
    {
        fout<<"0";
    }
    else
    {
        while(isPal(dim)==0)
        {

            k++;
            int j=k;
            for(int i=n+1; i<=n+k; i++)
            {
                v[i]=v[j];
                j--;
            }
            dim=n+k;
        }



        fout<<k<<endl;
        if(k!=0)
        {
            for(int i=n+1; i<=n+k; i++)
            {
                fout<<v[i]<<" ";
            }
        }

    }


}

*/










































