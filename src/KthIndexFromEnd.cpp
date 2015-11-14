/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int strlength(char *str);

char KthIndexFromEnd(char *str, int K) {
	if (str==0||str==""||K<0)
		return '\0';
	else
	{
		int strlen = strlength(str);
		if (strlen < K){
			return '\0';
		}
		return str[strlen - K - 1];			//get element from last
	}
}

int strlength(char *str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;

}