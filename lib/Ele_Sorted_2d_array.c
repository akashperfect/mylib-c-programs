#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "bucketsort.h"
#include "Matrixops.h"

int main(int argc, char *argv[])
{
    int r=10,c=10,**a = InitializeDDArray(r,c),*b = (int*)calloc(r,sizeof(int)),i,j,start=0;
    for(j=0;j<c;j++)
    {
        for(i=0;i<r;i++) b[i] = a[i][j];
        bucketsort(b,r);

        for(i=0;i<r;i++) a[i][j] = b[i];

    }

    for(i=0;i<r;i++)
    {
        bucketsort(a[i],r);
    }
    printarrayd(a,r,c);

    //RotateMatrix(a,0,r);
    FindEleSort2DArr(a,r,c,19629);

    printarrayd(a,r,c);
}
