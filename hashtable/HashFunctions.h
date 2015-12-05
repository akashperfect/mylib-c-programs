#ifndef HASHFUNCTIONS_H_INCLUDED
#define HASHFUNCTIONS_H_INCLUDED
#include<math.h>

int MultiplicationHash(int k, int n)
{
    double ka = (double)k*(sqrt(5)-1.0)/2.0;
    int ika = ka;
    return n*(ka-ika);
}

int CharacterHash(int k , char * s)
{
    int i,x;
    for (i = 0 ; i < strlen(s) ; i++)
    {
        x += (x*s[i])%k;
    }
    x %= k;
    return x;
}


#endif // HASHFUNCTIONS_H_INCLUDED
