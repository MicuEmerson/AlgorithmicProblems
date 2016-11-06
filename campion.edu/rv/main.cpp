#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("rv.in");
ofstream fout("rv.out");

int i, j,n;
string a[100][100],b[100][100];
char c[100];

int main()
{

    cin>>c;
    n=strlen(c);
    for(i=0; i<n; i++)
    {
        a[i][i]=c[i];
        b[i][i]=c[i];
    }
    for(i=n-2; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
        {
            if(c[i]>c[j])
            {
                a[i][j]=c[i]+b[i+1][j];
                b[i][j]=c[j]+a[i][j-1];
            }
            else if(c[i]<c[j])
            {
                a[i][j]=c[j]+b[i][j-1];
                b[i][j]=c[i]+a[i+1][j];
            }
            else
            {
                a[i][j]=c[i]+max(b[i][j-1],b[i+1][j]);
                b[i][j]=c[i]+min(a[i][j-1],a[i+1][j]);
            }
        }
    }
    for(i=n-2; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
        {
            cout<<a[i][j]<<"  / "<<b[i][j]<<endl;
        }
        cout<<endl;
        cout<<"SPATIU"<<endl;
        cout<<endl;
    }
    cout<<"\n\n\n\n\n";

    fout<<a[0][n-1];



}
