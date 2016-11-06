#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
int n,v[100002],cate;
int cifre1[10],cifre2[10];


int main()
{
    int i,j;
    fin>>n;
    fin>>v[1];
    for(i=2; i<=n; i++)
    {
        fin>>v[i];
        if(v[i-1]+1==v[i])
        {
            cate++;
        }
    }
    if(cate==n-1)
    {
        cout<<"0 0"<<endl;
        cout<<v[n];
    }
    else if(cate==n-2)
    {
        int nrMax=v[n-1]+1;
        v[n-1]=v[n-1]+1;
        i=0;
        while(v[n-1]>0)
        {
            cifre1[++i]=v[n-1]%10;
            v[n-1]/=10;
        }
        i=0;
        while(v[n]>0)
        {
            cifre2[++i]=v[n]%10;
            v[n]/=10;
        }
        for(i=1;i<=10;i++){
            if(cifre1[i]!=cifre2[i]){
                cout<<cifre1[i]<<" ";
            }
        }
        cout<<endl<<nrMax;
    }
    else{
        int nr1,nr2;
        for(i=1;i<n;i++){
            j=i+1;
            if(v[i]+1==v[j]){
                break;
            }
        }
        nr1=v[i]-1;
        nr2=v[i-1];
        i=0;
        while(nr1>0){
            cifre1[++i]=nr1%10;
            nr1/=10;
        }
        i=0;
        while(nr2>0){
            cifre2[++i]=nr2%10;
            nr2/=10;
        }

        for(i=1;i<=10;i++){
            if(cifre1[i]!=cifre2[i]){
                if(cifre1[i]>cifre2[i]){
                    cout<<cifre2[i]<<" "<<cifre1[i]<<endl;
                }
                else{
                    cout<<cifre1[i]<<" "<<cifre2[i]<<endl;
                }
            }
        }







    }















}
