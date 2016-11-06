#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

const int MAXN=202,MAXM=5002;

char c[MAXN][MAXM],maxy[MAXM],x[MAXM];

int n,tip,dim,f[MAXN][130],marcat[MAXN],cate;

ab
baa


int main()
{
    fin>>tip>>n;

    if(tip==1)
    {
        fin>>maxy;
        for(int i=2;i<=n;i++){
            fin>>x;
            if(strlen(x)>strlen(maxy)) strcpy(maxy,x);
            else if(strlen(x)==strlen(maxy) && strcmp(x,maxy)>0) strcpy(maxy,x);
        }
        cout<<maxy;
    }
    else
    {
        for(int i=1; i<=n; i++) fin>>c[i];

        for(int i=1; i<=n; i++)
            for(int j=0; j<strlen(c[i]); j++)
                f[i][c[i][j]]++;

        /*
        //afiasare frecventa
        for(int i=1; i<=n; i++)
        {
            for(int j=97; j<=122; j++)
            {
                cout<<(char)j<<":"<<f[i][j]<<" ";
            }
            cout<<endl;
        }
        */


        for(int i=1; i<=n; i++)
        {
            int ok=0;
            for(int j=1; j<=n; j++)
            {
                bool gasit=true;
                for(int p=97; p<=122; p++)
                {
                    if(f[i][p]>f[j][p]) gasit=false;
                }
                if(gasit) ok++;
            }

            if(ok==1) marcat[i]=1;
        }

        for(int i=1;i<=n;i++) if(marcat[i]) cate++;

        cout<<cate<<"\n";
        for(int i=1;i<=n;i++) if(marcat[i]) cout<<c[i]<<"\n";

    }

}
