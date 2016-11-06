#include <iostream>
#include <algorithm>
using namespace std;

int isPal(int n)
{

    int newNr=0;
    int cn=n;
    while(cn>0)
    {

        newNr=newNr*10+cn%10;
        cn/=10;
    }

    if(newNr==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int nrNumerePalindroame(int n)
{
    int numar=1;
    int contor=0;
    while(numar<=n)
    {
        if(isPal(numar)==1)
        {
            contor++;
        }
        numar++;
    }
    return contor;
}


int isPrim(int n)
{

    int div=0;
    int i;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            div++;
        }
    }
    if(div==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int nrNumerePrime(int n)
{
    int numar=1;
    int contor=0;
    while(numar<=n)
    {
        if(isPrim(numar)==1)
        {
            contor++;
        }
        numar++;
    }
    return contor;
}


void findN(int p,int q){

 int n=0;
 while()

}







int main()
{

    int p,q;
    cin>>p>>q;


}
