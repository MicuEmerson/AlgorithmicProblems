#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("relatii.in");
ofstream fout("relatii.out");

typedef struct
{
    int nr;
    int ok;
} sss;


int n,m,x;
int a[100][100];
char xx,semn,yy;
sss s[100];


int transformareLitere(char c)
{
    if(c=='a') return 1;
    if(c=='b') return 2;
    if(c=='c') return 3;
    if(c=='d') return 4;
    if(c=='e') return 5;
    if(c=='f') return 6;
    if(c=='g') return 7;
    if(c=='h') return 8;
    if(c=='i') return 9;
    if(c=='j') return 10;
}
char transformareCifre(int c)
{
    if(c==1) return 'a';
    if(c==2) return 'b';
    if(c==3) return 'c';
    if(c==4) return 'd';
    if(c==5) return 'e';
    if(c==6) return 'f';
    if(c==7) return 'g';
    if(c==8) return 'h';
    if(c==9) return 'i';
    if(c==10) return 'j';
}

int celMaiMic()
{
    int miny=99999;
    for(int i=1; i<=n; i++)
    {
        if(miny>s[i].nr && s[i].ok==0)
        {
            miny=s[i].nr;
        }
    }
    return miny;

}

int main()
{
    int i,j,k;
    fin>>n>>m;
    fin.get();
    for(i=1; i<=m; i++)
    {

        fin>>xx>>semn>>yy;

        if(semn=='>'){
            a[transformareLitere(xx)][transformareLitere(yy)]=1;
        }
        else{
            a[transformareLitere(yy)][transformareLitere(xx)]=1;
        }

    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            s[i].nr+=a[i][j];
        }
    }



    x=celMaiMic();


    while(x!=99999)
    {

        for(i=1; i<=n; i++)
        {

            if(s[i].nr==x && s[i].ok==0)
            {
                fout<<transformareCifre(i);
                s[i].ok=1;

                for(k=1; k<=n; k++)
                {
                    if(a[k][i]==1)
                    {
                        s[k].nr--;
                    }
                }

                i=0;
                x=celMaiMic();
            }
        }



    }

}



