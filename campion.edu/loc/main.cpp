#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("loc.in");
ofstream fout("loc.out");

int n,v[1001],nrMutari;

int isOk()
{

    for(int i=1; i<=n; i++)
    {
        if(v[i]!=i)
        {
            return 0;
        }
    }
    return 1;


}


int main()
{
    int i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }

    i=0;
    while(isOk()==0)
    {
        i++;
        if(v[i]!=i)
        {
            while(v[i]!=i)
            {
                swap(v[i],v[v[i]]);
            }
            nrMutari++;
        }


    }
    fout<<nrMutari;




}
