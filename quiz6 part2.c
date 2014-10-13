/* Justin Newman
Quiz #6 Part 2:
Hangman Game
ECE 270 9/28/14
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//prototype of function to display hangman status
void gameDisplay(float , FILE *);

int main()
	{
        //Declare and initialize variables
		char word[100], display[strlen(word)], guess; //word[ ]="dissonance", display[ ]="----------;
		int i=0, j=0, correctCounter=0, guessCounter=0, maxGuesses=10, wrongGuesses=0;
        float percentWrong=0;

        //Open file and prepare to write output to it
        FILE *fp;
		fp=fopen("quiz6part2.txt","w");

		printf("Hangman Game");
		fprintf(fp,"Hangman Game");

		//Allow player #1 to set mystery word and number of guesses allowed
		printf("\n\nPlease enter a word for the player to guess: ");
		scanf(" %s",&word);
        fprintf(fp,"\n\nPlease enter a word for the player to guess: %s",word);

		printf("\n\nPlease enter how many guesses the player should get: ");
		scanf(" %d",&maxGuesses);
        fprintf(fp,"\n\nPlease enter how many guesses the player should get: %d",maxGuesses);

		//Clear screen
		system("cls");

		printf("\nBegin Game!");
		fprintf(fp,"\nBegin Game!");

		//Populate display array with '-' for each letter in the mystery word
		for(j=0;j<strlen(word);j++)
			{
				display[j]='-';
			}

		display[strlen(word)]='\0';

		//Game continues until the number of correct guesses is less than the length of the mystery word
		//Game continues until the number of guesses equals the maximum guesses allowed
		while((correctCounter<strlen(word))&&(guessCounter<maxGuesses))

			{

				guessCounter++;

				printf("\n\nTry # %d",guessCounter);
                fprintf(fp,"\n\nTry # %d",guessCounter);

				printf("\nGuess a letter: ");
				scanf("\n%c",&guess);
                fprintf(fp,"\nGuess a letter: %c",guess);

				for (i=0;i<strlen(word);i++)

					{


						if ((guess==word[i])&&(display[i]=='-'))

							{
								display[i]=guess;
								correctCounter++;

							}


					}
				//Setting up wrong guess percentage to be passed to display function
                wrongGuesses=(guessCounter-correctCounter);
                percentWrong=(float)wrongGuesses/(float)maxGuesses;

                //Functions to simplify debugging
                //printf("%f",percentWrong); - debug
                //printf("%d",wrongGuesses); - debug

                //Clear screen
                system("cls");

                //Display current game status
                gameDisplay(percentWrong, fp);

                printf("\n%s",display);
                fprintf(fp,"\n%s",display);

            }

        system("cls");

        //Determines if game was won/lost and displays accordingly
		if (correctCounter==strlen(word))
			{
				printf("\nCongrats, You WIN!!");
				printf("\n\nWon in %d guesses", guessCounter);

				fprintf(fp,"\nCongrats, You WIN!!");
				fprintf(fp,"\n\nWon in %d guesses", guessCounter);
			}
		else
			{
				printf("\nSorry, you lost\n");
                fprintf(fp,"\nSorry, you lost\n");

                gameDisplay(1.0, fp);

				printf("\n\nYour guess:           %s",display);
                fprintf(fp,"\n\n Your guess:          %s",display);

				printf("\n\nThe mystery word was: %s\n",word);
                fprintf(fp,"\n\nThe mystery word was: %s",word);

			}

        fclose(fp);
		return 0;

	}

//Function displays hangman based on wrong guesses as a percent of total guesses
void gameDisplay(float wrong,FILE *disp)
    {

        if (wrong>0&&wrong<.1)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                    }
                else if (wrong>=.1&&wrong<.2)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.2&&wrong<.3)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|                |-------|");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                 ------- ");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                |-------|");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                 ------- ");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                    }
                else if (wrong>=.3&&wrong<.4)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|");
                        printf("\n|              | |       |");
                        printf("\n|              | |       |");
                        printf("\n|              | |       |");
                        printf("\n|              m |       |");
                        printf("\n|                 ------- ");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|");
                        fprintf(disp,"\n|              | |       |");
                        fprintf(disp,"\n|              | |       |");
                        fprintf(disp,"\n|              | |       |");
                        fprintf(disp,"\n|              m |       |");
                        fprintf(disp,"\n|                 ------- ");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.4&&wrong<.5)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.5&&wrong<.6)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|                |");
                        printf("\n|                |");
                        printf("\n|                |");
                        printf("\n|                |");
                        printf("\n|                b");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|                |");
                        fprintf(disp,"\n|                |");
                        fprintf(disp,"\n|                |");
                        fprintf(disp,"\n|                |");
                        fprintf(disp,"\n|                b");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.6&&wrong<.7)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |   |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                b       b");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                b       b");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.7&&wrong<.8)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |o  |");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                b       b");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |o  |");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                b       b");
                        fprintf(disp,"\n|");

                    }
                else if (wrong>=.8&&wrong<1.0)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |o o|");
                        printf("\n|                  |   |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | |       | |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                b       b");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |o o|");
                        fprintf(disp,"\n|                  |   |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                b       b");
                        fprintf(disp,"\n|");

                    }
                else if (wrong==1.0)
                    {
                        printf("\n|--------------------|");
                        printf("\n|                    |");
                        printf("\n|                  |o o|");
                        printf("\n|                  | Q |");
                        printf("\n|                    |");
                        printf("\n|              |-|-------|-|");
                        printf("\n|              | | Y o u | |");
                        printf("\n|              | |       | |");
                        printf("\n|              | | Lose..| |");
                        printf("\n|              m |       | m");
                        printf("\n|                 -------   ");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                |       |");
                        printf("\n|                b       b");
                        printf("\n|");

                        fprintf(disp,"\n|--------------------|");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|                  |x x|");
                        fprintf(disp,"\n|                  | o |");
                        fprintf(disp,"\n|                    |");
                        fprintf(disp,"\n|              |-|-------|-|");
                        fprintf(disp,"\n|              | | Y O U | |");
                        fprintf(disp,"\n|              | |       | |");
                        fprintf(disp,"\n|              | | LOST..| |");
                        fprintf(disp,"\n|              m |       | m");
                        fprintf(disp,"\n|                 -------   ");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                |       |");
                        fprintf(disp,"\n|                b       b");
                        fprintf(disp,"\n|");
                    }
    }
