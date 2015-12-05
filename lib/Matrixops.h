#ifndef MATRIXOPS_H_INCLUDED
#define MATRIXOPS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void RotateMatrix(int **a, int s, int e)
{
    if(s>=e) return;
    int temp;
    int i;
    for(i=s;i<e-1;i++)
    {
        temp = a[s][i];
        a[s][i] = a[e-i-1][s];
        a[e-i-1][s] = a[e-1][e-i-1];
        a[e-1][e-i-1] = a[s+i][e-1];
        a[s+i][e-1] = temp;
    }
    RotateMatrix(a,s+1,e-1);
}


void FindEleSort2DArr(int **a,int r,int c,int key)
{
    int i=0,j=c-1,start=0;
    while(1)
    {
        if(i >=r || j < 0) {
        printf("Element Not found\n"); break;}
        start = a[i][j];
        if(start==key){
            printf("Element found at row = %d and column = %d\n",i+1,j+1); break;}
        else if(start > key)
            j--;
        else if(start < key)
            i++;
    }
    return;
}


#endif // MATRIXOPS_H_INCLUDED
