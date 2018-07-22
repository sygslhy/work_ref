/*
 * main.c
 *
 *  Created on: 1 oct. 2017
 *      Author: Administrator
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringMethod.h"

int main (int argc, char* argv[])
{
/*	char* strtest = "world";
	char* stryuan = "Hello";
	char  strres[20];
	stringCopy(strres, stryuan);
	printf("%s\n", strres);

	printf("%s ; %s\n", strres, strtest);
	char* backup = stringConnect(strres, strtest);
	printf("%s ; %s\n", strres, backup);

	char* str1 = "Hello world";
	char* str2 = "world";
	char* res = stringSearch(str1, str2);
	printf("%s\n", res);

	char* s1 = "Yuan";
	char* s2 = "Yuanq";
	printf("%d\n", stringCompare(s1, s2));

	char s3[16];
	stringCopy(s3, "Hello");
	printf("%s\n", s3);
	stringReverse(s3);
	printf("%s\n", s3);*/

/*
	int *array = (int*)malloc(sizeof(int)*2);
	for(int i=0;i<2;i++)
	{
		array[i] = 0;
		printf("%d\n", array[i]);
	}
	free(array);

	int nrows = 8;
	int ncolumns = 8;
	int **array1 = malloc(nrows * sizeof(int *));
	for(int i=0; i<nrows; i++)
	{
		array1[i] = (int*)malloc(sizeof(int)*ncolumns);
		for(int j=0; j<ncolumns; j++)
		{
			array1[i][j] = 0;
		}
	}

	for(int i=0; i<nrows; i++)
	{
		for(int j=0; j<ncolumns; j++)
		{
			printf("%d,", array1[i][j]);
		}
	}

	for(int i=0; i<nrows; i++)
	{
		free(array1[i]);
	}
	free(array1);
*/

/*	int **array3 = (int**)calloc(3, sizeof(int*));
	array3[0] = (int*)calloc(1, sizeof(int));
	array3[1] = (int*)calloc(2, sizeof(int));
	array3[2] = (int*)calloc(3, sizeof(int));
	int lens[3] = {1,2,3};

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<lens[i]; j++)
		{
			printf("%d : ", array3[i][j]);
		}
		printf("\n");
	}
*/
	char mem1[15];
	char *mem2 = "helloworld";
	memcpy(mem1, mem2, 11);
	printf("%s\n", mem1);

/*	char *str1 = mem1 + 2;
	char *str2 = mem1 + 5;
	memmove(str2, str1, 2);
	printf("%s\n", mem1);*/

	printf("%s, %s\n", mem1, mem2);
	printf("memcmp %d\n", memcmp(mem1, mem2, 11));

	return 0;
}

