#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

ifstream fin("agenda.in");
ofstream fout("agenda.out");

typedef struct
{

    int z1,l1,h1,m1;
    int z2,l2,h2,m2;


} ttt;

ttt t[1000];
int dimT;
string s,a,b,luna,h,m;

int ceLuna(string x);
int transformareInNr(string x);
int transformareInLuna(string x);
void transformareOreSauMinute(string x, int primuSauAlDoilea);
int zileLuna(int luna);
long long durataElse(ttt x);
void durataMax();
void afisare();
int cmp(ttt a, ttt b);
void nrMaxSuprapuneri();
long long  luniDiferite(ttt a, ttt b);
int zileDiferite(ttt a, ttt b);
int oreDiferite(ttt a, ttt b);
int minDiferite(ttt a, ttt b);
void nrMaxDistanta();

int main()
{
    int nr,i,j;
    fin>>nr;
    fin.get();
    while(!fin.eof())
    {
        getline(fin,s);
        a=s.substr(0,s.find_first_of('-',0));
        b=s.substr(s.find_first_of('-',0)+1 , s.find_last_of('.',s.length()) - s.find_first_of('-',0)+2);
        dimT++;
        t[dimT].z1=transformareInNr(a);
        t[dimT].l1=transformareInLuna(a);
        transformareOreSauMinute(a,1);
        t[dimT].z2=transformareInNr(b);
        t[dimT].l2=transformareInLuna(b);
        transformareOreSauMinute(b,-1);
    }
    sort(t+1,t+dimT+1,cmp);
    if(nr==1)
    {
        durataMax();
    }
    else if(nr==2)
    {
        nrMaxSuprapuneri();
    }
    else
    {
        nrMaxDistanta();
    }
    fin.close();
    fout.close();
    return 0;
}

int ceLuna(string x)
{
    if(x=="Ianurie"||x=="ianuarie")
    {
        return 1;
    }
    if(x=="Februarie"||x=="februarie")
    {
        return 2;
    }
    if(x=="Martie"||x=="martie")
    {
        return 3;
    }
    if(x=="Aprilie"||x=="aprilie")
    {
        return 4;
    }
    if(x=="Mai"||x=="mai")
    {
        return 5;
    }
    if(x=="Iunie"||x=="iunie")
    {
        return 6;
    }
    if(x=="Iulie"||x=="iulie")
    {
        return 7;
    }
    if(x=="August"||x=="august")
    {
        return 8;
    }
    if(x=="Septembrie"||x=="septembrie")
    {
        return 9;
    }
    if(x=="Octombrie"||x=="octombrie")
    {
        return 10;
    }
    if(x=="Noiembrie"||x=="noiembrie")
    {
        return 11;
    }
    if(x=="Decembrie"||x=="decembrie")
    {
        return 12;
    }
}

int transformareInNr(string x)
{

    int nr=0;

    if(isdigit(x[0]))
    {
        nr=(int)x[0]-48;
    }
    if(isdigit(x[1]))
    {
        nr=nr*10+(int)x[1]-48;
    }
    return nr;
}

int transformareInLuna(string x)
{
    int  pStart=0,pStop,dim;
    while(!isalpha(x[pStart]))
    {
        pStart++;
    }
    pStop=pStart;
    while(isalpha(x[pStop]))
    {
        pStop++;
    }
    luna=x.substr(pStart,pStop-pStart);
    return ceLuna(luna);
}

void transformareOreSauMinute(string x, int primuSauAlDoilea)
{
    int pozPunct,pozStart,cat;
    int i,nrH=0,nrM=0;
    pozPunct=x.find_last_of('.',x.length());
    pozStart=x.find_first_of("1234567890",4);
    cat=pozPunct-pozStart;
    h=x.substr(pozStart,cat);
    cat=x.size()-pozPunct;
    m=x.substr(pozPunct+1,cat);
    for(i=0; i<h.length(); i++)
    {
        if(isdigit(h[i]))
        {
            nrH=nrH*10+(int)h[i]-48;
        }
    }
    for(i=0; i<m.length(); i++)
    {
        if(isdigit(m[i]))
        {
            nrM=nrM*10+(int)m[i]-48;
        }
    }
    if(primuSauAlDoilea==1)
    {
        t[dimT].h1=nrH;
        t[dimT].m1=nrM;
    }
    else
    {
        t[dimT].h2=nrH;
        t[dimT].m2=nrM;
    }
}

int zileLuna(int luna)
{

    if(luna==1 || luna==3 || luna==5 || luna==7 || luna==8 || luna==10 || luna==12)
    {
        return 31;
    }
    else if(luna==2)
    {
        return 28;
    }
    else
    {
        return 30;
    }

}

long long durataElse(ttt x)
{
    int valLuni[12]= {0,1,2,3,4,5,6,7,8,9,10,11};
    valLuni[0]=31 , valLuni[1]=28 , valLuni[2]=31 , valLuni[3]=30 , valLuni[4]=31 , valLuni[5]=30;
    valLuni[6]=31 , valLuni[7]=31 , valLuni[8]=30 , valLuni[9]=31 , valLuni[10]=30 , valLuni[11]=31;
    int nrLuniDif;
    long long mFinal=0,zFinala=0;
    nrLuniDif=x.l2-x.l1;
    if(nrLuniDif>1)
    {
        nrLuniDif--;
        for(int i=x.l1; i<x.l1+nrLuniDif; i++)
        {
            zFinala+=valLuni[i];
        }
    }
    mFinal+=zFinala*24*60;
    mFinal+=60-x.m1;
    mFinal+=(23-x.h1)*60;
    if(valLuni[x.l1-1]>x.z1+1)
    {
        mFinal+=(valLuni[x.l1-1]-x.z1)*24*60;
    }
    mFinal+=x.m2;
    mFinal+=x.h2*60;
    mFinal+=x.z2*24*60;
    mFinal-=1440;
    return mFinal;

}

