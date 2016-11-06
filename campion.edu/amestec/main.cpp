#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

typedef struct
{

    int cat;
    char dir;
    int tip;

} vvv;

int n,k;
int a[101][101];
vvv v[101];

int isOk(int mutare)
{

    if(mutare<=n && mutare>=1)
    {
        return 1;
    }
    return 0;

}

void schimbare(int care)
{

    queue < pair <int , int > > coada;
    if(v[care].dir=='N')
    {
        while(v[care].cat)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j]==v[care].tip && a[i+1][j]!=v[care].tip && isOk(i+1)==1)
                    {
                        coada.push(make_pair(i,j));
                    }
                }
            }
            if(!coada.empty())
            {
                while(!coada.empty())
                {
                    int x,y;
                    x=coada.front().first;
                    y=coada.front().second;
                    coada.pop();
                    swap(a[x][y],a[x+1][y]);
                }
            }
            else
            {
                break;
            }
            v[care].cat--;
        }
    }
    else if(v[care].dir=='S')
    {
        while(v[care].cat)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j]==v[care].tip && a[i-1][j]!=v[care].tip && isOk(i-1)==1)
                    {
                        coada.push(make_pair(i,j));
                    }
                }
            }
            if(!coada.empty())
            {
                while(!coada.empty())
                {
                    int x,y;
                    x=coada.front().first;
                    y=coada.front().second;
                    swap(a[x][y],a[x-1][y]);
                    coada.pop();
                }
            }
            else
            {
                break;
            }
            v[care].cat--;
        }
    }
    else if(v[care].dir=='V')
    {
        while(v[care].cat)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j]==v[care].tip && a[i][j-1]!=v[care].tip && isOk(j-1)==1)
                    {
                        coada.push(make_pair(i,j));
                    }
                }
            }
            if(!coada.empty())
            {
                while(!coada.empty())
                {
                    int x,y;
                    x=coada.front().first;
                    y=coada.front().second;
                    swap(a[x][y],a[x][y-1]);
                    coada.pop();
                }
            }
            else
            {
                break;
            }
            v[care].cat--;
        }
    }
    else
    {
        while(v[care].cat)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j]==v[care].tip && a[i][j+1]!=v[care].tip && isOk(j+1)==1)
                    {
                        coada.push(make_pair(i,j));
                    }
                }
            }
            if(!coada.empty())
            {
                while(!coada.empty())
                {
                    int x,y;
                    x=coada.front().first;
                    y=coada.front().second;
                    swap(a[x][y],a[x][y+1]);
                    coada.pop();
                }
            }
            else
            {
                break;
            }
            v[care].cat--;
        }
    }
}





int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char c;
            fin>>c;
            if(c=='1')
            {
                a[i][j]=1;
            }

        }
    }
    for(int i=1; i<=k; i++)
    {
        fin>>v[i].cat>>v[i].dir>>v[i].tip;
    }

    for(int i=1; i<=k; i++)
    {
        schimbare(i);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<endl;
    }













}
