#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("control1.in");
ofstream fout("control1.out");

int cifraDeControl(int n)
{
    int s;
    while(n>9)
    {

        s=0;
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        n=s;
    }
    return n;
}




int main()
{
    int a,b,c,dif,cate=0;

    fin>>a>>b>>c;
    dif=b-a;
    if(dif==0 && a!=c)
    {
        fout<<0;
    }
    else if(dif<10)
    {
        for(int i=a;i<=b;i++){
            if(cifraDeControl(i)==c){
                cate++;
            }

        }
        fout<<cate;
    }
    else
    {
        a=cifraDeControl(a);
        b=cifraDeControl(b);
        dif-=9-a;
        dif-=b;

        if(c>=a)
        {
            cate++;
        }

        if(c<=b)
        {
            cate++;
        }

        cate+=dif/9;
        fout<<cate;
    }


}
