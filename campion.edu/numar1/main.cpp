#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("numar1.in");
ofstream fout("numar1.out");

int v[100],n,y[100],dimY,s,nr,gasit;

void transformare(int &n)
{
    int cn,s;
    while(n>9)
    {

        cn=n;
        s=0;
        while(cn>0)
        {
            s+=cn%10;
            cn/=10;
        }
        n=s;
    }

}

int isInVector(int n)
{

    for(int i=1; i<=dimY; i++)
    {
        if(n==y[i])
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
    i=2;
    s=v[1];
    while(i<=n)
    {

        if(v[i-1]<=v[i])
        {
            s+=v[i];
        }
        else
        {
            y[++dimY]=s;
            s=0;
            s=v[i];
        }
        i++;
    }
    y[++dimY]=s;

    for(i=1; i<=dimY; i++)
    {
        transformare(y[i]);

    }

    for(i=9; i>=0; i--)
    {
       if(isInVector(i)==1){
        nr=nr*10+i;
        gasit=1;
       }
    }
    if(gasit==1){
        fout<<nr;
    }
    else{
        fout<<"-1";
    }


}
