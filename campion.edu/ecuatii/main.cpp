#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("text.txt");
ofstream fout("palc.out");

int pozEgal(char c[255])
{

    for(int j=0; j<strlen(c); j++)
    {
        if(c[j]=='=')
        {
            return j;
        }
    }


}

int numar(int v[1000], int n)
{

    int i;
    int nr=0;
    for(i=1; i<=n; i++)
    {
        nr=nr*10+v[i];
    }
    return nr;



}



int main()
{
    int n,i,j,pEgal, sumaStangaX, sumaStangaNormala, sumaDreaptaX, sumaDreaptaNormala;
    char c[255],exp1[255],exp2[255],aux[255],aux2[255];
    int v[1000],k;
    int dimV;
    fin>>n;
    for(i=1;i<=n;i++){
        aux[i]='+';
        aux2[i]='+';
    }
    fin.get();
    for(i=1; i<=n; i++)
    {
        fin.get(c,255);
        fin.get();
        pEgal=pozEgal(c);

        //copiere exp1
        j=0;
        while(c[j]!='=')
        {
            exp1[j]=c[j];
            j++;
        }
        exp1[j]=NULL;

        //copiere exp2
        strcpy(exp2,c+pEgal+1);


        sumaStangaX=0;
        sumaStangaNormala=0;
        sumaDreaptaX=0;
        sumaDreaptaNormala=0;


        //adaugare semn

        cout<<aux<<endl;
        if(exp1[0]!='+' && exp1[0]!='-')
        {
            strcat(aux,exp1);
            strcpy(exp1,aux);
        }

        if(exp2[0]!='+' && exp2[0]!='-')
        {
            strcat(aux2,exp2);
            strcpy(exp2,aux2);
        }



      //  cout<<exp1<<endl;
        //exp1
        for(j=0; j<strlen(exp1); j++)
        {

            if(isdigit(exp1[j]))
            {
                dimV=0;
                k=j;
                //cream numerele
                while(isdigit(exp1[j]) && j<strlen(exp1))
                {
                    v[++dimV]=(int)exp1[j]-48;
                    j++;
                }
                // adaum X-urile
                if(exp1[j]=='x')
                {
                    if(exp1[k-1]=='+')
                    {
                        sumaStangaX+=numar(v,dimV);
                    }
                    else
                    {
                        sumaStangaX-=numar(v,dimV);
                    }
                }
                //adaugam normalele
                else
                {
                    if(exp1[k-1]=='+')
                    {
                        sumaStangaNormala+=numar(v,dimV);
                    }
                    else
                    {
                        sumaStangaNormala-=numar(v,dimV);
                    }
                }
            }

        }
      //  cout<<sumaStangaX<<"x "<<sumaStangaNormala<<endl;
       // cout<<endl<<endl<<endl;

       // cout<<exp2<<endl;
        //exp2
        for(j=0; j<strlen(exp2); j++)
        {

            if(isdigit(exp2[j]))
            {

                dimV=0;
                k=j;
                //cream numerele
                while(isdigit(exp2[j]) && j<strlen(exp2))
                {
                    v[++dimV]=(int)exp2[j]-48;
                    j++;
                }

                //adaugam X-urile
                if(exp2[j]=='x')
                {
                    if(exp2[k-1]=='+')
                    {
                        sumaDreaptaX+=numar(v,dimV);
                    }
                    else
                    {
                        sumaDreaptaX-=numar(v,dimV);
                    }
                }
                //adaugam normalele
                else
                {
                    if(exp2[k-1]=='+')
                    {
                        sumaDreaptaNormala+=numar(v,dimV);
                    }
                    else
                    {
                        sumaDreaptaNormala-=numar(v,dimV);
                    }
                }
            }

        }
      //  cout<<sumaDreaptaX<<"x "<<sumaDreaptaNormala<<endl;
       // cout<<endl<<endl<<endl;


        sumaDreaptaX-=sumaStangaX;
        sumaStangaNormala-=sumaDreaptaNormala;
        //cout<<sumaStangaNormala<<" = "<<sumaDreaptaX<<endl;

        if(sumaStangaNormala==0 && sumaDreaptaX==0)
        {
            cout<<"infinit"<<endl;
        }
        else if(sumaStangaNormala==0 || sumaDreaptaX==0)
        {
            cout<<"imposibil"<<endl;
        }
        else
        {
            cout<<(float)sumaStangaNormala/(float)sumaDreaptaX<<endl;
        }
    }








}

















