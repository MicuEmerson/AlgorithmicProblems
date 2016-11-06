#include <stdio.h>
#include <vector>
using namespace std;
FILE *fi, *fo;
int N,M,i,a,b,varf;
vector <int> V[100001];
vector <int> :: iterator it;
int X[100001],nX;
int Q[100001],p,u;
int VIZ[100001];
int nY,Y;

int main()
{
	fi=fopen("grafxy.in","r");
	fo=fopen("grafxy.out","w");
	fscanf(fi,"%d%d",&N,&M);
	for (i=1;i<=M;i++)
	{
		fscanf(fi,"%d%d",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	fscanf(fi,"%d",&nX);
	for (i=1;i<=nX;i++)
		fscanf(fi,"%d",&X[i]);
	p=1;
	u=0;
	fscanf(fi,"%d",&nY);
	for (i=1;i<=nY;i++)
	{
		fscanf(fi,"%d",&Y);
		VIZ[Y]=1;
		u++;
		Q[u]=Y;
	}
	while (p<=u)
	{
		// vecinii nevizitati ai lui Q[p] se depun la sfarsitul lui Q
		varf=Q[p];
		for (it=V[varf].begin();it!=V[varf].end();it++)
			if (VIZ[*it]==0)
			{
				VIZ[*it]=1+VIZ[varf];
				u++;
				Q[u]=(*it);
			}
		p++;
	}
	for (i=1;i<=nX;i++)
		fprintf(fo,"%d\n",VIZ[X[i]]-1);
	fclose(fi);
	fclose(fo);
	return 0;
}

