/*
 * StringMethod.c
 *
 *  Created on: 1 oct. 2017
 *      Author: Administrator
 */
#include <stdio.h>
#include <string.h>

char* stringCopy(char* strdes, const char* strsrc)
{
	if (strdes==NULL||strsrc==NULL)
	{
		perror("ERROR, NULL string");
		return NULL;
	}

	if (strdes==strsrc)
	{
		return strdes;
	}
	char* res = strdes;


	while (*strsrc!='\0')
	{
		*strdes++ = *strsrc++;

	}

	*strdes = '\0';
	return res;
}

char* stringConnect(char* strdes, const char* strsrc)
{
	if (strdes==NULL||strsrc==NULL)
	{
		perror("NULL ERROR");
		return NULL;
	}

	int lens = strlen(strdes);
	char* strres = strdes;
	strdes=strdes+lens;
	while(*strsrc!='\0')
	{
		*strdes++ =*strsrc++;
	}
	*strdes='\0';
	return strres;
}

char* stringSearch(char* str, const char* substr)
{
	if (str==NULL||substr==NULL)
	{
		perror("NULL Pointer ERROR");
		return NULL;
	}
	if (str==substr)
	{
		return str;
	}
	int sublens = strlen(substr);
	int strlens = strlen(str);
	for (int i=0;i<=strlens-sublens;i++)
	{
		char* res = str + i;
		int j=0;
		while ( *(str+i+j)==*(substr+j) && *(substr+j)!='\0' )
		{
			j++;
		}
		if (j==sublens)
		{
			return res;
		}
	}

	return NULL;
}


int stringCompare(const char* str1, const char* str2)
{
	if (str1==NULL||str2==NULL)
	{
		perror("NULL Pointer ERROR\n");
		return -1;
	}
	if (str1==str2)
	{
		return 0;
	}
	while ( *str1!='\0' || *str2!='\0' )
	{
		int res = *str1++ - *str2++;
		if (res){
			return res;
		}
	}
	return 0;

}

char* stringReverse(char* str)
{
	char temp;
	int num = strlen(str);



	for (int i=0; i<num/2; i++)
	{
		temp = str[i];
		str[i] = str[num-i-1];
		str[num-i-1] = temp;
		//printf("%c, %c\n", str[i], str[num-i-1] );
	}

	return str;
}
