/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

int strlen(char* str);
void removeSpace(char *str,int p);
int findSpace(char *str,int st);


char removeSpaces(char *str) {
	if (str == ""||str==0)
		return '\0';
	else
	{
		int st = 0;
		while (str[st] != ' '&&str[st] != '\0'){
			st++;
		}
		if (st == strlen(str))
			return ' ';
		removeSpace(str, st);
		while (st < strlen(str)){
			st=findSpace(str, st);
			removeSpace(str, st);
		}
	}
}

void removeSpace(char *str,int p){
	int i,len=strlen(str);
	for (i = p; i<len - 1; i++)
		str[i] = str[i + 1];
	len -= 1;
	str[len] = '\0';
}

int strlen(char* str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

int findSpace(char *str,int st){
	while (str[st] != ' '){
		st++;
	}
	return st;
}