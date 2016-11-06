#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("soldati1.in");
ofstream fout("soldati1.out");
long long  n,k,a[105][105][105];


void mul(int a[], int b)
{
    int i, t = 0;
    for (i = 1; i <= a[0] || t; i++, t /= 10)
        a[i] = (t += a[i] * b) % 10;
    a[0] = i - 1;
}






int main()
{
    int i,j;
    fin>>n>>k;
    for(i=1; i<=n; i++)
    {
        a[i][i]=1;
        a[i][1]=1;
    }
    for(i=3; i<=n; i++)
    {
        for(j=2; j<=i-1; j++)
        {


            a[i][j]=j*a[i-1][j] + a[i-1][j-1] * (i-j+1);


        }
    }
    /*
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    fout<<a[n][k];


}
