#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct
{
    int fete;
    int baieti;

} vvv;

int n,m,f,b,x,y,perechi=-999999;
int miny;
vvv v[1000005];

int main()
{
    freopen("bal.in","r",stdin);
	freopen("bal.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&y);
        v[x].fete++;
        v[y+1].fete--;
    }

    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&x,&y);
        v[x].baieti++;
        v[y+1].baieti--;
    }

    for(int i=1; i<=1000000; i++)
    {
        f+=v[i].fete;
        b+=v[i].baieti;
         //cout<<i<<") : "<<f<<b<<endl;
         miny=min(f,b);
         perechi=max(miny,perechi);
    }

    printf("%d",perechi);

	fclose(stdin); fclose(stdout);
	return 0;
}
