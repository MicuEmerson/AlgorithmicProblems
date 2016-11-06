#include <stdio.h>
#include <queue>
using namespace std;
typedef pair <int,int> PERECHE;
FILE *fi,*fo;
int N,i,rez;
PERECHE P[10001],PER;
priority_queue <PERECHE> H;
int main()
{
	fi=fopen("piloti.in","r");
	fo=fopen("piloti.out","w");
	fscanf(fi,"%d",&N);
	for (i=1;i<=N;i++)
		fscanf(fi,"%d%d",&P[i].first,&P[i].second);
	rez=P[1].second;
	P[1].second=0;
	for (i=2;i<=N-1;i=i+2)
	{
		PER.first=P[i].first-P[i].second;
		PER.second=i;
		H.push(PER);
		PER.first=P[i+1].first-P[i+1].second;
		PER.second=i+1;
		H.push(PER);
		PER=H.top();
		H.pop();
		rez=rez+P[PER.second].second;
		P[PER.second].second=0;
	}
	for (i=1;i<=N;i++)
		if (P[i].second!=0)
			rez=rez+P[i].first;
	fprintf(fo,"%d",rez);
	fclose(fi);
	fclose(fo);
	return 0;
}
