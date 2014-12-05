#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#define R 3
#define C 3

int MCP(int cost[R][C])
{
    int i,j;
    for(i=1;i<R;i++) cost[i][0] += cost[i-1][0];
    for(i=1;i<C;i++) cost[0][i] += cost[0][i-1];
    for(i=1;i<R;i++)
    {
        for(j=1;j<C;j++)
        {
            cost[i][j] = min3(cost[i-1][j],cost[i][j-1],cost[i-1][j-1]) + cost[i][j];
        }
    }
    return cost[R-1][C-1];
}
int main(int argc, char *argv[])
{
    int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    printf("Min Cost Path = %d\n",MCP(cost));


}
