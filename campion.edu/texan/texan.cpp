#include <fstream>
#include <cmath>
#define PI 3.141592
using namespace std;
typedef struct punct {double x,y;} PUNCT;

ifstream fi("texan.in");
ofstream fo("texan.out");
int n,i,j;
PUNCT M[510];
PUNCT P[510];
PUNCT A,B,C;

PUNCT rotatie(PUNCT P, PUNCT A, double u)
{
	PUNCT R;
	P.x-=A.x;
	P.y-=A.y;
	R.x=cos(u)*P.x-sin(u)*P.y;
	R.y=sin(u)*P.x+cos(u)*P.y;
	R.x+=A.x;
	R.y+=A.y;
	return R;
}

int diferit(PUNCT A, PUNCT B)
{
	if ((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)<0.000001)
		return 0;
	return 1;
}

int intersectie(PUNCT A, PUNCT B, PUNCT C, PUNCT D, PUNCT E)
{
	double a,b,c;
	double d,e,f;
	int separa1,separa2;
	a=B.y-A.y;
	b=A.x-B.x;
	c=B.x*A.y-B.y*A.x;
	if ((a*C.x+b*C.y+c)*(a*D.x+b*D.y+c)<0.0)
		separa1=1;
	else
		separa1=0;
	d=D.y-C.y;
	e=C.x-D.x;
	f=D.x*C.y-D.y*C.x;
	if ((d*A.x+e*A.y+f)*(d*B.x+e*B.y+f)<0.0)
		separa2=1;
	else
		separa2=0;
	if (separa1==0 || separa2==0)
		return 0;
	E.y=(a*f-c*d)/(b*d-a*e);
	E.x=(-c-b*E.y)/a;
	return 1;
}

int main()
{
	fi>>n;
	for (i=1;i<=n;i++)
		fi>>M[i].x>>M[i].y;
	M[n+1]=M[1];
	A.x=(M[1].x+M[2].x)*0.5;
	A.y=(M[1].y+M[2].y)*0.5;
	// se obtin punctele P[i], rotind M[i] in jurul lui A cu 60 de grade
	for (i=1;i<=n+1;i++)
		P[i]=rotatie(M[i],A,PI/3.0);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (intersectie(M[i],M[i+1],P[j],P[j+1],B) && diferit(A,B))
				break;
	C=rotatie(B,A,-PI/3.0);
	fo<<A.x<<" "<<A.y<<"\n";
	fo<<B.x<<" "<<B.y<<"\n";
	fo<<C.x<<" "<<C.y<<"\n";
	fi.close();
	fo.close();
	return 0;
}
