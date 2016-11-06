#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("muguri.out");

int n,dim;
int v[110],s[110];

bool isPal()
{
    int jum=v[0]/2;
    int panaLa=v[0];
    for(int i=1; i<=jum; i++)
    {
        if(v[i]!=v[panaLa]) return false;
        panaLa--;
    }
    return true;
}

void aduna()
{

    int i,t=0;
    int aux[300];

    for (i=1; i<=v[0] || i<=s[0] || t; i++,t=t/10)
    {
        aux[i]=(t+=(v[i]+s[i]))%10;
    }
    aux[0]=i-1;
    for(int i=0; i<=aux[0]; i++)
    {
        s[i]=aux[i];
    }

}




int main()
{
    fin>>n;
    for(int k=1; k<=n; k++)
    {
        fin>>dim;
        v[0]=dim;

        for(int i=dim; i>=1; i--)
        {
            char c;
            fin>>c;
            v[i]=(int)c-48;
        }

        if(isPal()){
           aduna();
        }
    }
    for(int i=s[0];i>=1;i--){
        cout<<s[i];
    }








}
