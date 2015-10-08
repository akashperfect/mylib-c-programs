#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA 26
#include <time.h>

typedef struct trie * tries;

typedef struct trie{
    char lf;
    tries *alp;
};
extern tries new_trie_node();
extern tries insert_trie(tries t, char* key);
extern int search_key(tries t, char* key);
extern tries delete_trie(tries t, char * key);
extern void print_trie(tries t);

tries new_trie_node()
{
    tries t;
    int i;
    t = (tries)malloc(sizeof(struct trie));
    t->lf = 'n';
    t->alp = (tries*)malloc(ALPHA*sizeof(tries));

    for(i=0;i<ALPHA;i++)
    {t->alp[i] = NULL;
    }
    return t;
}



tries insert_trie(tries t, char *key)
{
    int l=0;
    tries ins = t;
    while(1)
    {

        if(l==strlen(key)-1)
        {
            if(ins->alp[key[l]-97]==NULL)
            {
                ins->alp[key[l]-97] = new_trie_node();
                ins->lf = 'l';
            }
            break;
        }
        if(ins->alp[key[l]-97]==NULL)
        {
            ins->alp[key[l]-97] = new_trie_node();
            ins->lf = 'n';
        }
        ins = ins->alp[key[l]-97];
        l++;

    }
    return t;

}



int search_key(tries t, char* key)
{
    int l=0;
    tries fin = t;
    while(l<strlen(key))
    {
        if(fin->alp[key[l]-97]!=NULL)
        {
            fin = fin->alp[key[l]-97];
            l++;
        }
        else
            break;
    }
    if(l==strlen(key))
        return 1;
    return 0;
}

void rec_trie(tries t, int lev)
{
    int i;
    for(i=0;i<ALPHA;i++)
    if(t->alp[i]!=NULL)
    {
        printf ("%d %c %c\n",lev,i+97,t->lf);
        rec_trie(t->alp[i],lev+1);
    }
    return ;
}

void print_trie(tries t)
{
    int l=0,i;
    rec_trie(t,l);

}


int main()
{
    clock_t begin, end;

    // Input keys (use only 'a' through 'z' and lower case)
    FILE *fp;
    char ch[10000][20];
    int i=0,p=10;
    fp = fopen("dataset.txt","r");
    //ch = (char *)malloc(10000);
//    while(p--)
//    {
//        fscanf(fp,"%s",ch[i]);
//        printf("%s\n",ch[i]);
//        i++;
//
//    }
//    int k;
//    for (k=0;k<i;k++)
//    printf("%s",ch[k]);

    while(fscanf(fp,"%s",ch[i])!=EOF)
    {
        i++;
    }
    tries t;
   t = new_trie_node();
    p=i;


    // Construct trie
    begin = clock();
    for(i = 0; i < p; i++)
    {
        t = insert_trie(t,ch[i]);

    }
    char output[][32] = {"Not present in trie", "Present in trie"};
    // Search for different keys
    printf("%s --- %s\n", "the", output[search_key(t, "the")] );
    printf("%s --- %s\n", "acin", output[search_key(t, "acin")] );
    printf("%s --- %s\n", "tholoi", output[search_key(t, "tholoi")] );
    printf("%s --- %s\n", "abacu", output[search_key(t, "abacu")] );
    end = clock();
    printf("sort time : %lf\n", (double)(begin) / CLOCKS_PER_SEC);
    //print_trie(t);
    return 0;
}
