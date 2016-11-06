#include <fstream>

using namespace std;
ifstream fi("sport.in");
ofstream fo("sport.out");
int n,i,j,nr,H[1001];
int P[1001],L[1001];
int rez;
int main()
{
	fi>>n;
	for (i=1;i<=n;i++)
		fi>>H[i];
	for (i=1;i<=n;i++)
	{
		nr=0;
		for(j=1;j<=n;j++)
			if (H[j]<H[i])
				nr++;
		P[i]=nr+1;
	}
	L[n]=1;
	for (i=n-1;i>=1;i--)
	{
		L[i]=0;
		for (j=i+1;j<=n;j++)
			if (P[j]==P[i]+1)
				L[i]=L[j];
		L[i]++;
	}
	rez=0;
	for (i=1;i<=n;i++)
		if (L[i]>rez)
			rez=L[i];
	fo<<n-rez;
	fi.close();
	fo.close();
	return 0;
}