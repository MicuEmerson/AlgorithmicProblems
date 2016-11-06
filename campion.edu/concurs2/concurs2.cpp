#include <fstream>
#define INF 1000000
using namespace std;
ifstream fi("concurs2.in");
ofstream fo("concurs2.out");
int n,k,i,j,p,c;
char X[1001];
int A[10][10];
int v,w;
int main()
{
	fi>>n>>k;
	fi>>X;
	for (i=0;i<=9;i++)
		for (j=0;j<=9;j++)
		{
			fi>>A[i][j];
			if (i==j && A[i][j]==1)
				A[i][j]=0;
		}
	for (i=0;i<=9;i++)
		for (j=0;j<=9;j++)
			if (i!=j && A[i][j]==0)
				A[i][j]=INF;
	// algoritmul Roy-Floyd
	for (p=0;p<=9;p++)
		for (i=0;i<=9;i++)
			for (j=0;j<=9;j++)
				A[i][j]=min(A[i][j],A[i][p]+A[p][j]);
	for (c=0;X[c]!='\0';c++)
	{
		v=(int)(X[c]-'0');
		w=-1;
		for (i=9;i>v;i--)
			if (A[v][i]<INF && A[v][i]<=k)
			{
				w=i;
				break;
			}
		if (w==-1)
			fo<<X[c];
		else
		{
			fo<<w;
			k=k-A[v][w];
		}
	}
	fi.close();
	fo.close();
	return 0;
}