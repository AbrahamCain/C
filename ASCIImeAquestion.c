#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	system("color e2");			//change color of font and terminal
	
	char word[] = "CyberSurfer";		//declare a character array
	
	printf("Please enter a word for translation: ");
	
	scanf("%[^\n]%*c", &word);		//scan for input using the modifiers to allow you to enter spaces as well
	printf("\n\n");
	
	int x = strlen(word);			//declare x as a variable to measure the length of the entered word
	int i;					//declare i
	
    //enter a loop to print out the ASCII value for each character in the character array
    for (i=0; i<=x-1; i++)
    {
        printf("%d : ", word[i]);
    }
	printf("NULL");				//optional, print NULL after the last colon
	printf("\n\n");	
	return 0;				//exit successfully
}
