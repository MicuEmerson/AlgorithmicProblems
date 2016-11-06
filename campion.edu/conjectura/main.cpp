#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int n;

int isPal(int v[100000], int n)
{
    int jum=n/2;
    for(int i=1; i<=jum; i++)
    {
        if(v[i]!=v[n])
        {
            return 0;
        }
        n--;
    }
    return 1;
}

void adunare(int a[100000], int &n)
{

    int t=0,s,dim=0;
    int c[100000];
    int n2=n;
    for(int i=1; i<=n ; i++)
    {
        s=a[i]+a[n2];
        n2--;
        c[++dim]=s%10+t;
        t=s/10;
    }
    n=dim;
    int j=0;
    for(int i=dim; i>=1; --i)
    {
        a[++j]=c[i];
    }


}



int functie(int x)
{


    int a[100000],dimA,contor=0;

    while(x>0)
    {
        a[++dimA]=x%10;
        x/=10;
    }

    while(isPal(a,dimA)==0){

        adunare(a,dimA);
        contor++;
    }
    return contor;




}


int main()
{

    /*cin>>n;

    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cout<<functie(x)<<"\n";

    }
    */
    cout<<functie(174);

























}
