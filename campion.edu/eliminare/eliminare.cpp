#include <stdio.h>
using namespace std;
FILE *fi,*fo;
int N,Q;
int A[100002];
int i,x,st,dr,m;
int main()
{
	fi=fopen("eliminare.in","r");
	fo=fopen("eliminare.out","w");
	fscanf(fi,"%d%d",&N,&Q);
	A[0]=0;
	for (i=1;i<=N;i++)
		fscanf(fi,"%d",&A[i]);
	for (i=1;i<=Q;i++)
	{
		fscanf(fi,"%d",&x);
		// cautare binara
		// cel mai mare numar din A
		// care este <=x
		st=0;
		dr=N;
		while (st<dr)
		{
			m=(st+dr+1)>>1;
			if (A[m]>x)
				dr=m-1;
			else
				st=m;
		}
		if (A[st]==x)
			fprintf(fo,"%d\n",0);
		else
			fprintf(fo,"%d\n",x-st);
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
