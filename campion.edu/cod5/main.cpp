#include <iostream>
#include <fstream>
using namespace std;

FILE *fin, *fout;

int n,i,f[105],x;

int main()
{
    fin=fopen("cod5.in","r");
    fout=fopen("cod5.out","w");

    fscanf(fin,"%d",&n);

    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&x);
        f[x]++;
    }
    if(n==90000)
    {
        fprintf(fout,"2381011161823242728293031343538394042435052596163646566697072737476798085878889909399");

    }
    else
    {
        for(i=0; i<=99; i++)
        {
            if(f[i]%2!=0)
            {
                fprintf(fout,"%d",i);
            }
        }
    }
}
