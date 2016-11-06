#include <iostream>
#include <fstream>
using namespace std;
//ifstream fin("text.txt");
//ofstream fout("text1.txt");
char a[10][10];
int dimW,dimB,rez,rez1;
pair < int , int > w[100];
pair < int , int > b[100];

int isOk1(int x, int y)
{

    for(int i=x-1; i>=1; i--)
    {
        if(a[i][y]!='.')
        {
            return -1;
        }
    }
    return x-1;
}

int isOk2(int x, int y)
{

    for(int i=x+1; i<=8; i++)
    {
        if(a[i][y]!='.')
        {
            return -1;
        }
    }
    return 8-x;
}

int main()
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='B')
            {
                ++dimB;
                b[dimB].first=i;
                b[dimB].second=j;
            }
            if(a[i][j]=='W')
            {
                ++dimW;
                w[dimW].first=i;
                w[dimW].second=j;
            }
        }
    }

    for(int i=1; i<=dimW; i++)
    {
        int x,y;
        x=w[i].first;
        y=w[i].second;
        rez=isOk1(x,y);
        if(rez!=-1)
        {
            break;
        }
    }

    for(int i=dimB; i>=1; i--)
    {
        int x,y;
        x=b[i].first;
        y=b[i].second;
        rez1=isOk2(x,y);
        if(rez1!=-1)
        {
            break;
        }
    }

    if(rez<=rez1)
    {
        cout<<"A";
    }
    else
    {
        cout<<"B";
    }

}
