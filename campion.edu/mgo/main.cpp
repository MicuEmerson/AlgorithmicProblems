#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("mgo.in");
ofstream fout("mgo.out");

int n,P,a[100],b[100],v[1001],nrA,nrB,itA,itB,cateA,cateB;

void stergereA(int poz)
{
    int st1=0,dr1,st2,dr2=0;
    int i;
    for(i=1; i<poz; i++)
    {
        if(v[i]==1)
        {
            st1=i;
            break;
        }
    }
    for(i=poz+1; i<=n; i++)
    {
        if(v[i]==1)
        {
            dr2=i;
            break;
        }
    }
    if(st1!=0){
        for(i=st1;i<=poz;i++){
            if(v[i]==2){
                v[i]=0;
            }
        }
    }
    if(dr2!=0){
        for(i=poz;i<=dr2;i++){
            if(v[i]==2){
                v[i]=0;
            }
        }
    }
}


void stergereB(int poz)
{
    int st1=0,dr1,st2,dr2=0;
    int i;
    for(i=1; i<poz; i++)
    {
        if(v[i]==2)
        {
            st1=i;
            break;
        }
    }
    for(i=poz+1; i<=n; i++)
    {
        if(v[i]==2)
        {
            dr2=i;
            break;
        }
    }
    if(st1!=0){
        for(i=st1;i<=poz;i++){
            if(v[i]==1){
                v[i]=0;
            }
        }
    }
    if(dr2!=0){
        for(i=poz;i<=dr2;i++){
            if(v[i]==1){
                v[i]=0;
            }
        }
    }

}


int main()
{
    int i;
    fin>>n>>P;
    for(i=1; i<=P; i++)
    {
        if(i%2==1)
        {
            fin>>a[++nrA];
        }
        else
        {
            fin>>b[++nrB];
        }
    }

    v[a[1]]=1;
    v[b[1]]=2;
    itA=itB=2;
    for(i=3; i<=P; i++)
    {

        if(i%2==1)
        {
            v[a[itA]]=1;
            stergereA(a[itA]);
            itA++;
        }
        else
        {
            v[b[itB]]=2;
            stergereB(b[itB]);
            itB++;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(v[i]==1)
        {
            cateA++;
        }
        if(v[i]==2)
        {
            cateB++;
        }
    }
    fout<<cateA<<" "<<cateB;



}
