#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree_node * tree;
struct tree_node
{
    tree left;
    tree right;
    tree parent;
    char c;
};

//#include"hashtable_chaining.c"
void LCS(char *f,char *s,int **a)
{
    int m = strlen(f),n = strlen(s),i,j;
         for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
        a[i][j] = 0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(f[i-1]==s[j-1])
                a[i][j] = a[i-1][j-1]+1;
            else if(a[i-1][j]>=a[i][j-1])
                a[i][j] = a[i-1][j];
            else
                a[i][j] = a[i][j-1];
        }
    }
    //printf("%d",a[100][100]);
    return a;
}

void printAllCS(tree t,int **a,int i,int j,char *f)
{
    if(a[i][j-1] == a[i-1][j] == a[i-1][j-1])
    {
        t->c = f[i];
        printAllCS(t->left,a,i-1,j,f);
        printAllCS(t->right,a,i,j-1,f);
    }


}

void printLCS(int **a,char *f,int i,int j)
{
    if(i==0||j==0)
        return ;
    if((a[i][j-1] == a[i-1][j])&&(a[i-1][j]== a[i-1][j-1]))
    {
        printLCS(a,f,i-1,j-1);
        printf("%c",f[i-1]);
    }
    else if(a[i-1][j]>=a[i][j-1])
        printLCS(a,f,i-1,j);
    else
        printLCS(a,f,i,j-1);
}

int main(void)
{
    int i,j,**a;
    char *f,*s;
    f = (char*)malloc(1000);
    s = (char*)malloc(1000);
    FILE *fp,*fp1;
    fp = fopen("first.txt","r");
    fp1 = fopen("second.txt","r");
    a=(int**)malloc(1000*sizeof(int*));
    for(j=0;j<1000;j++)
    a[j]= (int*)malloc(1000*sizeof(int));

    fscanf(fp,"%s",f);
    fscanf(fp1,"%s",s);
    strcpy(f,"ABCBDAB");
    strcpy(s,"BDCABA");
    LCS(f,s,a);
    printf("%d",a[strlen(f)][strlen(s)]);
    tree t;
    t = (tree)malloc(sizeof(struct tree_node));
    t->left = NULL;
    t->right = NULL;
    t->parent = NULL;
    for(i=0;i<strlen(f)+1;i++)
    {for(j=0;j<strlen(s)+1;j++)
    printf("%d ",a[i][j]);
    printf("\n");}
    printLCS(a,f,strlen(f),strlen(s));
    return 0;
}
