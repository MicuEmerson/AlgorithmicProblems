#include <iostream>
#include <stack>
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("text.txt");
ofstream fout("paranteze1.out");



/*
int main()
{
    int n,x;
    char c[255];
    stack <int> stiva;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>c;
        if(strlen(c)==3){
            if(c[0]=='t'){
                cout<<stiva.top()<<endl;
            }
            else{
                stiva.pop();
            }
        }
        else{
            fin>>x;
            stiva.push(x);
        }
        fin.get();
    }
}
*/
/*
int main()
{

    int n;
    fin>>n;
    char c[255];
    int i,j;
    for(i=1; i<=n; i++)
    {

        fin>>c;
        fin.get();
        int x=0,y=0,gasit=0;
        for(j=0; j<strlen(c); j++)
        {
            if(c[j]=='(')
            {
                x++;
            }
            else
            {
                y++;
            }
            if(x<y)
            {
                cout<<"0"<<endl;
                gasit=1;
            }

        }
        if(gasit==0)
        {
            if(x<y || x!=y)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<"1"<<endl;
            }
        }
    }

}
*/


int main()
{

    int n,i,j;
    int p11=0,p12=0,p21=0,p22=0;
    char c[255];
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>c;
        fin.get();
        p11=0;
        p12=0;
        p21=0;
        p22=0;
        int gasit=0;
        for(j=0; j<strlen(c); j++)
        {

            if(c[j]=='(')
            {
               p11++;
            }
            if(c[j]==')'){
                p12++;
            }
            if(c[j]=='[')
            {
               p21++;
            }
            if(c[j]==']'){
                p22++;
            }


            if(p12>p11){
                cout<<"0"<<endl;
                j=strlen(c);
                gasit=1;
            }
            if(p22>p21){
                cout<<"0"<<endl;
                j=strlen(c);
                gasit=1;
            }
        }

        if(gasit==0){
            if(p11!=p12 || p21!=p22){
                cout<<"0"<<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }


    }

}




