void durataMax()
{
    int i,j;
    int nr,nrMax=-99999;
    for(i=1; i<=dimT; i++)
    {
        int nr1=0,nr2=0;
        if(t[i].l1==t[i].l2)
        {
            nr1= (24*t[i].z1*60) + 60*t[i].h1 + t[i].m1;
            nr2= (24*t[i].z2*60) + 60*t[i].h2 + t[i].m2;
            nr2=nr2-nr1;
        }
        else
        {
            nr2=durataElse(t[i]);
        }
        nrMax=max(nrMax,nr2);
    }

    fout<<nrMax/(24*60);
    nrMax=nrMax%(24*60);
    fout<<" "<<nrMax/60<<" "<<nrMax%60;
}

void afisare()
{
    for(int i=1; i<=dimT; i++)
    {
        cout<<t[i].z1<<" "<<t[i].l1<<" "<<t[i].h1<<" "<<t[i].m1<<" / "<<t[i].z2<<" "<<t[i].l2<<" "<<t[i].h2<<" "<<t[i].m2<<endl;
    }
    cout<<endl;

}

int cmp(ttt a, ttt b)
{
    if(a.l2<b.l2)
    {
        return 1;
    }
    else if(a.l2==b.l2)
    {
        if(a.z2<b.z2)
        {
            return 1;
        }
        else if(a.z2==b.z2)
        {
            if(a.h2<b.h2)
            {
                return 1;
            }
            else if(a.h2==b.h2)
            {
                if(a.m2<b.m2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}

void nrMaxSuprapuneri()
{
    int nr,nrMax=-99999;
    int i,j;
    for(i=1; i<=dimT; i++)
    {
        nr=1;
        j=i+1;
        while(t[i].l2>=t[j].l1 && j<=dimT)
        {
            if(t[i].l2>t[j].l1)
            {
                nr++;
            }
            else if(t[i].l2==t[j].l1)
            {
                if(t[i].z2>t[j].z1)
                {
                    nr++;
                }
                else if(t[i].z2==t[j].z1)
                {
                    if(t[i].h2>t[j].h1)
                    {
                        nr++;
                    }
                    else if(t[i].h2==t[j].h1)
                    {
                        if(t[i].m2>t[j].m1)
                        {
                            nr++;
                        }
                    }
                }
            }
            j++;
        }
        nrMax=max(nrMax,nr);
    }
    if(nrMax==1)
    {
        fout<<"0";
    }
    else
    {
        fout<<nrMax;
    }
}

long long  luniDiferite(ttt a, ttt b)
{
    int valLuni[12]= {0,1,2,3,4,5,6,7,8,9,10,11};
    valLuni[0]=31 , valLuni[1]=28 , valLuni[2]=31 , valLuni[3]=30 , valLuni[4]=31 , valLuni[5]=30;
    valLuni[6]=31 , valLuni[7]=31 , valLuni[8]=30 , valLuni[9]=31 , valLuni[10]=30 , valLuni[11]=31;
    int nrLuniDif;
    long long mFinal=0,zFinala=0;
    nrLuniDif=b.l1-a.l2;
    if(nrLuniDif>1)
    {
        nrLuniDif--;
        for(int i=a.l2; i<a.l2+nrLuniDif; i++)
        {
            zFinala+=valLuni[i];
        }
    }
    mFinal+=zFinala*24*60;
    mFinal+=60-a.m2;
    mFinal+=(23-a.h2)*60;
    if(valLuni[a.l2-1]>a.z2+1)
    {
        mFinal+=(valLuni[a.l2-1]-a.z2)*24*60;
    }
    mFinal+=b.m1;
    mFinal+=b.h1*60;
    mFinal+=b.z1*24*60;
    mFinal-=1440;
    return mFinal;
}

int zileDiferite(ttt a, ttt b)
{
    int minA=0,minB=0;
    minB=(b.z1*24*60)+(b.h1*60)+b.m1;
    minA=(a.z2*24*60)+(a.h2*60)+a.m2;
    return minB-minA;
}

int oreDiferite(ttt a, ttt b)
{
    int minA=0,minB=0;
    minB=b.h1*60+b.m1;
    minA=a.h2*60+a.m2;
    return minB-minA;
}

int minDiferite(ttt a, ttt b)
{
    return b.m1-a.m2;
}

void nrMaxDistanta()
{
    long long dist,distMax=-99999;
    int i,j;
    for(i=1; i<dimT; i++)
    {
        j=i+1;
        if(t[i].l2<t[j].l1)
        {
            dist=luniDiferite(t[i],t[j]);
        }
        else if(t[i].l2==t[j].l1)
        {

            if(t[i].z2<t[j].z1)
            {

                dist=zileDiferite(t[i],t[j]);

            }
            else if(t[i].z2==t[j].z1)
            {
                if(t[i].h2<t[j].h1)
                {
                    dist=oreDiferite(t[i],t[j]);
                }
                else if(t[i].h2==t[j].h1)
                {

                    if(t[i].m2<t[j].m1)
                    {
                        dist=minDiferite(t[i],t[j]);
                    }
                }
            }
        }
        distMax=max(distMax,dist);
    }

    fout<<distMax/(24*60);
    distMax=distMax%(24*60);
    fout<<" "<<distMax/60<<" "<<distMax%60;

}
