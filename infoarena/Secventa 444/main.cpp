#include <bits/stdc++.h>
using namespace std;

ifstream fin("iesire.in");
ofstream fout("iesire.out");

void cifmaxmin(int n, int &max, int &min)
{

    if(n<=9)
    {
        max=n;
        min=n;
    }
    else
    {

        cifmaxmin(n/10,max,min);
        if(max>n%10) max=n%10;
        if(min<n%10) min=n%10;
    }

}



int main()
{

    int min,max;
    cifmaxmin(12446,max,min);
    cout<<max<<" "<<min<<endl;



}
