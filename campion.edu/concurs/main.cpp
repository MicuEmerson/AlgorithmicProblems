#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("concurs.in");
ofstream fout("concurs.out");

int n,nrj;
set < int > J[51];

int main()
{  int i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        int x,y;
        fin>>x>>y;
        J[x].insert(y);
    }
    for(i=1; i<=50; i++)
    {
        if(J[i].size()!=0)
        {
            nrj++;
        }
    }
    fout<<nrj<<endl;
    for(i=1; i<=50; i++)
    {
        if(J[i].size()!=0)
        {
            fout<<J[i].size()<<" ";
        }
    }
    fout<<endl;

    int uj=0,maxi,jud;
    while(n>0)
    {
        maxi=0;
        for(i=1; i<=50; i++)
        {
            if(maxi<=J[i].size() && uj!=i)
            {
                maxi=J[i].size();
                jud=i;
            }
        }
        fout<<jud<<" "<<*(J[jud].begin())<<endl;
        J[jud].erase(*(J[jud].begin()));
        uj=jud;
        n--;

    }





}
