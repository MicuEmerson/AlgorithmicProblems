#include <iostream>

using namespace std;

long long aib[10005],n;
long long  s[10005];


int main()
{

    int t,u,q,i,j,st,dr,k,val,x;
    cin>>t;

    for(i=1; i<=t; i++)
    {

        cin>>n;
        cin>>u;
        for(j=0;j<n;j++){
            s[j]=0;
        }
        for(j=1; j<=u; j++)
        {
            cin>>st>>dr>>val;
            aib[st]+=val;
            aib[dr+1]-=val;

        }
        for(j=0;j<=n;j++){
            s[j]+=s[j-1]+aib[j];
        }

        cin>>q;

        for(j=1; j<=q; j++)
        {
            cin>>x;
            cout<<s[x]<<endl;

        }

    }

}
