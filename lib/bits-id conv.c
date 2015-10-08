#include<stdio.h>
int main()
{
    FILE *fp,*fp1;
    int i,c=0;
    char id[20],s[30],ch[2];
    fp = fopen("A&_students.txt","r");
    fp1 = fopen("mails.txt","w");
    while(fscanf(fp,"%s",id)!=EOF)
    {
        s[0] = '\0';
        //strcpy(s,ch);
        if(id[4]=='H')strcat(s,"h");
        else
        strcat(s,"f");//h for ME
        strncat(s,id,4);
        //printf("%s\n",s);
        //printf("%s\n",s);
        for(i=8;i<11;i++)
        {
            ch[0] = id[i];
            ch[1] = '\0';
            strcat(s,ch);
        }
        strcat(s,"@pilani.bits-pilani.ac.in");
        c++;
        fprintf(fp1,"%s, ",s);
        if(c==50)
        {
            fprintf(fp1,"\n\n\n");
            c=0;
        }
    }
    printf("%d",c);

}
