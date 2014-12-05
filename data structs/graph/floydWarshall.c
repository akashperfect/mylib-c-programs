#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXINT  214748364
#define MININT -2147483648

int ** CreateGraphAM(int n)
{
    int ** w,i;
    w = (int**)calloc((n+1),sizeof(int*));
    for(i=0;i<=n;i++)
    {
        w[i] = (int*)calloc((n+1),sizeof(int));
    }
    return w;
}

void AddEdgeW(int u, int v, int wt, int ***w)
{
    //int ** we = (*w);
    *(*(*w+u)+v) = wt;
    *(*(*w+v)+u) = wt;
}

int ** FloydWarshall(int ** w, int size)
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        if(i!=j&&w[i][j]==0)
        w[i][j] = MAXINT;
    }
    for(k=1;k<=size;k++)
    for(i=1;i<=size;i++)
    for(j=1;j<=size;j++)
    if(w[i][j] > w[i][k]+w[k][j])
    w[i][j] =  w[i][k]+w[k][j];
    return w;

}

int main()
{
    int **w,i,j;
    w = CreateGraphAM(9);
    AddEdgeW(1,2,5,&w);
    AddEdgeW(1,4,10,&w);
    AddEdgeW(1,3,9,&w);
    AddEdgeW(4,2,2,&w);
    AddEdgeW(3,4,1,&w);
    AddEdgeW(3,5,8,&w);
    AddEdgeW(6,4,9,&w);
    AddEdgeW(5,9,1,&w);
    AddEdgeW(5,8,4,&w);
    AddEdgeW(7,8,2,&w);
    w = FloydWarshall(w,9);
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        printf("%d ",w[i][j]);
        printf("\n");
    }

    return 0;

}
