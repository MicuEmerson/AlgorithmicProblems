#include <iostream>

using namespace std;
int n,x,v[1000005],f[1000005],gasit=0;
unsigned long long s[1000005],r[1000005];

int main()
{



    cin>>n>>x;

    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for(int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+v[i];
    }
    for(int i=1; i<=n; i++)
    {
        r[i]=s[i]%x;
        f[r[i]]++;
    }

    for(int i=1; i<=n; i++)
    {
        cout<<s[i]<<" "<<r[i]<<endl;
    }

    if(f[0]>0)
    {
        cout<<"YES";
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(f[i]>1)
            {
                cout<<"YES";
                gasit=1;
                break;
            }
        }
        if(gasit==0)
        {
            cout<<"NO";
        }

    }
}
