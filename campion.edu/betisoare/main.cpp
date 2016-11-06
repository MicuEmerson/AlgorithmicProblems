/*
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <stack>
using namespace std;

ifstream fin("betisoare.in");
ofstream fout("betisoare.out");

int calcul(int a, int b, char c)
{

    if(c=='+')
    {
        return a+b;
    }
    return a*b;

}

int prioritare(char c)
{

    if(c=='.')
    {
        return 1;
    }
    if(c=='+')
    {
        return 2;
    }
    return 3;


}


int main()
{
    int n,i,nrFraze=0,j,nr;
    char c[1000000],k;
    long long v1,v2;
    stack <long long> numere;
    stack <char> op;
    fin>>n;
    fin.get();
    for(i=1; i<=n; i++)
    {
        fin.get(c,1000000);
        fin.get();
        if(strlen(c)==1)
        {
            fout<<"1";
        }
        else
        {

            //resetam stivele
            while(!op.empty())
            {
                op.pop();
            }
            while(!numere.empty())
            {
                numere.pop();
            }
            op.push('.');


            for(j=0; j<strlen(c); j++)
            {

                nr=0;
                //creare numar
                while(c[j]=='I' && j<strlen(c))
                {
                    nr++;
                    j++;
                }
                numere.push(nr);

                //operatii prioritare si adaugare operatii
                while(prioritare(op.top())>=prioritare(c[j])&& j<strlen(c))
                {
                    k=op.top();
                    op.pop();
                    v1=numere.top();
                    numere.pop();
                    v2=numere.top();
                    numere.pop();
                    numere.push(calcul(v1,v2,k));
                }
                if(j<strlen(c))
                {
                    op.push(c[j]);
                }

            }

            //partea finala
            while((k=op.top())!='.')
            {
                op.pop();
                v1=numere.top();
                numere.pop();
                v2=numere.top();
                numere.pop();
                numere.push(calcul(v1,v2,k));
            }
            fout<<numere.top()<<endl;
        }
    }

}
*/



#include <stack>
#include <stdio.h>
using namespace std;
int n;
stack <char> S;
stack <long long> R;
FILE *fi,*fo;
char L[10];
int i;
long long v,a,b,rez;
char c;
int main()
{
    fi = fopen("betisoare.in","r");
    fo = fopen("betisoare.out","w");
    fscanf (fi,"%d",&n);
    fgets(L,10,fi);
    for(i = 1;i<=n;i++)
    {
        v=0;
        while (!R.empty())
            R.pop();
        while (!S.empty())
            S.pop();
        while (1)
        {
            fscanf(fi,"%c",&c);
            if (c=='I')
                v++;
            else
                if (c=='+')
                {
                    R.push(v);
                    v=0;
                    while (!S.empty())
                    {
                        c=S.top();
                        S.pop();
                        if (c=='+')
                        {
                            a=R.top();
                            R.pop();
                            b=R.top();
                            R.pop();
                            rez=a+b;
                            R.push(rez);
                        }
                        else
                        {
                            a=R.top();
                            R.pop();
                            b=R.top();
                            R.pop();
                            rez=a*b;
                            R.push(rez);
                        }
                    }
                    S.push('+');
                }
                else
                    if (c=='*')
                    {
                        R.push(v);
                        v=0;
                        while (!S.empty() && S.top()=='*')
                        {
                            S.pop();
                            a=R.top();
                            R.pop();
                            b=R.top();
                            R.pop();
                            rez=a*b;
                            R.push(rez);
                        }
                        S.push('*');
                    }
                    else
                    {
                        R.push(v);
                        v=0;
                        while (!S.empty())
                        {
                            c=S.top();
                            S.pop();
                            if (c=='+')
                            {
                                a=R.top();
                                R.pop();
                                b=R.top();
                                R.pop();
                                rez=a+b;
                                R.push(rez);
                            }
                            else
                            {
                                a=R.top();
                                R.pop();
                                b=R.top();
                                R.pop();
                                rez=a*b;
                                R.push(rez);
                            }
                        }
                        break;
                    }
        }
        fprintf(fo,"%lld\n",R.top());
    }
    fclose(fi);
    fclose(fo);
    return 0;
}

