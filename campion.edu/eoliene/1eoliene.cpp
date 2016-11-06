#include <stdio.h>
int n;
int d[1005],df[1005];
FILE *f,*g;


void citire()
{
  f=fopen("eoliene.in","r");
  fscanf(f,"%d",&n);
  int i,lg;
  for(i=1;i<=n;i++)
    fscanf(f,"%d",&d[i]);
  for(i=1;i<=n;i++)
{ fscanf(f,"%d",&lg);
  df[i]=d[i]+lg;d[i]=d[i]-lg; }
  fclose(f);
}

void sort( )
{
    int i, ok, x;
    do{
        ok=0;
        for(i=1;i<n;i++)
        if(df[i]>df[i+1])
        {
            x=df[i]; df[i]=df[i+1]; df[i+1]=x;
            x=d[i]; d[i]=d[i+1]; d[i+1]=x;
            ok=1;
        }
    }while(ok);
}

int main()
{ citire();
  sort();
  int nr=1,i,x;
  x=df[1];
  for(i=2;i<=n;i++)
  {
      if(x<d[i]){nr++; x=df[i];}
  }
  g=fopen("eoliene.out","w");
  fprintf(g,"%d\n",n-nr);
  fclose(g);
  return 0;
}

//O(nxn)



