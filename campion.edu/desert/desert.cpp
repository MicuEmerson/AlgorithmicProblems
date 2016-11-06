#include <fstream>
#include <iomanip>
using namespace std;
int n;
double k,p;
ifstream fi("desert.in");
ofstream fo("desert.out");

double f(int n)
{
	double d;
	if (n==1)
		return k*100.0/p;
	if (n==2)
		return 2*k*100.0/p;
	d=k*100.0/p/(2*n-3);
	return d+f(n-1);
}

int main()
{
	fi>>n>>k>>p;
	fo<<fixed<<setprecision(3)<<f(n);
	fi.close();
	fo.close();
	return 0;
}