#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int dl[4]= {0,-1,0,1};
int dc[4]= {1,0,-1,0};
int a[255][255],n;
char c;
queue < pair < int , int > > Q;

bool isOk(int i, int j)
{
    if(a[i][j]==-2 || a[i][j]==-1) return false;

    if(i>=1 && j>=1 && i<=n && j<=n) return true;

    return false;
}

void lee()
{

    while(!Q.empty())
    {

        int i=Q.front().first;
        int j=Q.front().second;
        Q.pop();
        for(int d=0; d<=3; d++)
        {
            int i_next=i+dl[d];
            int j_next=j+dc[d];
            if(isOk(j_next,i_next) && a[i_next][j_next]==0)
            {
                a[i_next][j_next]=a[i][j]+1;
                Q.push(make_pair(i_next,j_next));

            }
        }


    }
}

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            fin>>c;
            if(c=='.') a[i][j]=0;
            else if(c=='#') a[i][j]=-2;
            else
            {
                a[i][j]=-1;
                Q.push(make_pair(i,j));
            }
        }
    }
    lee();


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
