/*
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

ifstream fin("palc.in");
ofstream fout("palc.out");

int isPal(char c[255])
{

    char aux[255];
    strcpy(aux,c);
    strrev(c);
    if(strcmp(aux,c)==0)
    {
        return 1;
    }
    return 0;

}

void permutareLaStanga(char c[255])
{

    int aux=c[0];
    strcpy(c,c+1);
    c[strlen(c)]=aux;
    c[strlen(c)]=NULL;

}

void permutareLaDrepta(char c[255])
{


    char aux[255];
    strcpy(aux,c+strlen(c)-1);
    c[strlen(c)-1]=NULL;
    strcat(aux,c);
    c[0]=NULL;
    strcpy(c,aux);

}


int main()
{
    char c[255],cc[255];
    fin>>c;
    strcpy(cc,c);
    int i,dim,contor1=0,nrMin=99999;
    dim=strlen(c);
    i=1;
    //stanga
    while(i<=dim && isPal(c)==0)
    {
        contor1++;
        permutareLaStanga(c);
        //cout<<c<<" ";
        //cout<<isPal(c)<<endl;
        i++;

    }

    if(contor1<nrMin && isPal(c)==1)
    {
        nrMin=contor1;
    }

    //dreapta
    i=1;
    contor1=0;
    while(i<=dim && isPal(cc)==0)
    {
        contor1++;
        permutareLaDrepta(cc);
        //cout<<cc<<" ";
       // cout<<isPal(cc)<<endl;
        i++;
    }

    if(contor1<nrMin && isPal(cc)==1)
    {
        nrMin=contor1;
    }
    if(nrMin=99999){
        fout<<"-1";
    }
    else{
        fout<<nrMin;
    }

}
*/

#include<stdio.h>
#include<string.h>

#define MIN(a,b) (a)<(b) ? (a):(b)
char siri[300];
char sirn[1000];

int pal(char *s,int n)
{
   int i = 0;
   while(i<=n/2 && s[i] == s[n-i-1])
    i++;

   if(i>n/2) return 1;
   else return 0;
}
int n,r;
int main()
{
	freopen("palc.in","r",stdin);
	freopen("palc.out","w",stdout);

	while(scanf("%c",&siri[n]) != -1 && siri[n] != '\n'&&siri[n]!='\r')
		n++;
	siri[n]='\0';
	n = strlen(siri);
	strcpy(sirn,siri);
	strcpy(sirn+n,siri);

	r=-1;
	for(int i=0;i<n;i++)
	{
		if(pal(sirn+i,n))
			r= MIN(i,n-i);
	}
	printf("%d",r);
	fclose(stdin); fclose(stdout);
	return 0;
}







