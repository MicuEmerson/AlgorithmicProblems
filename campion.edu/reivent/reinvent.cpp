#include <stdio.h>
#include <vector>
using namespace std;
FILE *fi, *fo;
int n,m,x,i,v1,v2,p,u,vf,w;
vector <int> V[100001];
int Q[100001],VIZ[100001];
int P[100001];
int rez;
int main()
{
	fi=fopen("reinvent.in","r");
	fo=fopen("reinvent.out","w");
	fscanf(fi,"%d%d%d",&n,&m,&x);
	for (i=1;i<=m;i++)
	{
		fscanf(fi,"%d%d",&v1,&v2);
		V[v1].push_back(v2);
		V[v2].push_back(v1);
	}
	for (i=1;i<=x;i++)
	{
		fscanf(fi,"%d",&Q[i]);
		VIZ[Q[i]]=1;
	}
	p=1;
	u=x;
	while (p<=u)
	{
		vf=Q[p];
		for (i=0;i<V[vf].size();i++)
		{
			w=V[vf][i];
			if (VIZ[w]==0)
			{
				u++;
				Q[u]=w;
				VIZ[w]=1+VIZ[vf];
				P[w]=vf;
			}
			else
				if (P[vf]==w)
					;
				else
				{
					rez=VIZ[vf]+VIZ[w]-1;
					fprintf(fo,"%d",rez);
					fclose(fi);
					fclose(fo);
					return 0;
				}
		}
		p++;
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
