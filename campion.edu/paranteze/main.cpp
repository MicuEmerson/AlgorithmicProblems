#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");




int main()
{
    int n,dim,i,x,v[100],k=0,j;
    stack <int> stiva;
    fin>>n;
    fin.get();

    for(i=1; i<=n; i++)
    {

        //resetare stiva
        while(!stiva.empty())
        {
            stiva.pop();
        }

        fin>>dim;

        for(j=1; j<=dim; j++)
        {
            fin>>x;

            if(stiva.empty())
            {
               stiva.push(x);
            }
            else if(stiva.top()==0 && x==1)
            {
                stiva.pop();
            }
            else if(stiva.top()==2 && x==3)
            {
                stiva.pop();
            }
            else if(stiva.top()==0 && x==3)
            {

                j++;
                while(j<=dim)
                {
                    fin>>x;
                    j++;
                }
            }
            else if(stiva.top()==2 && x==1)
            {
                j++;
                while(j<=dim)
                {
                    fin>>x;
                    j++;
                }
            }
            else{
                stiva.push(x);
            }
        }


        if(stiva.empty()){
            v[++k]=1;
        }
        else{
            v[++k]=0;
        }
    }

    for(i=1; i<=k; i++)
    {
        fout<<v[i]<<endl;
    }
}









