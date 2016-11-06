#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("lightbot.out");

int n,tip;
int v[200001],dim;
int v1[200001],dim1;
int f[200001];


void tip1()
{
    int cate=0;
    for(int i=1; i<dim; i++)
    {
        if(v[i]+1!=v[i+1])
        {
            cate++;
            i++;
        }
    }
    fout<<cate;

}

void tip2()
{
    int maxy=-1;
    for(int i=0; i<=200000; i++)
    {
        maxy=max(maxy,f[i]);
    }
    for(int i=200000; i>=0; i--)
    {
        if(f[i]==maxy)
        {
            fout<<i;
            break;
        }
    }
}

void tip3()
{

    for(int i=1; i<dim; i++)
    {
        if(v[i]+1!=v[i+1])
        {
            v1[++dim1]=i;
            i++;
        }
    }

    for(int i=1; i<=dim1; i++)
    {
        for(int j= v[v1[i]]+1 ; j <= v[v1[i]+1]-1; j++)
        {
            cout<<j<<" ";
        }

    }

}



int main()
{
    fin>>tip>>n;

    while(!fin.eof())
    {
        fin>>v[++dim];
        f[v[dim]]++;
    }
    if(tip==1)
    {
        tip1();
    }
    else if(tip==2)
    {
        tip2();
    }
    else
    {
        tip3();
    }

}
