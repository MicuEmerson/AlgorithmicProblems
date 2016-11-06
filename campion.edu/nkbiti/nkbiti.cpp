#include <fstream>
#define MOD 666777
using namespace std;
typedef struct matrice {long long V[42][42];} MATRICE;
int N,K,rez,i,j;
ifstream fi("nkbiti.in");
ofstream fo("nkbiti.out");
MATRICE Q;

MATRICE produs(MATRICE A, MATRICE B)
{
	int i,j,k;
	MATRICE C;
	for (i=0;i<=K;i++)
		for (j=0;j<=K;j++)
		{
			C.V[i][j]=0;
			for (k=0;k<=K;k++)
				C.V[i][j]=(C.V[i][j]+A.V[i][k]*B.V[k][j]) % MOD;
		}
	return C;
}

MATRICE putere(MATRICE A, int n)
{
	MATRICE X,HALF;
	int i,j;
	if (n==0)
	{
		for (i=0;i<=K;i++)
			for (j=0;j<=K;j++)
				if (i!=j)
					X.V[i][j]=0;
				else
					X.V[i][j]=1;
		return X;
	}
	HALF=putere(A,n/2);
	X=produs(HALF,HALF);
	if (n%2==1)
		X=produs(X,A);
	return X;
}

int main()
{
	fi>>N>>K;
	for (i=0;i<=K;i++)
		for (j=0;j<=K;j++)
			if (j==0 || j==i+1)
				Q.V[i][j]=1;
			else
				Q.V[i][j]=0;
	Q=putere(Q,N);
	rez=0;
	for (i=0;i<=K;i++)
		rez=(rez+Q.V[0][i])% MOD;
	fo<<rez;
	fi.close();
	fo.close();
	return 0;
}
