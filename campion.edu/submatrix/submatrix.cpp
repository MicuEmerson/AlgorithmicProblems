#include <fstream>
using namespace std;
ifstream fi("submatrix.in");
ofstream fo("submatrix.out");
int n,m,i,j,sus,jos,p;
int A[101][101];
int S[101][101];
char c;
int L[101],R[101];
int L1,L2,C1,C2,maxi,maximum;
int main()
{
    fi>>n>>m;
    for(i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            fi>>c;
            A[i][j]=(int)(c-'0');
        }
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            S[i][j]=S[i-1][j]+A[i][j];
    maximum=A[1][1];
    L1=L2=C1=C2=1;
    for (sus=1; sus<=n; sus++)
        for (jos=sus; jos<=n; jos++)
        {
            for (i=1; i<=m; i++)
                if (S[jos][i]-S[sus-1][i]==jos-sus+1)
                    L[i]=1;
                else
                    L[i]=0;
            for (i=1; i<=m; i++)
                if (L[i]==0)
                    R[i]=0;
                else
                    R[i]=R[i-1]+1;
            maxi=0;
            p=0;
            for (i=1; i<=m; i++)
                if (R[i]>maxi)
                {
                    maxi=R[i];
                    p=i;
                }
            if (maxi*(jos-sus+1)>maximum)
            {
                maximum=maxi*(jos-sus+1);
                L1=sus;
                L2=jos;
                C1=p-maxi+1;
                C2=p;
            }
        }
    fo<<maximum<<"\n";
    fo<<L1<<" "<<C1<<" "<<L2<<" "<<C2;
    fi.close();
    fo.close();
    return 0;
}
