#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("bursa.out");

int n,s;
int v[505];
int c[505];
int main()
{
    int i,x=99999,y=99999,j;
    int cumparator,rez,rezMax=-9999;

    fin>>n>>s;
    for(i=1; i<=n; i++)
    {
        fin>>c[i];
    }
    for(i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    for(i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(i=1; i<n; i++)
    {
        cumparator=s/c[i];

        for(j=i+1; j<=n; j++)
        {
            rez=cumparator*v[j];

            if(rez>rezMax)
            {
                rezMax=rez;
                x=i;
                y=j;
            }
            else if(rez==rezMax)
            {
                if(i<x)
                {
                    rezMax=rez;
                    x=i;
                    y=j;
                }
                else if(i==x)
                {
                    if(j<y)
                    {
                        rezMax=rez;
                        x=i;
                        y=j;
                    }
                }
            }
        }
    }
    if(rezMax<s)
    {
        cout<<s<<endl<<"-1"<<" "<<"-1";
    }
    else
    {
        cout<<rezMax<<endl<<x<<" "<<y;
    }




}
