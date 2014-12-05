#include<math.h>
double around(double n,double m)
{
    double f,i,f1,i1;
    int i2;
    f = modf(n,&i);
    f*=pow(10.0,m);
    f1=modf(f,&i1);
    if(f1>0.500000000001) i1++;
    else if((int)i1%2!=0&&f1<0.50000000001) i1++;
    f=i1*pow(10.0,-1.0*m);
    n=i+f;
    return n;
}
