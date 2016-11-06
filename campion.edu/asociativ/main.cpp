#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("asociativ.in");
ofstream fout("asociativ.out");

int n,v[5],dim,contor;
string aa,bb,cc,x;
int a[110],b[110],c[110];
int dimMax;

typedef struct
{

    int total[310];

} vvv;


vvv adunareDoua( int a[310], int b[310], int dimA, int dimB)
{

    vvv t;
    int sum;
    t.total[0]=0;
    int dimMax=max(dimA,dimB);

    for(int i=1; i<=dimMax; i++)
    {
        sum=0;
        if(i<=dimA)
        {
            sum+=a[i];
        }
        if(i<=dimB)
        {
            sum+=b[i];
        }
        if(sum<=9)
        {
            t.total[++t.total[0]]=sum;

        }
        else
        {
            t.total[++t.total[0]]=sum%10;
            t.total[++t.total[0]]=sum/10;
        }
    }
    return t;
}

bool comparare(vvv a, vvv b)
{

    if(a.total[0]!=b.total[0])
    {
        return false;
    }
    else
    {
        for(int i=1; i<=a.total[0]; i++)
        {
            if(a.total[i]!=b.total[i])
            {
                return false;
            }
        }
    }
    return true;
}




int main()
{
    fin>>n;
    fin.get();
    for(int j=1; j<=n; ++j)
    {
        getline(fin,x);

        dim=0;
        for(int i=0; i<=x.size(); i++)
            if(x[i]==' ') v[++dim]=i;

        aa=x.substr(0,v[1]);
        bb=x.substr(v[1]+1,v[2]-v[1]-1);
        cc=x.substr(v[2]+1,x.size()-v[2]-1);

        a[0]=0;
        for(int i=aa.size()-1; i>=0; i--)
        {
            a[++a[0]]=(int)aa[i]-48;
        }

        b[0]=0;
        for(int i=bb.size()-1; i>=0; i--)
        {
            b[++b[0]]=(int)bb[i]-48;
        }

        c[0]=0;
        for(int i=cc.size()-1; i>=0; i--)
        {
            c[++c[0]]=(int)cc[i]-48;
        }


        vvv t1=adunareDoua(a,b,a[0],b[0]);
        t1=adunareDoua(t1.total,c,t1.total[0],c[0]);

        vvv t2=adunareDoua(c,b,c[0],b[0]);
        t2=adunareDoua(t2.total,a,t2.total[0],a[0]);




        if(comparare(t2,t1))
        {
            for(int i=t1.total[0]; i>=1; i--)
            {
                fout<<t1.total[i];
            }
        }
        else
        {
            fout<<"0";
        }
        fout<<"\n";
    }



}
