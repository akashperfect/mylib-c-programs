# include <stdio.h>
#include "Trie.h"
///* Function to swap values at two pointers */
//void swap (char *x, char *y)
//{
//    char temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
///* Function to print permutations of string
//   This function takes three parameters:
//   1. String
//   2. Starting index of the string
//   3. Ending index of the string. */
//void permute(FILE *fp,char *a, int i, int n)
//{
//   int j;
//   if (i == n)
//     fprintf(fp,"%s\n", a);
//   else
//   {
//        for (j = i; j <= n; j++)
//       {
//          if(a[i]!=a[j])
//          swap((a+i), (a+j));
//          permute(fp,a, i+1, n);
//          swap((a+i), (a+j)); //backtrack
//       }
//   }
//}

/* Driver program to test above functions */
int main()
{
//   int t = 5*2*3/4*10;
//   printf("%d",t);
   tries t;
   t = new_trie_node();
   char * s,*s1,*s2;
   s = "akash";
   s1 = "pooja";
   s2 = "saxena";
   t = insert_trie(t,s);
   t = insert_trie(t,s1);
   t = insert_trie(t,s2);
   print_trie(t);
   printf("%d\n",search_key(t,s));
   return 0;
}
