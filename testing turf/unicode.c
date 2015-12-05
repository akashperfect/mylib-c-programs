#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


int main(int argc, char const *argv[])
{
	int i;
	char *str;
	char sample;
	FILE *fpt;
	wchar_t wch;
	fpt = fopen("input.txt", "r");
	str = ( char *)calloc(300, sizeof( char ));
	while(fgets(str, 300, fpt) != NULL){
		printf("len = %d\n", strlen(str));
		for ( i = 0; i < strlen(str); ++i) {
			printf("%d%c ", str[i], (int)str[i]);
		}
		printf("\n");
	}
	printf("%d\n", sizeof(wchar_t));
	return 0;
}