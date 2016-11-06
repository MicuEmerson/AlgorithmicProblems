#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("factori.in");
ofstream fout("factori.out");


int E[60005];

void eratostene()
{
    int i,j;
    for(i=2; i<=60005; i++)
    {
        E[i]=1;
    }
    for(i=2; i<=60005; i++)
    {
        if(E[i]==1)
        {
            for(j=i+i; j<=60005; j=j+i)
            {
                E[j]=0;
            }
        }
    }
}


int main()
{
    int x,i,s,ci;
    eratostene();
    while(fin>>x && x!=0)
    {

        i=2;
        while(i<=x){
            s=0;
            if(E[i]==1){

                ci=i;
                while(ci<=x){
                    s+=x/ci;
                    ci*=i;
                }
                fout<<s<<" ";
            }
            i++;
        }
        fout<<endl;
    }


}

































