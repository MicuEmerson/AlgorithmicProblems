#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
ifstream fin("text.txt");
ofstream fout("circular.out");

const int MAXN=20005;
int n,gasit;
char a[MAXN*2],b[MAXN];


int main()
{

    fin>>n;
    fin.get();
    getline(fin,a);
    getline(fin,b);
    for(int i=strlen(a); i<=strlen(a)*2; i++)
    {

    }






}

#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=20005;
char P[3010],A[MAXN],B[MAXN];
int Z[1000];
int n,l,r,k;
int p1,p2,lung;
int kp,i,beta;

int main()
{
    P[0]='.';
    P[1]='\0';
    fin>>n;
    fin.get();
    getline(fin,A);
    getline(fin,B);

    strcat(P,A);
    strcat(P,"$");
    strcat(P,B);
    n=strlen(P+1);
    Z[0]=Z[1]=0;
    l=r=0;
    for (k=2; k<=n; k++)
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

    for (i=1; i<=n; i++)
        cout<<Z[i]<<" ";
    return 0;
}

