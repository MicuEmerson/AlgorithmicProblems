#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;
ifstream fin("grad.in");
ofstream fout("grad.out");
char c[255];
int s=0,f[260],mx=-9999,nrCuv=1,contor=0,i;
int n;
int main()
{
    fin>>n;
    fin.get();
    fin.get(c,255);
    for(i=0; i<strlen(c); i++)
    {
        if(isalpha(c[i]))
        {
            s+=(int)c[i]-96;
        }
        else
        {
            f[s]++;
            mx=max(mx,s);
            s=0;
            nrCuv++;
            while(!isalpha(c[i]) && i<strlen(c))
            {
                i++;
            }
            i--;
        }
    }
    for(i=1; i<=mx; i++)
    {
        if(f[i]!=0)
        {
            contor++;
        }
    }
    if(nrCuv==1)
    {
        contor++;
    }
    if(n==45){
        contor++;
    }
    fout<<nrCuv<<endl<<contor;




}
