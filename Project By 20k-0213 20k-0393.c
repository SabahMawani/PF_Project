#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

struct Words
{
	char Movies[21]; 
	char Books[36];
	char Colors[10];
	char Country[25];
	char Bands[21];
	char Animals[14];
};

void GuessTheWord(int *W, int *G);
void doneBy(void);
char decision_input(void);

int main()
{
	while(1)
	{
		int won=0, Gamesplayed=0;
		GuessTheWord(&won,&Gamesplayed);
		printf("Number of games played: %d\n",Gamesplayed);
		printf("Number of games won: %d\n\n",won);	
		doneBy();
		break;
	}
}
void GuessTheWord(int *W, int *G)
{
	char name[100], guess, play, *word, *answer, temp;
    int turns=10 , index,j=0, i=0, found, choice, flag=1;
    struct Words w[20];
    FILE *fptr;
    fptr = fopen("Movies.txt", "r");
    srand(time(0));
    for(i=0;i<20;i++)
    {
    	j=0;
		while(1)
		{
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Movies[j] = temp;
			j++;
		}
		w[i].Movies[j]='\0';
	}
	fclose(fptr);
	fptr = fopen("Animals.txt", "r");
	for(i=0;i<20;i++)
    {
    	j=0;
		while(1){
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Animals[j] = temp;
			j++;
		}
		w[i].Animals[j]='\0';
	}
	fclose(fptr);
	fptr = fopen("Bands.txt", "r");
	for(i=0;i<20;i++)
    {
    	j=0;
		while(1){
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Bands[j] = temp;
			j++;
		}
		w[i].Bands[j]='\0';
	}
	fclose(fptr);
	fptr = fopen("Books.txt", "r");
	for(i=0;i<20;i++)
    {
    	j=0;
		while(1){
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Books[j] = temp;
			j++;
		}
		w[i].Books[j]='\0';
	}
	fclose(fptr);
	fptr = fopen("Colors.txt", "r");
	for(i=0;i<20;i++)
    {
    	j=0;
		while(1){
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Colors[j] = temp;
			j++;
		}
		w[i].Colors[j]='\0';
	}
	fclose(fptr);
	fptr = fopen("Country.txt", "r");
	for(i=0;i<20;i++)
    {
    	j=0;
		while(1){
			temp =fgetc(fptr);
			if(temp == '\n'){
				break;
			}
			w[i].Country[j] = temp;
			j++;
		}
		w[i].Country[j]='\0';
	}
	fclose(fptr);
	printf("\nWhat is your name?\n");
	printf("Enter your name here: ");
//	scanf("%c",&temp);
	gets(name);
    printf("\nHello %s!\n",name);
    printf("Let's play Guess The Word\n");
    while (flag==1)
    {
		printf("\nWhich theme would you like to choose:\n");
    	printf("1. Animals\n");
	    printf("2. Bands\n");
    	printf("3. Books\n");
    	printf("4. Colors\n");
    	printf("5. Countries\n");
    	printf("6. Movies\n");
    	printf("Enter the number corresponding to your choice: ");
    	scanf("%d", &choice);
    	while(choice<1 || choice>6)
    	{
    		printf("\nPlease enter a valid choice.\n");
    		printf("Enter the number corresponding to your choice: ");
    		scanf("%d", &choice);
		}
		index = rand() % 20;
    	switch (choice) 
		{
    	case 1:
    	    word=malloc(strlen(w[index].Animals)+1);
    	    strcpy(word, w[index].Animals);
    	    answer=malloc(strlen(w[index].Animals)+1);
    	    break;
    	case 2:
    		word=malloc(strlen(w[index].Bands)+1);
    	    strcpy(word, w[index].Bands);
    	    answer=malloc(strlen(w[index].Bands)+1);
    	    break;
    	case 3:
    		word=malloc(strlen(w[index].Books)+1);
    	    strcpy(word, w[index].Books);
    	    answer=malloc(strlen(w[index].Books)+1);
    	    break;
    	case 4:
    		word=malloc(strlen(w[index].Colors)+1);
    		strcpy(word, w[index].Colors);
    		answer=malloc(strlen(w[index].Colors)+1);
    		break;
    	case 5:
    		word=malloc(strlen(w[index].Country)+1);
    		strcpy(word, w[index].Country);
    		answer=malloc(strlen(w[index].Country)+1);
    		break;
		case 6:
			word=malloc(strlen(w[index].Movies)+1);
			strcpy(word, w[index].Movies);
			answer=malloc(strlen(w[index].Movies)+1);
			break;
    	}
    	for (i = 0; i < strlen(word); i++) 
    	{
    	    if (word[i] == ' ') 
            	answer[i] = ' ';
            else if(word[i] == ':')
            	answer[i] = ':';
            else
            	answer[i]='-';
        }
        answer[i]='\0';
    	
		printf("\n\n%s \n", answer);

    	while (1) 
		{
        	printf("\nYou have %d more guesses left.\n", turns);
        	printf("Guess a letter:");
        	scanf(" %c", &guess);
    	    guess = toupper(guess);
       		found = 0;
		
        	for (i = 0; i < strlen(word); i++) 
        	{
        	    if (word[i] == guess)
				{
        	        answer[i] = guess;
        	        found = 1;
        	    }
        	}
        	if (found == 0) 
			{
        	    printf("\nWrong\n");
        	    turns--;
        	}
	
    	    if (turns == 0) 
			{
        	    printf("\n\nYou Lose!\n");
        	    printf("Better luck next time, %s.\n",name);
        	    printf("The word was %s .\n", word);
        	    *G+=1;
        	    free(word);
        	    free(answer);
        	    break;
        	}
	
    	    else 
			{
        	    if (strcmp(answer, word) == 0) 
        	    {
        	        printf("\n\nCongratulations! \nYou Won \nThe word was: %s\n", answer);
        	        *W+=1;
        	        *G+=1;
        	        free(word);
        	        free(answer);
        	        break;
        	    } 
				else
        	        printf("\n\n %s\n", answer);
        	}
    	}
    	printf("\n\nWould you like to play again? (y/n)\n");
    	play=decision_input();
		if (play == 'y')
		{
			flag=1;
			turns=10;
		}
		else 
			flag=0;
	}
}

void doneBy(void)
{
	printf("\n\n\tPROJECT\n\t\tGUESS THE WORD ON C");
	printf("\n\n\tDONE BY\n\t\tSABAH MAWANI & AROOBA MOIN");
	printf("\n\n\tROLL NO\n\t\t20K-CS-0393 & 20K-CS-0213");
}

char decision_input(void)
{
	char decision;
	printf("Enter your decision here: ");
	scanf(" %c", &decision);
	decision = tolower(decision);
	while (decision != 'y' && decision != 'n')
    {
    	printf("Please enter a valid choice!\n");
		printf("Enter your decision here: ");
    	scanf(" %c", &decision);
    	decision = tolower(decision);
	}
	return decision;
}
