#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("volei1.in");
ofstream fout("volei1.out");
typedef struct
{

    int fete;
    int nr;


} ff;
typedef struct
{

    int baieti;
    int ok;


} bb;

bb b[2005];
ff f[2005];
int n,m,i,x,y,nr=0,k;
int fb[4010],bbb[2005];

/*
int cautareBinara(int st,int dr, int elem)
{
    int m;
    while(st!=dr)
    {
        m=(st+dr)/2;
        if(b[m].baieti==elem)
        {
            return b[m].baieti-(2*b[m].baieti);
        }
        else
        {
            if(elem>=b[m].baieti) st=m+1;
            else  dr=m;
        }
    }
    if(elem<b[st].baieti && b[st].ok==1)
    {
        b[st].ok=0;
        return b[st].baieti-(2*b[st].baieti);
    }
    else return 0;
}
*/

int cautare(int elem){
 for(int i=1;i<=m;i++){
    if(elem<b[i].baieti && b[i].ok==1){
        b[i].ok=0;
        return b[i].baieti-(2*b[i].baieti);
    }
 }
 return 0;
}


int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>f[i].fete;
    }
    fin>>m;
    for(i=1; i<=m; i++)
    {
        fin>>bbb[i];
        b[i].ok=1;
    }
    sort(bbb+1,bbb+m+1);
    for(i=1;i<=m;i++){
        b[i].baieti=bbb[i];
    }

    for(i=1; i<n; i++)
    {
        f[i].nr=max(f[i].fete,f[i+1].fete);
    }
    f[n].nr=max(f[n].fete,f[1].fete);
    for(i=1;i<=n;i++){
        fb[++nr]=f[i].fete;
        k=cautare(f[i].nr);
        if(k!=0){
            fb[++nr]=k;
        }
    }
    fout<<nr-n<<endl;
    for(i=1;i<=nr;i++){
        fout<<fb[i]<<" ";
    }



}






