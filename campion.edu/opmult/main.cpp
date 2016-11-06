#include <fstream>
using namespace std;
typedef struct multime{int E[256];} MULTIME;

MULTIME reuniune(MULTIME A, MULTIME B)
{
	MULTIME R;
	int i;
	for (i=1;i<=255;i++)
		R.E[i]=A.E[i]+B.E[i]-A.E[i]*B.E[i];
	return R;
}

MULTIME intersectie(MULTIME A, MULTIME B)
{
	MULTIME R;
	int i;
	for (i=1;i<=255;i++)
		R.E[i]=A.E[i]*B.E[i];
	return R;
}

MULTIME diferenta(MULTIME A, MULTIME B)
{
	MULTIME R;
	int i;
	R=A;
	for (i=1;i<=255;i++)
		if (B.E[i]==1)
			R.E[i]=0;
	return R;
}

int priority(char c)
{
	if (c=='.')
		return 0;
	if (c=='u' || c=='-')
		return 1;
	return 2;
}

int conversie(char L[], int p1, int p2)
{
	int rez,i;
	rez=0;
	for (i=p1;i<=p2;i++)
		rez=rez*10+(int)(L[i]-'0');
	return rez;
}

MULTIME transformare(int nr1, int nr2, char c1, char c2)
{
	MULTIME M;
	int i;
	for (i=1;i<=255;i++)
		M.E[i]=0;
	if (c1=='[' && c2==']')
		for (i=nr1;i<=nr2;i++)
			M.E[i]=1;
	if (c1=='[' && c2==')')
		for (i=nr1;i<nr2;i++)
			M.E[i]=1;
	if (c1=='(' && c2==']')
		for (i=nr1+1;i<=nr2;i++)
			M.E[i]=1;
	if (c1=='(' && c2==')')
		for (i=nr1+1;i<nr2;i++)
			M.E[i]=1;
	return M;
}

ifstream fi("opmult.in");
ofstream fo("opmult.out");
int T,test,y;
char L[2005];
char S[2005];
MULTIME R[1000];
int kS,kR;
int p,v,w;
int nr1, nr2;

int main()
{
	fi>>T;
	for (test=1;test<=T;test++)
	{
		fi>>y;
		fi>>L;
		// initializari penru stive
		kS=0;
		S[0]='.';
		kR=0;
		p=0;
		while (L[p]!='\0')
			if (L[p]=='(' || L[p]=='[')
			{
				// se cauta virgula
				v=p;
				while (L[v]!=',')
					v++;
				nr1=conversie(L,p+1,v-1);
				// se cauta paranteza de inchidere
				w=v;
				while (!(L[w]==')' || L[w]==']'))
					w++;
				nr2=conversie(L,v+1,w-1);
				R[++kR]=transformare(nr1,nr2,L[p],L[w]);
				p=w+1;
			}
			else
			{
				// tot ce se afla in varful lui S
				// si are prioritate >= L[p]
				// este extras si efectuat
				while (priority(S[kS])>=priority(L[p]))
				{
					if (S[kS]=='u')
					{
						R[kR-1]=reuniune(R[kR-1],R[kR]);
						kR--;
					}
					if (S[kS]=='n')
					{
						R[kR-1]=intersectie(R[kR-1],R[kR]);
						kR--;
					}
					if (S[kS]=='-')
					{
						R[kR-1]=diferenta(R[kR-1],R[kR]);
						kR--;
					}
					kS--;
				}
				S[++kS]=L[p++];
			}
		while (kS!=0)
		{
			if (S[kS]=='u')
			{
				R[kR-1]=reuniune(R[kR-1],R[kR]);
				kR--;
			}
			if (S[kS]=='n')
			{
				R[kR-1]=intersectie(R[kR-1],R[kR]);
				kR--;
			}
			if (S[kS]=='-')
			{
				R[kR-1]=diferenta(R[kR-1],R[kR]);
				kR--;
			}
			kS--;
		}
		if (R[1].E[y]==1)
			fo<<"DA\n";
		else
			fo<<"NU\n";
	}
	fi.close();
	fo.close();
	return 0;
}
