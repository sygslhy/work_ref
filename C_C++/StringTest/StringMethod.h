/*
 * StringMethod.h
 *
 *  Created on: 1 oct. 2017
 *      Author: Administrator
 */

#ifndef STRINGMETHOD_H_
#define STRINGMETHOD_H_

char* stringCopy(char* strdes, char* strsrc);

char* stringConnect(char* strdes, const char* strsrc);

char* stringSearch(const char* str, const char* substr);

int stringCompare(const char* str1, const char* str2);

char* stringReverse(char* str);

#endif /* STRINGMETHOD_H_ */
