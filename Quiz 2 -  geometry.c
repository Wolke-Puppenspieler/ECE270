/*Justin Newman
ECE270 9/10/14
Quiz #2*/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415926535897932384626433832795

void menu();
void circle();
void triangle();
void sphere();

int main()
	{

		char selection;

        //Call menu function
		menu();

        //Loop for allowing use of all three functions of the program without restarting
        do
			{

				scanf("\n%c",&selection);

				switch(selection)
					{
					case 'T':case 't':
						system("cls");
						triangle();
						menu();
					break;
					case 'C':case 'c':
						system("cls");
                        circle();
                        menu();
					break;
					case 'S':case 's':
						system("cls");
						sphere();
						menu();
					break;
					case 'Q':case 'q':
						system("cls");
						printf("\nProgram terminating...\ngoodbye");
					break;
					default :
						system("cls");
						printf("\nPlease make a valid selection from the following menu:\n");
						menu();
					}

			}while(selection!='Q'||selection!='q');


    return 0;

	}

void menu()
	{
	    //Displays function selection menu
		printf("\nWelcome to Justin Newman's ECE270 Quiz #2 geometry program");
		printf("\n\nPlease make your selection from the following menu:");
		printf("\n\nT:\tCalculate area of a triangle");
		printf("\nC:\tCalculate area, diameter, and perimeter of a circle");
		printf("\nS:\tCalculate volume of a sphere");
		printf("\nQ:\tTo quit");
		printf("\n\nPlease enter your selection now:");
	}

void circle()
	{

        //Define vars
		float radius=0;

		printf("\nJustin Newman's Circle Calculator!!");

		//Get input
		printf("\n\nPlease enter the radius of your circle");
		scanf("\n%f",&radius);

		//Efficient code for calculating and printing the desired quantities
		printf("\nThe area of your circle is: \t\t%.2f\nThe diameter of your circle is:\t\t %.2f\nThe perimeter of your circle is:\t %.2f",PI*(radius)*(radius),2*radius,2*PI*radius);
		printf("\n\nPress any key to return to the selection screen");

		//Hold for user input
		getch();

		//Clear screen
        system("cls");

	}

void triangle()
	{

        //Define vars
		float base=0, height=0;

		printf("\nJustin Newman's Triangle Calculator!!");

		//Get input
		printf("\n\nPlease enter the base of your triangle");
		scanf("\n%f",&base);
		printf("\nPlease enter the height of your triangle");
		scanf("\n%f",&height);

        //Efficient code for calculating and printing the desired quantities
		printf("\n\The area of your triangle is %.2f",.5*base*height);
		printf("\n\nPress any key to return to the selection screen");

		//Hold for user input
		getch();

		//Clear screen
		system("cls");

	}

void sphere()
	{
        //Define vars
		float radius=0;

		printf("\nJustin Newman's Sphere calculator!!");

		//Get input
		printf("\n\nPlease enter the radius of your sphere");
		scanf("\n%f",&radius);

        //Efficient code for calculating and printing the desired quantities
		printf("\n\nThe volume of your sphere is %.2f",4*PI*(radius*radius*radius)/3);
		printf("\n\nPress any key to return to the selection screen");

		//Hold for user input
		getch();

		//Clear screen
		system("cls");

	}
