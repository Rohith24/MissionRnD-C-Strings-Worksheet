/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int findString(char *str1, char *str2);
void copystr(char *src, char *dest);
int getnoofwords(char *str);


char ** commonWords(char *str1, char *str2) {
	if (str1 == 0 || str2 == 0)
		return NULL;
	else
	{
		int counter1 = 0, counter2 = 0, counter3 = 0;
		int str1wordcount = getnoofwords(str1);

		char **str1words = (char **)malloc(str1wordcount*sizeof(char *));
		char **comwords = (char **)malloc(str1wordcount*sizeof(char *));
		
		for (counter1 = 0; counter1 < str1wordcount; counter1++){
			str1words[counter1] = (char *)malloc(SIZE*sizeof(char));
			comwords[counter1] = (char *)malloc(SIZE*sizeof(char));
			comwords[counter1][0] = '\0';
		}
		
		for(counter1=0,counter2=0;str1[counter1] != '\0'&&counter2<str1wordcount;counter1++){
			if (str1[counter1] != ' '){
				str1words[counter2][counter3++] = str1[counter1];
			}
			else if (str1[counter1] == ' ')
			{
				str1words[counter2][counter3] = '\0';
				counter2++;
				counter3 = 0;
			}
		}
		str1words[counter2][counter3] = '\0';


		for (counter1 = 0, counter2 = 0; counter1 < str1wordcount; counter1++){
			if (findString(str2, str1words[counter1]) == 1){
				copystr(str1words[counter1], comwords[counter2]);
				counter2++;
			}
		}

		if (counter2>0)
			return comwords;
		else
		{
			return NULL;
		}
	}
}

int getnoofwords(char *str){

	int i = 0, count = 1;

	while (str[i] != '\0'){

		if (str[i] == ' ')
			count++;

		i++;
	}

	return count;

}

int findString(char *str1, char *str2){
	int counter1 = 0, counter2 = 0;
	while (str1[counter1] != '\0'){
		while (str1[counter1] == str2[counter2] && str2[counter2] != '\0'){
			counter1++;
			counter2++;
		}
		if (str2[counter2] != '\0'&&counter2>0){
			counter2 = 0;
		}
		counter1++;
	}
	if (counter2 > 0)
		return 1;
	return 0;
}

void copystr(char *src, char *dest){

	int i = 0;

	while (src[i] != '\0')
		dest[i] = src[i++];

	dest[i] = '\0';
}