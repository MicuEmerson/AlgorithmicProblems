#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("sir4.in");
ofstream fout("sir4.out");

int k;
int v[10000],dimV=0,nr,ok,nr1,nr2;

int cmp(int a, int b)
{

    if(a<=9 && b<=9)
    {

        if(a < b)
        {
            return 1;
        }

    }

    else if(a<=9 && b>9)
    {
        if(a < b/10)
        {
            return 1;
        }
    }

    else if(b<=9 && a>9)
    {
        if(a/10 < b)
        {
            return 1;
        }
    }
    else
    {
        if(a/10 < b/10)
        {
            return 1;
        }
    }
    return 0;



}


int isInVector(int elem)
{

    for(int i=1; i<=dimV; i++)
    {
        if(elem==v[i])
        {
            return 1;
        }
    }
    return 0;
}




int main()
{
    int i;
    fin>>k;
    nr=k*k;
    nr/=10;
    nr1=nr%10;
    nr2=(nr/10)%10;
    nr=nr2*10+nr1;
    v[++dimV]=nr;


    while(ok==0)
    {
        nr=v[dimV]*v[dimV];
        nr/=10;
        nr1=nr%10;
        nr2=(nr/10)%10;
        nr=nr2*10+nr1;
        if(isInVector(nr)==0)
        {
            v[++dimV]=nr;
        }
        else
        {
            ok=1;
        }
    }

    for(i=1; i<=dimV; i++)
    {
        fout<<v[i]<<" ";
    }
    fout<<endl;
    sort(v+1,v+dimV+1,cmp);
    for(i=1; i<=dimV; i++)
    {
        fout<<v[i]<<" ";
    }



}
