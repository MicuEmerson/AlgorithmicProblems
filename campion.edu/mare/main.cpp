#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");

int n,lin=1;
int v[105];
int a[110][1100];

int isPal(int st, int dr, int lin)
{
    int dim=0,i,x,j;
    for(i=dr; i>=st; i--)
    {

        x=v[i];
        if(x==0)
        {
            a[lin][0]++;
            a[lin][1]=0;
        }
        else
        {
            while(x>0)
            {
                a[lin][++dim]=x%10;
                x/=10;
            }
        }
    }

    a[lin][0]=dim;
    j=a[lin][0];

    for(i=1; i<=a[lin][0]/2; i++)
    {
        if(a[lin][i]!=a[lin][j])
        {
            a[lin][1100]=-1;
            break;
        }
        j--;
    }

    if(a[lin][1100]==-1)
    {
        return 0;

    }
    else
    {
        a[lin][1100]=1;
        return 1;

    }




}




int main()
{
    int i,j,gasit;

    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }

    for(i=1; i<=n; i++)
    {

        gasit=0;
        j=n;

        if(isPal(i,j,lin)==0)
        {
            while(isPal(i,j,lin)==0 && j>=i)
            {
                j--;
                lin++;
            }
        }

    }
    cout<<lin<<endl;

    for(i=1; i<=lin; i++)
    {


        for(j=1; j<=a[i][0]; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl<<endl;

    }





}
