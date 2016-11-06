#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("powerpuff.in");
ofstream fout("powerpuff.out");

int x1,x2,x3,n,v[100];

void reset(int f[10]){

   for(int i=0;i<=9;i++){
    f[i]=0;
   }

}
int comparare(int x, int y)
{
    int s=0;
    int fx[10],fy[10];
    reset(fx);
    reset(fy);
    while(x>0)
    {
        fx[x%10]++;
        x/=10;
    }
    while(y>0)
    {
        fy[y%10]++;
        y/=10;
    }
    for(int i=0;i<=9;i++){
        if(fx[i]==0 && fy[i]>0) s-=(i*fy[i]);
        else if(fx[i]>0 && fy[i]==0) s+=(i*fx[i]);
    }
    return s;
}


int main()
{

    fin>>x1>>x2>>x3>>n;
   // cout<<x1<<" "<<x2<<" "<<x3<<" "<<n<<endl;
    for(int i=1; i<=n; i++) fin>>v[i];
   // cout<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
    for(int i=1; i<=n; i++) x1+=comparare(x1,v[i]);

    for(int i=1; i<=n; i++) x2+=comparare(x2,v[i]);

    for(int i=1; i<=n; i++) x3+=comparare(x3,v[i]);

    fout<<x1<<endl<<x2<<endl<<x3;

}





















