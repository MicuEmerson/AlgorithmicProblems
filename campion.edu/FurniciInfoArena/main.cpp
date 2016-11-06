#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;


int main()
{
    fin=fopen("furnici1.in","r");
    fout=fopen("furnici1.out","w");
    int l,n,i,dist,distMax=-999999;
    char c;
    fscanf(fin,"%d",&l);
    fscanf(fin,"%d",&n);

    for(i=1; i<=n; i++){
        fscanf(fin,"%d",&dist);
        fscanf(fin,"%c",&c);
        fscanf(fin,"%c",&c);


        if(c=='D')
        {
            dist=l-dist;
        }
        if(distMax<dist)
        {
            distMax=dist;
        }
    }
    fprintf(fout,"%d",distMax);

}

/*
#include<stdio.h>
#define MAX_N 1000005

int b[MAX_N],f[MAX_N];
int n,m;
int i,x,y;
int maxP;
int ft,bt;

int main()
{


	freopen("bal.in","r",stdin);
	freopen("bal.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&x,&y);
		b[x]++;
		b[y+1]--;

	}
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&x,&y);
		f[x]++;
		f[y+1]--;

	}
	for(i=1;i<MAX_N;i++)
	{
		if(f[i] || b[i])
		{
			if(f[i]==1) ft++;
			if(b[i]==1) bt++;

			maxP = max(maxP,min(ft,bt));
		}

		if(f[i]==-1) ft--;
		if(b[i]==-1) bt--;
	}
	printf("%d",maxP);

	fclose(stdin); fclose(stdout);
	return 0;
}
*/
