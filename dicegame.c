/*Dice game*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
	{
		int diceRoll,isPlaying,rolls;
		srand(time(NULL));




		do
			{
				diceRoll=1+rand()%6;
				if (diceRoll==6)
					{
						printf("CONGRATULATIONS! Your roll of 5 wins you $50!");
					}
				else
					{
						printf("you lose");
					}

				printf("Roll again?");


			}while(isPlaying==1);
