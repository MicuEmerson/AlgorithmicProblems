#include <fstream>
using namespace std;
ifstream f("v.in");
ofstream g("v.out");
long a[101][101],m,n,i,j,q,w,e,r,t,mx,col,lin,cel,mincel;
void citire()
{
    f>>m>>n;
    for  (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            f>>a[i][j];
}
long s(long col,long lin)
{s
    long i,j,x;
    i=1;
    j=col;
    x=a[i][j];
    cel=0;
    while (i<lin)
    {
        i++;
        j++;
        x+=a[i][j];
        cel++;
    }
    while ((i>1)&&(j<n))
    {
        i--;
        j++;
        x+=a[i][j];
        cel++;
    }
    if (i==1) return x;
    else return -2000000000;
}
int main()
{
    mx=-2000000000;
    mincel=0;
    citire();
    for (i=1; i<=n; i++)
        for (j=2; j<=m; j++)
        {
            q=s(i,j);
            if (q>mx)
            {
                mx=q;
                col=i;
                lin=j;
                mincel=cel;
            }
            else if ((q==mx)&&(cel<mincel))
            {
                mx=q;
                col=i;
                lin=j;
                mincel=cel;
            }

        }
    g<<mx<<" "<<col<<" "<<lin<<"\n";
    f.close();
    g.close();
    return 0;
}
