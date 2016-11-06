#include <fstream>
#include <iostream>
using namespace std;
ifstream fi("vizibil.in");
ofstream fo("vizibil.out");
int n,p,q;
int i,j,k;
int S[101][101];
int C[101][101];
int rez;

int main()
{
	fi>>n>>p>>q;
	for (i=0;i<=n;i++)
		C[i][i]=C[i][0]=1;
	for (i=2;i<=n;i++)
		for (j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%997;
	S[0][0]=1;
	for (i=1;i<=n;i++)
		S[i][i]=1;
	for (i=2;i<=n;i++)
		S[i][1]=S[i-1][1]*(i-1)%997;
	for (i=3;i<=n;i++)
		for (j=2;j<i;j++)
			S[i][j]=(S[i-1][j-1]+(i-1)*S[i-1][j])%997;
	rez=0;
	for (k=1;k<=n;k++)
		rez=(rez+C[n-1][k-1]*S[k-1][p-1]*S[n-k][q-1])%997;
	fo<<rez;
	fi.close();
	fo.close();
	return 0;
}
