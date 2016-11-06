#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int k;
int a[158][3];
int main()
{
    fin>>k;
    for(int i=1; i<=158; i++)
    {
        fin>>a[i][1]>>a[i][2]>>a[i][3];
    }

    for(int i=1; i<=158; i++)
    {
        if(k%a[i][1]==0)
        {
            int x= a[i][1];
            int y= a[i][2];
            int z= a[i][3];
            while(a[i][1]!=k){
                a[i][1]+=x;
                a[i][2]+=y;
                a[i][3]+=z;
            }
            cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;

        }
    }







}
