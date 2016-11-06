#include <iostream>
#include <string.h>
#include <fstream>
#include <ctype.h>
using namespace std;

ifstream fin("fraze.in");
ofstream fout("fraze.out");


//resetam vectorul sa aiba valori de 0 peste tot, daca nu l-am reseta ar avea valori random date de calculator
void resetare(int v[1000])
{

    int i;
    for(i='a'; i<='z'; i++)
    {
        v[i]=0;
    }
}

// functie ce ne returneaza 1 daca este pangramPerfect si 0 in caz contrar
int isPangramPerfect(int v[1000])
{

    int i;
    for(i='a'; i<='z'; i++)
    {
        if(v[i]==0)
        {
            return 0;
        }
    }
    return 1;

}
// functie ce ne returneaza 1 daca este pangram si 0 in caz contrar
int isPangram(int v[1000])
{

    int i;
    if(isPangramPerfect(v)==1)
    {
        for(i='a'; i<='z'; i++)
        {
            if(v[i]>1)
            {
                return 1;
            }
        }
    }
    return 0;
}

// functie simpla de sortare ( e ca si cum am sorta un vector doar ca aici folosim comenzi gen strcmp, strcpy, pentru siruri)
void sortare(char c[255][255], int n)
{

    int i,j;
    char aux[255];
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(strcmp(c[i],c[j])>0)
            {
                strcpy(aux,c[i]);
                strcpy(c[i],c[j]);
                strcpy(c[j],aux);
            }
        }
    }
}


int main()
{
    int v[1000];
    char c[255];
    char a[255][255];
    int  linii=0;
    int i, nrPangram=0, nrPangramPerfect=0;

    while(!fin.eof())
    {

        fin.get(c,255);
        fin.get();
        resetare(v);
        for(i=0; i<strlen(c); i++)
        {
            v[tolower(c[i])]++;
        }
        if(isPangramPerfect(v)==1)
        {
            if(isPangram(v)==1)
            {
                nrPangram++;
            }
            else
            {
                nrPangramPerfect++;
                nrPangram++;
            }
            linii++;
            strcpy(a[linii],c);
        }
    }
    sortare(a,linii);

    fout<<nrPangram<<" "<<nrPangramPerfect<<endl;
    for(i=1; i<=linii; i++)
    {
        fout<<a[i]<<endl;
    }

}



























