#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;
ifstream fin("suma.in");
ofstream fout("suma.out");
int v[1005];
int v2[1005];
int main()
{
    int n,copieN,ultPoz,i,primaPoz;

    fin>>n;
    if(n==1)
    {
        fout<<1<<endl<<1;
    }
    else if(n==2)
    {
        fout<<11<<endl<<20;
    }
    else
    {

        //cel mai mic
        v[1]=1;
        copieN=n-1;
        ultPoz=n;
        if(copieN>9)
        {

            while(copieN>9)
            {
                 v[ultPoz]=9;
                 ultPoz--;
                 copieN-=9;
            }
            v[ultPoz]=copieN;

        }
        else{
            v[ultPoz]=copieN;
        }
        for(i=1;i<=n;i++){
            fout<<v[i];
        }
        fout<<endl;

        //cel mai mare;

        copieN=n;
        primaPoz=0;
        if(copieN>9){

            while(copieN>9){
                v2[++primaPoz]=9;
                copieN-=9;
            }
            v2[++primaPoz]=copieN;

        }
        else{
            v2[++primaPoz]=copieN;
        }
        for(i=1;i<=n;i++){
            fout<<v2[i];
        }





    }


}
