#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\basicdef.h"

struct{
int a;
char c;
long double r;
//char d3;
//double da;
}stru;
int var;
int var;
int var=90;

char* func()
{
   char *str = (char*)malloc(12);
   strcpy(str,"Dragon!");
   return(str);
}

int test(int a, int b)
{
    return a + b;
}

void funsize(int **arr)
{
    printf("size of arr = %d\n",sizeof(*arr));
}
extern int a1;
int main(int argc, char *argv[])
{
    unsigned  i = 10100;
    int t=5;
    int (*ptr)[3];
    //printf("%u", (~0) );
    int *a = (int*)malloc(5*sizeof(int)), *b;
    i=0;
    /*while(t--) scanf("%d",&a[i++]);
    b = a;
    for(i=0;i<5;i++) printf("%d ",b[i]);*/
    printf("%d",strcmp("255","20a"));
    printf("%d",atoi("2v5a"));
    printf("\n\n\n\nfunc = %x\n",ptr);
    ptr+=2;
    printf("\n\n\n\nfunc = %x\n",ptr);
    printf("%s\n",func());
    char *c = calloc(16,1);
    free(c);
    c[1] = 'a';
    printf("%d\n\n",c[0]);
    int d[100][10];
    printf("size of arr main = %d\n",sizeof(d));
    funsize(d);
    int view = MAXINT;
    view++;
    printf("\nview = %d and MININT = %d\n",view,MININT);
    //extern int a1;

    int a12=34;

    printf("%d",a12);
    int var = 564 ;
printf("%d \n",var);


puts("Geeksfor");
    puts("Geeks");

    fputs("Geeksfor", stdout);
    fputs("Geeks", stdout);
    printf("Hello GeeksforGeeks");
 puts("Geek%sforGeek%s");
    //int * q = (int*)calloc(10000000,sizeof(int));
    //free(q);
    //q[10000000000000000000000000000000000000000000000000000000000000000] = 2;
    //printf("array = %d\n",q[100000]);
    //int w[10000000];

//    int **test1,j;
//    test1 = (int**)malloc(10*sizeof(int *));
//    for(j=0;j<10;j++)
//    test1[j] = (int*)malloc(10*sizeof(int));
    int ** a1,j;
    a1 = (int**)calloc(10,sizeof(int*));
    for(j=0;j<10;j++)
        a1[j] = (int*)calloc(10,sizeof(int));


    printf("sizes\nint = %d\n",sizeof(int));
    printf("char = %d\n",sizeof(char));
    printf("float = %d\n",sizeof(float));
    printf("double = %d\n",sizeof(double));
    printf("long = %d\n",sizeof(long));
    printf("long long = %d\n",sizeof(long long));
    printf("long long int = %d\n",sizeof(long long int));
    printf("long int = %d\n",sizeof(long int));
    printf("long double = %d\n",sizeof(long double));
    printf("short int = %d\n",sizeof(short int));
    printf("strcut = %d\n",sizeof(stru));


}
