#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("pachete.in");
ofstream fout("pachete.out");
int n,i,j;
int v[105];

int pozGol()
{
    for(i=1; i<=n+1; i++)
    {
        if(v[i]==0)
        {
            return i;
        }
    }

}
int pozElem(int elem)
{
    for(i=1; i<=n+1; i++)
    {
        if(v[i]==elem)
        {
            return i;
        }
    }
}

int main()
{

    fin>>n;
    pair < int , int > pereche[1000];
    int nr=0;
    int i,poz;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }

    for(i=1; i<=n; i++)
    {

        if(v[i]!=i)
        {
            if(v[i]!=0)
            {
                poz=pozGol();
                nr++;
                pereche[nr].first=i;
                pereche[nr].second=poz;
                swap(v[i],v[poz]);
            }
            poz=pozElem(i);
            nr++;
            pereche[nr].first=poz;
            pereche[nr].second=i;
            swap(v[i],v[pozElem(i)]);
        }
    }
    fout<<nr<<endl;
    for(i=1; i<=nr; i++)
    {
        fout<<pereche[i].first<<" "<<pereche[i].second<<endl;
    }





}
