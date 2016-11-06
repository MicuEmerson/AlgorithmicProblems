#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("gradina.in");
ofstream fout("gradina.out");


int E[300005],primi[26005];
int a,b;

void eratostene()
{
    for(int i=2; i<=300001; i++) E[i]++;

    for(int i=2; i<=300001; i++)
        if(E[i]==1)
        {

            primi[++primi[0]]=i;
            for(int j=i+i; j<=300001; j+=i)
                E[j]=0;
        }
}

bool isCubeOrSquare(int n)
{

    if(cbrt(n) == (int)cbrt(n)) return true;
    if(sqrt(n) == (int)sqrt(n)) return true;
    return false;
}








void sDivizori(int n)
{
    int s=1,i=1,p;
    while(n!=1)
    {
        if(n%primi[i]==0)
        {
            p=0;
            while(n%primi[i]==0)
            {
                p++;
                n/=primi[i];
            }
            s=s* ( (pow(primi[i],p+1) - 1) / (primi[i]-1));

        }
        i++;
    }
    cout<<s;

}






int main()
{
    eratostene();
    sDivizori(10);





}
