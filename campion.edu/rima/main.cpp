#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
ifstream fin("rima.in");
ofstream fout("rima.out");

char s[100];
char c[4][100];


int isVocala(char c)
{
    char vocale[10];
    strcpy(vocale,"aeiouAEIOU");
    if(strchr(vocale,c)) return 1;
    return 0;
}

void prelucrare(char s[100], int care)
{
    int poz;
    for(int i=strlen(s)-1; i>=0; i--)
    {
        if(isVocala(s[i])==1 || s[i]==' ')
        {
            poz=i;
            break;
        }
    }
    if(s[poz]==' ')
    {
        poz++;
    }
    int k=-1;
    for(int i=poz; i<strlen(s); i++)
    {
        c[care][++k]=s[i];

    }

    if(care==4)
    {

        if(strcmp(c[1],c[2])==0 && strcmp(c[1],c[3])==0 && strcmp(c[1],c[4])==0)
        {
            fout<<"perfecta"<<"\n";
        }
        else if(strcmp(c[1],c[3])==0 && strcmp(c[2],c[4])==0)
        {
            fout<<"incrucisata"<<"\n";
        }
        else if(strcmp(c[1],c[4])==0 && strcmp(c[2],c[3])==0)
        {
            fout<<"imbricata"<<"\n";
        }
        else if(strcmp(c[1],c[2])==0 && strcmp(c[3],c[4])==0)
        {
            fout<<"uniforma"<<"\n";
        }
        else
        {
            fout<<"alba"<<"\n";
        }
    }

}


int main()
{
    int n;
    fin>>n;
    fin.get();

    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=4; j++)
        {

            fin.get(s,100);
            fin.get();
            prelucrare(s,j);

        }
    }
}

























