#include <fstream>
#include <cmath>
#include <iomanip>
#define PI 3.141592
using namespace std;
typedef struct punct {double x,y;} PUNCT;
ifstream fi("tarc.in");
ofstream fo("tarc.out");
int n,i;
PUNCT P[100001];
PUNCT Q[100001];
PUNCT S[4],SOL[4];
double ust,udr,um;
double dif,diferenta;
double xmin,xmax,ymin,ymax;
int T,t;

double f(double u)
{
	int i;
	for (i=1;i<=n;i++)
	{
		Q[i].x=cos(u)*P[i].x-sin(u)*P[i].y;
		Q[i].y=sin(u)*P[i].x+cos(u)*P[i].y;
	}
	xmin=ymin=100000000.0;
	xmax=ymax=-100000000.0;
	for (i=1;i<=n;i++)
	{
		if (Q[i].x<xmin)
			xmin=Q[i].x;
		if (Q[i].x>xmax)
			xmax=Q[i].x;
		if (Q[i].y<ymin)
			ymin=Q[i].y;
		if (Q[i].y>ymax)
			ymax=Q[i].y;
	}

	return (ymax-ymin)-(xmax-xmin);
}

int main()
{
	fi>>T;
	for (t=1;t<=T;t++)
	{
		fi>>n;
		for (i=1;i<=n;i++)
			fi>>P[i].x>>P[i].y;
		ust=0.0;
		udr=PI/2;
		while (udr-ust>0.0000000001)
		{
			um=(ust+udr)/2.0;
			if (f(um)*f(ust)<0.0)
				udr=um;
			else
				ust=um;
		}
		S[0].x=xmin;
		S[0].y=ymin;
		S[1].x=xmin;
		S[1].y=ymax;
		S[2].x=xmax;
		S[2].y=ymin;
		S[3].x=xmax;
		S[3].y=ymax;
		for (i=0;i<=3;i++)
		{
			SOL[i].x=cos(-ust)*S[i].x-sin(-ust)*S[i].y;
			SOL[i].y=sin(-ust)*S[i].x+cos(-ust)*S[i].y;
		}
		for (i=0;i<=3;i++)
			fo<<fixed<<setprecision(7)<<SOL[i].x<<" "<<SOL[i].y<<"\n";
	}
	fi.close();
	fo.close();
	return 0;
}
