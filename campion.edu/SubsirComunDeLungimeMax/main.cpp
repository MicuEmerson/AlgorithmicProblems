#include <iostream>
#include <string.h>
using namespace std;

void afisare(int a[255][255], int n, int m)
{

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



}


int main()
{
    char x[255];
    char y[255];
    int a[255][255];
    int n,m,i,j;
    cin>>x>>y;
    n=(int)strlen(y);
    m=(int)strlen(x);


    //prima lin
    for(j=0; j<m; j++)
    {
        if(y[0]==x[j])
        {
            while(j<m)
            {
                a[0][j]=1;
                j++;
            }
        }
        else
        {
            a[0][j]=a[0][j-1];
        }
    }

    // prima col
    for(i=0; i<n; i++)
    {
        if(x[0]==y[i])
        {
            while(i<n)
            {
                a[i][0]=1;
                i++;
            }
        }
        else
        {
            a[i][0]=a[i-1][0];
        }
    }
    //ceva bug remediat, nush dc imi pune pe prima 1 si daca nu trebuie, dar cu asta remediem
    if(x[0]!=y[0])
    {
        a[0][0]=0;
    }



    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            if(x[j]==y[i])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                }
                else
                {
                    a[i][j]=a[i][j-1];
                }
            }
        }
    }
    afisare(a,n,m);





}
