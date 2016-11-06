#include <iostream>
#include <algorithm>

using namespace std;

int functie(int nr,int poz)
{

    int i=0,nrNou=0;
    while(nr>0)
    {
        i++;
        if(i!=poz) nrNou=nrNou*10+nr%10;
        nr/=10;
    }
    while(nrNou>0)
    {
        nr=nr*10+nrNou%10;
        nrNou/=10;
    }
    return nr;


}

int main()
{

    int nr,nr1,cate=0,maxy=-1;
    cin>>nr;
    nr1=nr;
    while(nr1>0)
    {
        cate++;
        nr1/=10;
    }

    for(int i=1; i<=cate; i++)
    {
        int f=nr%functie(nr,i);
        if(f!=0) maxy=max(maxy,f);
    }
    cout<<maxy;


}
