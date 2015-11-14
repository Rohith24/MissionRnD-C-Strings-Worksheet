/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverseWord(char *inp, int st, int end);
void swap(char *input, int i, int j);
void str_words_in_rev(char *input, int len){
	int counter1, counter2, count = 0;
	for (counter1 = 0, counter2 = len - 1; counter1 < counter2 && counter1 != counter2; counter1++, counter2--)
		swap(input, counter1, counter2);

	for (counter1 = 0, counter2 = 0; counter1 <= counter2&&input[counter2] != '\0';) {
		if (input[counter2] != ' '){
			counter2++;
		}
		else{
			count++;
			reverseWord(input, counter1, counter2 - 1);
			counter2++;

			counter1 = counter2;
		}
	}



	if (count == 0){
		reverseWord(input, 0, len - 1);
		return;
	}

	reverseWord(input, counter1, counter2 - 1);
	
}

void swap(char *input, int i, int j){
	char temp = input[i];
	input[i] = input[j];
	input[j] = temp;
}

void reverseWord(char *input, int counter1, int counter2){

	char temp;
	for (; counter1 < counter2 && counter1 != counter2; counter1++, counter2--)
		swap(input, counter1, counter2);
}