#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("text.txt");

typedef struct
{

    int poz[100];
    int dim;

} vct;

vct b[100];
int i,j,n,a[10000],nrS=0,vf[100];

void cautareBinar(int st,int dr,int elem)
{

   int m,gasit=0
   while(st<=dr && gasit == 0)
   {
        m=(st+dr)/2;
        if(elem==vf[m])
        {
            gasti=1;
        }
        else{
            if(vf[m]>elem){
                st=m+1;
            }
            else{
                dt=m-1;
            }
        }
    }
    if(gasit==1){
            b[m-1].dim++;
        b[m-1].poz[b[m-1].dim]=elem;
    }
    else{

        if(vf[nrS]>elem){
            nrS++;
            b[nrS].dim++;
            b[nrS].poz[b[nrS].dim]=elem;
        }
    }



}


int main()
{


    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }




}
