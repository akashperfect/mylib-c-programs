#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef enum{true=0,false=1} boolean;
boolean* sieve(int n)
{
   boolean prime[n+1];
   Arrays.fill(prime,true);
   int i;
   for(i=0;i<n;i++)
   prime[i] = 0;
   prime[0]=1;
   prime[1]=1;
   int m=sqrt(n),k;

   for ( i=2; i<=m; i++)
      if (prime[i]==0)
         for ( k=2*i; k<=n; k+=i)
            prime[k]=1;

   return prime;
}
int main()
{
    boolean *p;
    p = sieve(100);
    int i;
     for ( i=2; i<=100; i++)
      //if (p[i]==0)
      printf("%d\n",p[i]);
}
