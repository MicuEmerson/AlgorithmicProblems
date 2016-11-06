#include <iostream>
using namespace std;

typedef struct
{

    char nume[30];
    int p1,p2,p3;


} vvv;

vvv v[205];
int n;
int a[205][205],m;

int comparare(int i, int j)
{

    int nr1=0,nr2=0;
    if(v[i].p1>v[j].p1)
    {
        nr1++;
    }
    else
    {
        nr2++;
    }

    if(v[i].p2>v[j].p2)
    {
        nr1++;
    }
    else
    {
        nr2++;
    }

    if(v[i].p3>v[j].p3)
    {
        nr1++;
    }
    else
    {
        nr2++;
    }

    if(nr1>nr2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


void creareArce()
{
    int i,j;
    for(i=1; i<n; i++)
    {

        for(j=i+1; j<=n; j++)
        {
            if(comparare(i,j)==1)
            {
                a[i][j]=1;
            }
            else
            {
                a[j][i]=1;
            }
        }
    }
}


void RW()
{
    int i,j,k;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i!=j && j!=k && k!=i)
                {
                    if(a[i][k]==1 && a[k][j]==1)
                    {
                        a[i][j]=1;
                    }
                }
            }
        }
    }

}

int suma(int i){

  int s=0;
  for(int j=1;j<=n;j++){
    s+=a[i][j];
  }
  return s;
}


int main()
{

    int i;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>v[i].nume;
        cin>>v[i].p1>>v[i].p2>>v[i].p3;
        cin.get();
    }

    creareArce();

    RW();

    for(i=1;i<=n;i++){
        if(suma(i)==n-1){
            cout<<v[i].nume<<endl;
        }
    }

}
