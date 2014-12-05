#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\basicdef.h"
#include "..\\Dijkstra.h"

void fun(int **a, int r, int c)
{
    int i,j;
    for(i=0;i<r;i++){
    for(j=0;j<c;j++)
    *(*(a+i)+j) = rand();}
    printf("Function\n");
    for(i=0;i<r;i++){
    for(j=0;j<c;j++)
    printf("%d ",a[i][j]);
    printf("\n");}
}
int  * randomfun()
{
    if(t==0) return t;
    int t = 20;
    printf("fun %u\n",&t);
    return &t;
}
int main()
{
    /*graph g;
    int ** w;
    g = CreateGraph(9);
    w = CreateGraphAM(9);
    g = AddEdgeW(g,1,2,5,&w);
    g = AddEdgeW(g,1,4,6,&w);
    g = AddEdgeW(g,1,3,7,&w);
    g = AddEdgeW(g,4,2,2,&w);
    g = AddEdgeW(g,3,4,1,&w);
    g = AddEdgeW(g,3,5,8,&w);
    g = AddEdgeW(g,6,4,9,&w);
    g = AddEdgeW(g,5,9,1,&w);
    g = AddEdgeW(g,5,8,4,&w);
    g = AddEdgeW(g,7,8,2,&w);
    NODE curr = g.list[1].top;
    printf("%d",curr->s.num);
    printf("path = %d\n",Dijkstra(g,1,5,w));*/
    int i = randomfun();
    printf("%d",i);

    return 0;

}

//int main(int argc, char *argv[])
//{
//    int **a,j,i,r=10,c=10,b[10][10];
//    a = (int**)malloc(10*sizeof(int *));
//    for(j=0;j<10;j++)
//    a[j] = (int*)calloc(10,sizeof(int));
//
////    for(i=0;i<r;i++){
////    for(j=0;j<c;j++)
////    printf("%d ",b[i][j]);
////    printf("\n");}
//
//    fun(b,r,c);
//
//    for(i=0;i<r;i++){
//    for(j=0;j<c;j++)
//    printf("%d ",b[i][j]);
//    printf("\n");}
//
//}
