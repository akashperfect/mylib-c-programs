#include<stdio.h>
int main()
{
    FILE *fp,*fp1;
    int i,c=0;
    char id[20],s[30],ch[2];
    fp = fopen("email.txt","r");
    fp1 = fopen("doc.txt","w");
    while(fscanf(fp,"%s",id)!=EOF)
    {
        if((id[7]=='7'&&id[6]=='A')||(id[5]=='7'&&id[4]=='A'))
        {fprintf(fp1,"%s\n",id);
        c++;}
        /*s[0] = '\0';
        ch[0] = id[0];
        ch[1] = '\0';
        //strcpy(s,ch);
        strcat(s,"h201");
        //printf("%s\n",s);
        ch[0] = id[3];
        ch[1] = '\0';
        strcat(s,ch);
        //printf("%s\n",s);
        for(i=8;i<11;i++)
        {
            ch[0] = id[i];
            ch[1] = '\0';
            strcat(s,ch);
        }
        strcat(s,"@bits-pilani.ac.in");
        */
        //fprintf(fp1,"%s, ",s);
    }
    printf("%d",c);

}
