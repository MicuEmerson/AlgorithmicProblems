#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("renju.in");
ofstream fout("renju.out");

int n=19,a[20][20],i,j,d,contor;
int dl[4]= {0,1,1,1};
int dc[4]= {1,1,0,-1};
int linBun,colBun;
int l_next,c_next;

int main()
{
    //citire
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fin>>a[i][j];
        }
    }

    //parcurgere
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {

            for(d=0; d<=3; d++)
            {
                contor=1;
                l_next=i+dl[d];
                c_next=j+dc[d];

                if(a[i][j]==1)
                {
                    while(a[l_next][c_next]==1)
                    {
                        contor++;
                        l_next+=dl[d];
                        c_next+=dc[d];
                    }
                    if(contor==5 && a[i-dl[d]][j-dc[d]]!=1)
                    {
                        if(dl[d]==1 && dc[d]==-1)
                        {
                            linBun=l_next-dl[d];
                            colBun=c_next-dc[d];
                        }
                        else
                        {
                            linBun=l_next-5*dl[d];
                            colBun=c_next-5*dc[d];
                        }
                        break;
                    }
                }
                if(a[i][j]==2)
                {
                    while(a[l_next][c_next]==2)
                    {
                        contor++;
                        l_next+=dl[d];
                        c_next+=dc[d];
                    }
                    if(contor==5 && a[i-dl[d]][j-dc[d]]!=2)
                    {
                        if(dl[d]==1 && dc[d]==-1)
                        {
                            linBun=l_next-dl[d];
                            colBun=c_next-dc[d];
                        }
                        else
                        {
                            linBun=l_next-5*dl[d];
                            colBun=c_next-5*dc[d];
                        }
                        break;
                    }
                }
            }
        }
    }

    if(linBun==0 && colBun==0)
    {
        fout<<"0";
    }
    else if (a[linBun][colBun]==1)
    {
        fout<<"1"<<endl<<linBun<<" "<<colBun;
    }
    else
    {
        fout<<"2"<<endl<<linBun<<" "<<colBun;
    }



}
