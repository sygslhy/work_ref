/*
 * main.c
 *
 *  Created on: 24 oct. 2017
 *      Author: Administrator
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fd = fopen("in.txt", "r+");
	FILE *fd1 = fopen("in1.txt", "a+");
	printf("0x%x, 0x%x\n", (int)fd, (int)fd1);
	char str[12];
	fgets(str, 12, fd);
	//fscanf(fd1, "%s", str);
	printf("%s\n", str);
	//fprintf(fd1, "%d %d %d", 1, 2, 3);
	char str1[20];
	int n = fread(str1, 1, 20, fd1);
	printf("n=%d, %s\n",n , str1);
	fclose(fd);
	fclose(fd1);

	FILE *fd2 = fopen("in2.txt", "w+");
	char *buf = "lhy";
	fwrite(buf, 1, 3, fd2);
	fclose(fd2);

	FILE *fd3 = fopen("in3.txt", "r");
	fseek(fd3, 0, SEEK_END);
	int len = ftell(fd3);
	printf("file size is %d", len);
	fclose(fd3);

	FILE *fd4 = fopen("in4.txt", "w");
	fclose(fd4);
	rename("in4.txt", "in4-bg.txt");


	return 0;
}
