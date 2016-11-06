//Emanuela Cerchez 100 puncte
#include <fstream>
#define NMAX 501

using namespace std;

struct Loc {int c, d, nr;};
Loc L[NMAX];
int n;
int D[NMAX];
int NrD;

ifstream fin("cursa1.in");
ofstream fout("cursa1.out");

void citire();
void sortare();
void depasiri();

int main()
{   int i;
    citire();
    sortare();
    for (i=1; i<n; i++) fout<<L[i].c<<' ';
    fout<<L[n].c<<'\n';
    depasiri();
    fout.close();
    return 0;
}

void citire()
{
int i;
fin>>n;
for (i=1; i<=n; i++)
    {
     fin>>L[i].c>>L[i].d;
     L[i].nr=i;
    }
 for (i=n; i>1; i--)
     L[i].d-=L[i-1].d;
}

void sortare()
{
//sortare prin selectia minimului
int poz, pozmin, i;
Loc aux;
for (poz=n; poz>1; poz--)
     {
      //determin minimul de la 1 la poz
      pozmin=1;
      for (i=2; i<=poz; i++)
          if (L[pozmin].d>L[i].d ||
			  L[pozmin].d==L[i].d && L[pozmin].c<L[i].c)
             pozmin=i;

      aux=L[pozmin]; L[pozmin]=L[poz]; L[poz]=aux;
     }
}

int cautloc(int i)
{int poz;
 for (poz=1; L[poz].nr!=i; poz++);
 return poz;
}

void depasiri()
{int i, j, poz;
for (i=2; i<=n; i++)
    {//depasirile din localitatea i
     poz=cautloc(i);//caut localitatea i in L
	 NrD=0;
     for (j=n; j>0; j--)
          if (i>L[j].nr && L[poz].d>L[j].d) //depasire
                {
                 NrD++;
                 D[NrD]=j;
                }
        if (NrD)
           {
           	fout<<i<<' '<<L[poz].c<<' '<<NrD;
            for (j=1; j<=NrD; j++) fout<<' '<<L[D[j]].c;
            fout<<'\n';}
    }
}

