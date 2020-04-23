#include <stdio.h>

int main(){
	
	//declare character as a char
	char character;
	
	//ask user to enter a character
	printf("Please enter a character: ");
	scanf("%c", &character); //%c is to print a char
	
	printf("\n\nYou entered: %c", character);

	//%d prints the int (ASCII) value of a character
	printf("\nASCII is: %d", character); 
	
	printf("\n\n");   	// "\n" is the newline escape character
	return 0;			//exit code is success 

}
