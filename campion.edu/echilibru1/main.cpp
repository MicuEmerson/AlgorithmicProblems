/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin, *fout;

int n,m,l,rez;
int a[800001];
int b[800001];
int c[800001];
int x[800001];

void update(int val, int poz)
{

    while(poz<=m)
    {
        x[poz]+=val;
        poz+=(poz&(-poz));
    }
}

int interogare(int poz)
{

    int rez=0;
    while(poz>0)
    {
        rez+=x[poz];
        poz-=(poz&(-poz));
    }
    return rez;
}


int cautareBinara(int st, int dr, int elem)
{
    int m;
    if(st==dr)
    {
        return st;
    }
    m=(st+dr)/2;
    if(elem<=c[m])
    {
       return cautareBinara(st,m,elem);
    }
    else
    {
        return cautareBinara(m+1,dr,elem);
    }
}


int main()
{
    fin=fopen("echilibru1.in","r");
    fout=fopen("echilibru1.out","w");
    int i;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&l);

    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a[i]);
        b[i]=a[i];
    }

    // normalizare

    sort(b+1,b+n+1);
    c[++m]=b[1];
    for(i=2; i<=n; i++)
    {
        if(b[i]!=b[i-1])
        {
            c[++m]=b[i];
        }
    }
    for(i=1; i<=n; i++)
    {
        a[i]=cautareBinara(1,m,a[i]);
    }

    // prelucrare prima segventa;
    for(i=1;i<=l*2+1;i++){
        update(1,a[i]);
    }
    update(-1,a[l+1]);
    if(interogare(a[l+1]-1)==l){
        rez++;
    }
    // parcurgere toate segventele;

    for(i=2;i<=n-l*2;i++){

        update(-1,a[i-1]);
        update(1,a[i+2*l]);
        update(-1,a[l+i]);
        update(1,a[i+l-1]);
        if(interogare(a[l+i]-1)==l){
            rez++;
        }
    }
    fprintf(fout,"%d ",rez);

}
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin, *fout;

int n,m,l,rez;
int a[800001];
int b[800001];
int f[1000000];
int x[800001];

void update(int val, int poz)
{

    while(poz<=m)
    {
        x[poz]+=val;
        poz+=(poz&(-poz));
    }
}

int interogare(int poz)
{

    int rez=0;
    while(poz>0)
    {
        rez+=x[poz];
        poz-=(poz&(-poz));
    }
    return rez;
}

int cautareBinara(int st, int dr, int elem)
{
    int m;
    if(st==dr)
    {
        return st;
    }
    m=(st+dr)/2;
    if(elem<=b[m])
    {
       return cautareBinara(st,m,elem);
    }
    else
    {
        return cautareBinara(m+1,dr,elem);
    }
}


int main()
{
    fin=fopen("text.txt","r");
    fout=fopen("text1.in","w");
    int i;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&l);

    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a[i]);
        f[a[i]+500000]++;

    }

    // normalizare
    for(i=1;i<=1000000;i++){
        if(f[i]>0){
            b[++m]=i-500000;
        }
    }
    for(i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl<<endl;
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        a[i]=cautareBinara(1,m,a[i]);
    }
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;



    // prelucrare prima segventa;
    for(i=1;i<=l*2+1;i++){
        update(1,a[i]);
    }
    update(-1,a[l+1]);
    if(interogare(a[l+1]-1)==l){
        rez++;
    }
    // parcurgere toate segventele;

    for(i=2;i<=n-l*2;i++){

        update(-1,a[i-1]);
        update(1,a[i+2*l]);
        update(-1,a[l+i]);
        update(1,a[i+l-1]);
        if(interogare(a[l+i]-1)==l){
            rez++;
        }
    }
    fprintf(fout,"%d ",rez);

}




























