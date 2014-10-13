/* Justin Newman
Quiz #6 Part 1:
Letter Guessing Game
ECE 270 9/28/14
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
	{

		char word[ ]="dissonance", display[strlen(word)], guess; //word[ ]="dissonance", display[ ]="----------;
		int i=0, j=0, correctCounter=0, guessCounter=0;

		FILE *fp;
		fp=fopen("quiz6part1.txt","w");

		printf("Word guessing game");
		printf("\nYou have 10 guesses");

		fprintf(fp,"Word guessing game");
		fprintf(fp,"\nYou have 10 guesses");

		for(j=0;j<strlen(word);j++)
			{
				display[j]='-';
			}
		display[strlen(word)]='\0';

		//game continues until the number of correct guesses = the number of letters in the word
		//or the number of guesses = the number of allowed guesses
		while((correctCounter<10)&&(guessCounter<10))

			{

				guessCounter++;

				printf("\n\nTry # %d",guessCounter);
				fprintf(fp,"\n\nTry # %d",guessCounter);

				printf("\nGuess a letter: ");
				scanf("\n%c",&guess);
				fprintf(fp,"\nGuess a letter: %c",guess);

				for (i=0;i<11;i++)

					{


						if ((guess==word[i])&&(display[i]=='-'))

							{

								display[i]=guess;
								correctCounter=correctCounter+1;

							}

					}

					printf("\n%s",display);
					fprintf(fp,"\n%s",display);

				}

		//Determines if game was won/lost and displays accordingly
		if (correctCounter==10)
			{
				printf("\nCongrats, You WIN!!");
				printf("\nWon in %d guesses", guessCounter);

				fprintf(fp,"\nCongrats, You WIN!!");
				fprintf(fp,"\nWon in %d guesses", guessCounter);
			}
		else
			{
				printf("\nSorry, you lost");
				printf("\n\nThe mystery word was: %s",word);

				fprintf(fp,"\nSorry, you lost");
				fprintf(fp,"\n\nThe mystery word was: %s",word);
			}
		return 0;

	}
