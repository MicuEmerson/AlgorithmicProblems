#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("dartz.in");
ofstream fout("dartz.out");
int s,x,y;
int main()
{
    fin>>s;
    s/=2;
    for(int i=1; i<=300; i++)
    {
        int rez=i*(i+1)*(i+2);
        int s2=s-rez;
        for(int j=1; j<=300; j++)
        {

            int rez2=j*(j+1)*(j+2);
            if(rez2==s2 && j!=i)
            {
                x=i;
                y=j;
                break;
            }
        }
        if(x!=0) break;

    }
    fout<<x<<" "<<y<<" "<<x<<" "<<y;


}
