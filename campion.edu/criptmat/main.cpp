#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin("criptmat.in");         // cin
ofstream fout("criptmat.out");       // cout

void functie(char s[255][255], char sir[255], int n)
{

    int i,j,m,k=0;

    m=strlen(sir)/n;  // numarul linilor reprezentat prin m
    i=1;
    while(i<=m)   // cu while-ul acesta parcurgem toate linile
    {
        if(i%2!=0)   // verificam daca ii para/impara linia ( daca e impara punem elem de la coloana 1++, altfel de la coloana n--)
        {
            j=1;    //col 1
            while(j<=n)  // mergem pana la ultima coloana
            {
                s[i][j]=sir[k];
                k++;
                j++;
            }
        }
        else     // in cazul in care este impara parcurgem de la coloana n -> 1
        {
            j=n;
            while(j>0)   // mergem pana la prima col;
            {
                s[i][j]=sir[k];
                k++;
                j--;
            }
        }
        i++;   // crestem numarul linilor
    }

    for(j=1;j<=n;j++){    //parcurgem pe coloana matricea si ne rezulta cuvantul necriptat
        for(i=1;i<=m;i++){
                cout<<s[i][j];
            fout<<s[i][j];   // punem cuvantul necriptat in fisier
        }
    }

}

int main()
{
    char s[255][255];
    int n;
    char sir[255];
    fin>>n;  // citim de pe prima linie din fisier;
    fin.get();     // un fel de enter in fisier
    fin.get(sir,255);  //  citim sirul de pe linia a doua
    functie(s,sir,n);




}
