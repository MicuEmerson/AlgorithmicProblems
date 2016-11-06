#include <fstream>
using namespace std;
ifstream fi("oneton.in");
ofstream fo("oneton.out");
int N,pas,v;

int f(int i)
{
	if (i%2==1)
		return (i+1)/2;
	else
		return 2*N+1-i/2;
}

int main()
{
	fi>>N;
	pas=0;
	v=2;
	do
	{
		pas++;
		v=f(v);
	}
	while (v!=2);
	fo<<pas;
	fi.close();
	fo.close();
	return 0;
}