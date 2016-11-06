#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("prime.in");
ofstream fout("prime.out");

int E[30000];
char c;

void eratostene()
{
    int i,j;
    for(i=2; i<=30000; i++)
    {
        E[i]=1;
    }
    for(i=2; i<=30000; i++)
    {
        if(E[i]==1)
        {

            for(j=i+i; j<=30000; j=j+i)
            {
                E[j]=0;
            }
        }
    }
}


int main()
{
    eratostene();
    int i=1,s=0;
    while(fin>>c)
    {
        while(E[i]==0)
        {
            i++;
        }
        if(c=='1'){
            s+=i;
        }
        i++;
    }
    fout<<s;
}















