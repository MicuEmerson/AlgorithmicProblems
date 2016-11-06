#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("text.txt");


typedef struct
{

    int st;
    int dr;
    int poz;
    int ok;


} vct;

vct v[100];
int i,j;

void sortare(vct v[100], int n)
{

    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(v[i].dr>v[j].dr)
            {
                swap(v[i].dr,v[j].dr);
                swap(v[i].st,v[j].st);
                swap(v[i].poz,v[j].poz);
            }
        }
    }
}

int main()
{
    int n,cati=1;
    int s[1000],f[1000];
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i].st;
        v[i].poz=i;
        v[i].ok=1;
    }
    for(i=1; i<=n; i++)
    {
        fin>>v[i].dr;
    }
    sortare(v,n);
    i=1;
    j=2;
    while(i<n)
    {

        if(v[i].ok==1)
        {
            if(v[i].dr<=v[j].st)
            {
                cati++;
                i++;
                j++;
            }
            else
            {   v[j].ok=0;
                j++;
            }

        }
        else{
            i++;
            j++;
        }
    }
    if(v[n-1].st<=v[n].dr && v[n-1].ok==1){
        cati++;
    }
    cout<<cati<<endl;
    for(i=1;i<=n;i++){
       if(v[i].ok==1){
        cout<<v[i].poz<<" ";
       }
    }


}
