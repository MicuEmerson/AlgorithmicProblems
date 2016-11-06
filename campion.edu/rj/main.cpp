/*
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
using namespace std;
ifstream fin("rj.in");
ofstream fout("rj.out");
int n,m,a[105][105],b[105][105];
int dl[8]= {0,-1,0,1,1,1,-1,-1};
int dc[8]= {1,0,-1,0,1,-1,-1,1};

bool isOk(int i, int j)
{
    if(a[i][j]==-1) return false;
    if(i>=1 && j>=1 && i<=n && j<=m) return true;
    return false;
}
bool isOk1(int i, int j)
{
    if(b[i][j]==-1) return false;
    if(i>=1 && j>=1 && i<=n && j<=m) return true;
    return false;
}


void lee(int li,int ci)
{
    queue < pair < int , int > > coada;
    a[li][ci]=1;
    coada.push(make_pair(li,ci));

    while(!coada.empty())
    {
        int i=coada.front().first;
        int j=coada.front().second;
        coada.pop();

        for(int d=0; d<=7; d++)
        {
            int i_next=i+dl[d];
            int j_next=j+dc[d];

            if(isOk(i_next,j_next) && a[i_next][j_next] == 0 )
            {
                a[i_next][j_next]=a[i][j]+1;
                coada.push(make_pair(i_next,j_next));
            }
        }
    }
}

void lee2(int li,int ci)
{
    queue < pair < int , int > > coada;
    b[li][ci]=1;
    coada.push(make_pair(li,ci));

    while(!coada.empty())
    {
        int i=coada.front().first;
        int j=coada.front().second;
        coada.pop();

        for(int d=0; d<=7; d++)
        {
            int i_next=i+dl[d];
            int j_next=j+dc[d];

            if(isOk1(i_next,j_next) && b[i_next][j_next] == 0 )
            {
                b[i_next][j_next]=b[i][j]+1;
                coada.push(make_pair(i_next,j_next));
            }
        }
    }
}



int main()
{
    int x1,x2,x3,y1,y2,y3,miny=99999999;
    fin>>n>>m;
    fin.get();
    for(int i=1; i<=n; i++)
    {

        char c[255];
        fin.get(c,255);
        fin.get();
        for(int j=0; j<strlen(c); j++)
        {
            if(c[j]=='X')
            {
                b[i][j+1]=-1;
                a[i][j+1]=-1;
            }
            if(c[j]=='R')
            {
                x1=i;
                y1=j+1;
            }
            if(c[j]=='J')
            {
                x2=i;
                y2=j+1;
            }
        }
    }

    lee(x1,y1);
    lee2(x2,y2);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]==b[i][j] && a[i][j]!=-1)
                if(miny>a[i][j])
                {
                    miny=a[i][j];
                    x3=i;
                    y3=j;
                }

    fout<<miny<<" "<<x3<<" "<<y3<<"\n";
}
*/
#include <fstream.h>
#define InFile "rj.in"
#define OutFile "rj.out"
#define NMax 102
#define NV 8

int n, m, xr, yr, xj, yj;
int dl[NV]={0, 1, 0, -1, -1, 1, -1, 1};
int dc[NV]={1, 0, -1, 0, -1, 1,  1,-1};
char l[NMax][NMax];
int r[NMax][NMax];

ifstream f(InFile);

void citire(void);
void afisare(int [NMax][NMax]);
void parcurge (int, int, int[NMax][NMax]);

int main()
{int j[NMax][NMax];
 citire();
 parcurge(xr, yr, r);
 parcurge(xj, yj, j);
 afisare(j);
 return 0;
}

void citire(void)
{
int i, k;
char c;

f>>n>>m;
for (i=0; i<=n+1; i++) l[i][0]=l[i][m+1]='X';
for (i=0; i<=m+1; i++) l[0][i]=l[n+1][i]='X';
f.get(c);
for (i=1; i<=n; i++)
	{for (k=1; k<=m; k++)
		{f.get(c); l[i][k]=c;
		 if (l[i][k]=='R') {xr=i; yr=k; l[i][k]=' ';}
		 if (l[i][k]=='J') {xj=i; yj=k; l[i][k]=' ';}
		}
	f.get(c);}
f.close();
}

void parcurge (int x0, int y0, int d[NMax][NMax])
{
struct Punct {int l, c;} C[NMax*NMax], p;
int inc=0, sf=0, i, k;
for (i=0; i<=n+1; i++)
	for (k=0; k<=m+1; k++) d[i][k]=-1;
C[0].l=x0; C[0].c=y0; d[x0][y0]=1;
while (inc<=sf)
	{
	 p=C[inc++];
	 for (i=0; i<NV; i++)
		if (l[p.l+dl[i]][p.c+dc[i]]==' ' && d[p.l+dl[i]][p.c+dc[i]]==-1)
			{
			d[p.l+dl[i]][p.c+dc[i]]=1+d[p.l][p.c];
			C[++sf].l=p.l+dl[i];
			C[sf].c=p.c+dc[i];
			}
	}
}

void afisare(int j[NMax][NMax])
{
ofstream f(OutFile);
int tmin=NMax*NMax+5, xmin=-1, ymin=-1, i, k;
for (i=1; i<=n; i++)
	for (k=1; k<=m; k++)
		if (r[i][k]==j[i][k])
			if (r[i][k]<tmin && r[i][k]!=-1)
				{tmin=r[i][k]; xmin=i; ymin=k;}
f<<tmin<<' '<<xmin<<' '<<ymin<<'\n';
f.close();
}
