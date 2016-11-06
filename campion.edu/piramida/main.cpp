#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;
ifstream fin("piramida.in");
ofstream fout("piramida.out");

char c[100];
int v[100],dim;

int ceCifra(char x)
{
    if(x=='a' || x=='j' || x=='s')
    {
        return 1;
    }
    else if(x=='b' || x=='k' || x=='t')
    {
        return 2;
    }
    else if(x=='c' || x=='l' || x=='u')
    {
        return 3;
    }
    else if(x=='d' || x=='m' || x=='v')
    {
        return 4;
    }
    else if(x=='e' || x=='n' || x=='w')
    {
        return 5;
    }
    else if(x=='f' || x=='o' || x=='x')
    {
        return 6;
    }
    else if(x=='g' || x=='p' || x=='y')
    {
        return 7;
    }
    else if(x=='h' || x=='q' || x=='z')
    {
        return 8;
    }
    else
    {
        return 9;
    }
}

int cifraCorecta(int n)
{
    int s=0;
    while(n>9)
    {
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        n=s;
    }
    return n;

}


int main()
{   int i,k,j;
    fin.get(c,100);
    dim=strlen(c);
    for(i=0; i<strlen(c); i++)
    {
        c[i]=tolower(c[i]);
    }
    fout<<c<<endl;
    for(i=0; i<strlen(c); i++)
    {
        v[i+1]=ceCifra(c[i]);
    }
    int dimInitial=dim;
    while(dim!=1)
    {
        for(i=1; i<dim; i++)
        {
            k=v[i]+v[i+1];
            fout<<v[i]<<" ";
            v[i]=cifraCorecta(k);
        }
        fout<<v[dim]<<endl;
        dim--;
        for(j=1;j<=dimInitial-dim;j++){
            fout<<" ";
        }
    }
    fout<<v[dim];








}



















