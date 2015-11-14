/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int getnodigits(int decimal,int floatpart);
int gettenspower(int num, int power);

void number_to_str(float number, char *str,int afterdecimal){
	int decimalpart, floatpart=0, digits = 0;
	if (number > 0){			//if number is positive
		decimalpart = number;
		if (afterdecimal>0)
			floatpart = (number - decimalpart)*gettenspower(10, afterdecimal);		//floatpart=number*tenspower //ex: 0.7654*100 if afterdecimal =2		
		digits += getnodigits(decimalpart,floatpart);			
		str[digits] = '\0';
	}
	else
	{
		decimalpart = number*-1;
		if (afterdecimal>0)
			floatpart = ((-1*number) - decimalpart)*gettenspower(10, afterdecimal);
		digits += getnodigits(decimalpart, floatpart) + 1;
		str[digits] = '\0';
		str[0] = '-';
	}
	
	if (floatpart > 0){
		while (floatpart > 0){
			str[--digits] = (floatpart % 10) + '0';
			floatpart /= 10;
		}
		str[--digits] = '.';
	}
	while (decimalpart > 0){
		str[--digits] = (decimalpart % 10) + '0';
		decimalpart /= 10;
	}

	
}

int getnodigits(int decimal, int floatpart){
	int counter = 0;
	while (decimal > 0){
		decimal = decimal / 10;
		counter++;
	}
	if (floatpart > 0){
		counter++;
		while (floatpart > 0)
		{
			floatpart = floatpart / 10;
			counter++;
		}
	}
	return counter;
}

int gettenspower(int num,int power){
	int i, result = 1;
	for (i = 0; i < power; i++){
		result *= num;
	}
	return result;
}