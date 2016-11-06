#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("munte3.in");
ofstream fout("munte3.out");

int v[105],n,del[105],nrDel;

void eliminarePoz(int v[105], int &n, int poz)
{
    int i;
    for(i=poz; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;
}

void afisare(){
 for(int i=1;i<=n;i++){
    cout<<v[i]<<" ";
 }
 cout<<endl;

}

int main()
{
    int i,j,cate=0,intratOdata=0,cate2=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    afisare();
    for(i=2; i<n; i++)
    {
        if(v[i-1]<v[i] && v[i]>v[i+1])
        {
            del[++nrDel]=i;
            cate++;
        }
    }
    for(i=1; i<=nrDel; i++)
    {
        eliminarePoz(v,n,del[i]);
        for(j=1;j<=nrDel;j++){
            del[j]--;
        }
    }
    afisare();
    fout<<cate<<endl;

    while(cate2!=0 || intratOdata==0)
    {
        intratOdata=1;
        cate2=0;
        nrDel=0;
        for(i=2; i<n; i++)
        {
            if(v[i-1]<v[i] && v[i]>v[i+1])
            {
                del[++nrDel]=i;
                cate2++;
            }
        }
        for(i=1; i<=nrDel; i++)
        {
            eliminarePoz(v,n,del[i]);
            for(j=1;j<=nrDel;j++){
            del[j]--;
        }
        }
        cate+=cate2;
        afisare();
    }
   fout<<cate<<endl<<n;


}
















