#ifndef BASICDEF_H_INCLUDED
#define BASICDEF_H_INCLUDED
#define MAXINT  2147483647
#define MININT -2147483648
#define ALPHA 26

int max2(int a,int b)
{
    return (a>b)?a:b;
}

int min(int a,int b)
{
    return (a<b)?a:b;
}

int min3(int a,int b,int c)
{
    int min = (a<b)?a:b;
    return (min<c)?min:c;
}

int ** DeclareDDArray(int r,int c)
{
    int ** a,i;
    a = (int**)calloc(r,sizeof(int*));
    for(i=0;i<r;i++)
        a[i] = (int*)calloc(c,sizeof(int));

    return a;
}

int ** InitializeDDArray(int r, int c)
{
    int **a = DeclareDDArray(r,c),i,j;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    a[i][j] = rand();
    return a;
}

void printarrays(int *a,int size)
{
    int i;
    FILE *fp;
    fp = fopen("Array.txt","w");
    for(i=0;i<size;i++)
    fprintf(fp,"%d\n",a[i]);
    fclose(fp);
}

void printarrayd(int **a,int r,int c)
{
    int i,j;
    FILE *fp;
    fp = fopen("Array.txt","w");
    //fprintf(fp,"\n\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        fprintf(fp,"%-6d",a[i][j]);
        fprintf(fp,"\n");
    }

    fclose(fp);
}

#endif // BASICDEF_H_INCLUDED
