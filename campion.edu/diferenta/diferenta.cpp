#include <stdio.h>
using namespace std;
FILE *fi,*fo;
int n,m,a;
int i,j;

int f(int a)
{
	int rez,d;
	rez=0;
	for (d=1;d*d<=a;d++)
		if (a%d==0)
			if ((d+a/d)%2==0)
				rez++;
	return rez;
}

int main()
{
	fi=fopen("diferenta.in","r");
	fo=fopen("diferenta.out","w");
	fscanf(fi,"%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			fscanf(fi,"%d",&a);
			fprintf(fo,"%d ",f(a));
		}
		fprintf(fo,"\n");
	}
	fclose(fi);
	fclose(fo);
	return 0;
}