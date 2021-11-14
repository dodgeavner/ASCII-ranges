/**
 * File Name: con.c
 * Program get from the user/file a string and print a shorter version of the string with ranges of the diffrent classes of ASCII chars
 *
 * @author Avner Azoulay
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ZERO 0
#define ONE 1
#define MAX 81
#define HYPHEN '-'
#define SPACE ' '
#define NUMBERBOUNDARY 65
/*Public array of chars - used in more than one functions*/
char s1[MAX]; 
char s2[MAX];

void readString();
void contract(char s1[], char s2[]);
void printVersions();


int main()
{
	readString();
	printVersions();
	return(0);
}


void printVersions()
{
	printf("The original string: %s \n",s1);
	contract(s1,s2); /* Will send to contract function to make the string shorter*/
	printf("The shorter version of this string is: %s\n ",s2);
}


void readString()
{
	/*FILE *read;*/ /* creating file for reading */
	/*read = fopen("test.txt" , "r"); *//* opening file for reading */
	/*if(read == NULL)*/ 
	/*{*/
		/*perror("Error opening file");*/
		printf("Please enter a string: \n");
		fgets (s1,MAX,stdin); /*Insert new string from user input to s1 array */
    	puts(s1); 
	/*}*/
	/*else*/
	/*{*/
		/*fgets (s1,MAX,read);*/ /* writing content to s1 from file*/
    		/*puts(s1); */
  		/*fclose(read);*/
	/*}*/
}

void contract(char s1[], char s2[])
{ 
	/*i - indicator of s1 (input) array ,
	  z - indicator of s2 (output) array
	  j - indicator of consecutive numbers count*/
	  
	int i,j,z;
	for(i=ZERO, j= ZERO ,z=ZERO ; i < MAX ; i++,z++)
	{
		if(s1[i] == NUMBERBOUNDARY ) /*In case We have the boundary between @ and A(not same category) in chapter 7 we'll defer between classes of ASCII*/
		{
			j=ZERO;
			s2[z] = s1[i];
		}
		if(s1[i+ONE] == s1[i]) /*Equal chars will directly insert and move on*/
		{
			s2[z] = s1[i];
			j = ZERO ;
		}
		if(s1[i] == SPACE) /*Space will directly insert and move on*/
		{
			s2[z] = SPACE;
		}	
		if((s1[i+ONE] - s1[i]) == ONE && s1[i] != SPACE ) /*consecutive numbers diffrence is always one*/
		{
			j++;
			if(j > ONE) /*A range is printed only when we have more than two consecutive numbers*/
		{
			s2[z] = HYPHEN;
			z++; /*after inserting HYPHEN we'll need to move forward on s2 array*/
			for(;((s1[i+ONE] - s1[i]) == ONE ); i++){} /*will pass all the consecutive numbers unil the last one*/
			j = ZERO ;
		}	
			s2[z] = s1[i];
		}
		else /*or else will just insert new char*/
		{
			j = ZERO ;
			s2[z] = s1[i];
		}
	}
}

