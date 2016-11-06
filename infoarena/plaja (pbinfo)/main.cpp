#include <bits/stdc++.h>

using namespace std;

int n,m,a[1005][1005];
vector < pair<int,int> > v[1005];


int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>a[i][j];

    for(int j=1; j<=m; j++)
    {
        for(int i=1; j<=n; j++)
        {
            if(a[i][j] == 0)
            {

                int ii=i;
                while(a[ii][j] == 0 && ii<=n) ii++;
                ii--;
                pair <int , int > x;
                x.first=i;
                x.second=ii;
                v[j].insert( x);

            }
        }
    }

    for(int j=1; j<=m; j++)
    {

        for(auto it: v[j])
            cout<< "(" << it.first << "," << it.second << ") ";

                cout<<endl;

    }




}
