#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#define R 6
#define C 5

int MSSSMWA1S(int mat[R][C])
{
    int c[R][C],i,j,entry,max=0;
    for(i=0;i<R;i++)
    for(j=0;j<C;j++) c[i][j] = 0;
    for(i=0;i<R;i++) c[i][0] = mat[i][0];
    for(i=1;i<C;i++) c[0][i] = mat[0][i];
    for(i=1;i<R;i++)
    {
        for(j=1;j<C;j++)
        {
            if(mat[i][j]!=0)
            {
                c[i][j] = min3(c[i-1][j],c[i][j-1],c[i-1][j-1]) + 1;
                if(c[i][j]>max) max = c[i][j];
            }
        }
    }
    return max;
}


int main(int argc, char *argv[])
{
    int a[R][C] = {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

    printf("Maximum size square sub-matrix with all 1s = %d\n",MSSSMWA1S(a));

}
