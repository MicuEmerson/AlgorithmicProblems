#include <stdio.h>
using namespace std;
FILE *fi,*fo;
int N,i;
int L[100002],B[100002];
long long CB[100002];
int st,dr,m;
int main()
{
	fi=fopen("ants.in","r");
	fo=fopen("ants.out","w");
	fscanf(fi,"%d",&N);
	for (i=1;i<=N;i++)
		fscanf(fi,"%d%d",&L[i],&B[i]);
	L[N+1]=L[N];
	B[N+1]=0;
	st=0;
	dr=1000000000;
	while (st<dr)
	{
		for (i=1;i<=N+1;i++)
			CB[i]=(long long)B[i];
		m=((st+dr)>>1)+1;
		// se verifica daca pot fi invitati cel putin m greieri
		for (i=1;i<=N;i++)
			if (CB[i]>=m)
				if (L[i+1]-L[i]>CB[i]-m)
					;
				else
					CB[i+1]=CB[i+1]+(CB[i]-m)-(L[i+1]-L[i]);
			else
				CB[i+1]=CB[i+1]-(m-CB[i])-(L[i+1]-L[i]);
		if (CB[N+1]>=0)
			st=m;
		else
			dr=m-1;
	}
	fprintf(fo,"%d",st);
	fclose(fi);
	fclose(fo);
	return 0;
}