#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

long long n;
int tip,s,a[10][10],rez[25],dim;

void solve1()
{
    if(n==0)
        s=6;
    else
        while(n>0)
        {
            if(n%10==0) s+=6;
            if(n%10==1) s+=2;
            if(n%10==2) s+=5;
            if(n%10==3) s+=5;
            if(n%10==4) s+=4;
            if(n%10==5) s+=5;
            if(n%10==6) s+=6;
            if(n%10==7) s+=3;
            if(n%10==8) s+=7;
            if(n%10==9) s+=6;
            n/=10;
        }

    cout<<s;

}


int main()
{
    cin>>tip>>n;
    if(tip==1) solve1();
    else
    {

        a[0][1]=1,a[0][2]=1,a[0][3]=1,a[0][4]=1,a[0][5]=1,a[0][6]=1;  //0
        a[1][2]=1,a[1][3]=1;                                          //1
        a[2][1]=1,a[2][2]=1,a[2][4]=1,a[2][5]=1,a[2][7]=1;            //2
        a[3][1]=1,a[3][2]=1,a[3][2]=1,a[3][4]=1,a[3][7]=1;            //3
        a[4][2]=1,a[4][3]=1,a[4][6]=1,a[4][7]=1;                      //4
        a[5][1]=1,a[5][3]=1,a[5][4]=1,a[5][6]=1,a[5][7]=1;            //5
        a[6][1]=1,a[6][3]=1,a[6][4]=1,a[6][5]=1,a[6][6]=1,a[6][7]=1;  //6
        a[7][1]=1,a[7][2]=3,a[7][3]=1;                                //7
        a[8][1]=1,a[8][2]=1,a[8][3]=1,a[8][4]=1,a[8][5]=1,a[8][6]=1,a[8][7]=1; //8
        a[9][1]=1,a[9][2]=1,a[9][3]=1,a[9][4]=1,a[9][6]=1,a[9][7]=1;  //9


        if(n==0) cout<<1;
        else
            while(n>0)
            {

                int  cif=n%10;
                n/=10;
                dim++;
                for(int i=cif+1; i<=9; i++)
                {
                    bool ok=true;
                    for(int j=1; j<=7; j++)
                    {
                        if(a[cif][j]==1 && a[i][j]==0) ok=false;
                    }
                    if(ok) rez[dim]++;
                }
            }

        for(int i=1;i<=dim;i++) s+=rez[i];


        for(int i=dim; i>=2; i--)
        {
            int prod=rez[i];
            for(int j=i-1; j>=1; j--)
            {
                prod*=(rez[j]+1);
            }
            s+=prod;
        }
        cout<<s;

    }



}
