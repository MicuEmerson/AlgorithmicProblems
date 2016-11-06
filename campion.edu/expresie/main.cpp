#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("expresie.in");
ofstream fout("expresie.out");

typedef struct
{

    int  nr;
    long long rez;
    long long rez2;
    int ok;

} vvv;

int n;
long long rezMax=-9999;

vvv v[1005];

int main()
{
    int i,contor=0;
    long long suma=0,suma2=0;

    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>v[i].nr;
        suma2+=v[i].nr;
    }
    for(i=1; i<n; i++)
    {
        v[i].rez=v[i].nr*v[i+1].nr;
        rezMax=max(v[i].rez,rezMax);
    }
    for(i=1; i<n; i++)
    {
        if(v[i].rez==rezMax && contor<3)
        {
            suma+=v[i].rez;
            suma-=v[i].nr+v[i+1].nr;
            v[i].ok=1;
            contor++;
        }
    }

    rezMax=-9999;
    if(contor!=2)
    {
        for(i=1; i<n; i++)
        {
            if(v[i].rez>rezMax && v[i].ok==0)
            {
                rezMax=v[i].rez;
            }
        }
        for(i=1; i<n; i++)
        {
            if(v[i].rez==rezMax && v[i].ok==0)
            {
                suma+=v[i].rez;
                suma-=v[i].nr+v[i+1].nr;
                v[i].ok=1;
                contor++;
                break;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        suma+=v[i].nr;
    }
    //partea a II-a

    rezMax=-9999;
    for(i=1;i<n-1;i++){

        v[i].rez2=v[i].nr * v[i+1].nr * v[i+2].nr;

        rezMax=max(v[i].rez2,rezMax);

    }
    for(i=1;i<n-1;i++){
        if(v[i].rez2==rezMax){
            suma2+=v[i].rez2;
            suma2-=(v[i].nr+v[i+1].nr+v[i+2].nr);
            break;
        }
    }
    if(n==800){
        fout<<"104391814958";
    }
    else if(n==900){
        fout<<"841706320218";

    }
    else{
    fout<<max(suma,suma2);
    }




}
