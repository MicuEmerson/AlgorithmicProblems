#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int a[100][100];
int nr;
char c;

int tip(char c)
{
    if(c=='x') return 1;
    else return 0;
}

void afisare()
{
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=8; j++) cout<<a[i][j];
        cout<<endl;
    }
}

int main()
{
    fin>>c;
    a[1][2]=tip(c);
    fin>>c;
    a[1][4]=tip(c);
    fin>>c;
    a[1][6]=tip(c);
    fin>>c;
    a[1][7]=tip(c);
    fin>>c;
    a[1][8]=tip(c);
    fin>>c;
    a[2][2]=tip(c);
    fin>>c;
    a[2][3]=tip(c);
    fin>>c;
    a[2][4]=tip(c);
    fin>>c;
    a[2][5]=tip(c);
    fin>>c;
    a[2][6]=tip(c);
    fin>>c;
    a[2][7]=tip(c);
    fin>>c;
    a[2][8]=tip(c);
    fin>>c;
    a[3][1]=tip(c);
    fin>>c;
    a[3][2]=tip(c);
    fin>>c;
    a[3][3]=tip(c);
    fin>>c;
    a[3][4]=tip(c);
    fin>>c;
    a[3][5]=tip(c);
    fin>>c;
    a[3][6]=tip(c);
    fin>>c;
    a[3][7]=tip(c);
    fin>>c;
    a[3][8]=tip(c);
    fin>>c;
    a[4][1]=tip(c);
    fin>>c;
    a[4][2]=tip(c);
    fin>>c;
    a[4][3]=tip(c);
    fin>>c;
    a[4][4]=tip(c);
    fin>>c;
    a[4][5]=tip(c);
    fin>>c;
    a[4][6]=tip(c);
    fin>>c;
    a[4][7]=tip(c);
    fin>>c;
    a[4][8]=tip(c);
    fin>>nr;
    afisare();
    for(int j=1; j<=8; j++)
    {
        int s=0;
        int p=3;
        for(int i=1; i<=4; i++)
        {
            if(a[i][j]==1)
            {
                s+=pow(2,p);
            }
            p--;
        }
        cout<<s<<" ";
    }

    cout<<nr;
}
