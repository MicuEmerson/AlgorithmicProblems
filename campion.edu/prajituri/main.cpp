#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int n,m,x,miny=9999999;
int fn[101],fm[101];
char c1[10005],c2[10005],P[20010];
int Z[10005];
int l,r;
int p1,p2,lung;
int kp,beta;

int main()
{

    fin>>n>>m;
    for(int i=0;i<n;i++){
        fin>>x;
        fn[x]++;
        c1[i]=x+48;
    }

    for(int i=0;i<m;i++){
        fin>>x;
        fm[x]++;
        c2[i]=(char)x;
    }

    for(int i=0;i<=100;i++){
        if(fn[i]!=0 && fm[i]!=0){
            miny=min(miny,fn[i]);
        }
    }

    P[0]='.';
    P[1]='\0';
    strcat(P,c1);
    strcat(P,"$");
    strcat(P,c2);
    n=strlen(P+1);
    Z[0]=Z[1]=0;
    l=r=0;
    cout<<P;
    for (int k=2; k<=n; k++)
        // se calculeaza Z[k]
        if (r<k)
        {
            p1=1;
            p2=k;
            lung=0;
            while (P[p1]==P[p2])
            {
                p1++;
                p2++;
                lung++;
            }
            if (lung==0)
                Z[k]=0;
            else
            {
                Z[k]=lung;
                l=k;
                r=p2-1;
            }
        }
        else
        {
            kp=k-(l-1);
            beta=r-(k-1);
            if (Z[kp]<beta)
                Z[k]=Z[kp];
            else
            {
                p2=r+1;
                p1=beta+1;
                lung=0;
                while (P[p1]==P[p2])
                {
                    p1++;
                    p2++;
                    lung++;
                }
                l=k;
                r=p2-1;
                Z[k]=beta+lung;
            }
        }

    for (int i=1; i<=n; i++)
        cout<<Z[i]<<" ";
    return 0;




}
