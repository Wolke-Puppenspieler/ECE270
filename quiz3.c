/*Justin Newman
ECE270 9/19/14
Quiz #3:
Quadratic Equation Solver*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
	{
		double discriminant, varA, varB, varC;

		FILE *fp;
		fp=fopen("quiz3.txt","w");

        //All screen output lines are followed by a matching line that prints output to quiz3.txt
		printf("ECE270 Quiz 3, Quadratic Equation Solver");
		fprintf(fp,"ECE270 Quiz 3, Quadratic Equation Solver");

		printf("\nThis progam will solve quadratic equations of the type ax^2+bx+c");
        fprintf(fp,"\nThis progam will solve quadratic equations of the type ax^2+bx+c");

		printf("\n\nPlease enter the value of a:");
		scanf("\n%lf",&varA);
		fprintf(fp,"\n\nPlease enter the value of a:%f",varA);

		printf("\n\nPlease enter the value of b:");
		scanf("\n%lf",&varB);
		fprintf(fp,"\n\nPlease enter the value of b:%f",varB);

		printf("\n\nPlease enter the value of c:");
		scanf("\n%lf",&varC);
		fprintf(fp,"\n\nPlease enter the value of C:%f",varC);

		discriminant=varB*varB-4*varA*varC;



            //Based on value of discriminant, determines type of solution and which operations to perform
            if(discriminant>0)
                {
                //If the solutions are real roots:
                    double answer1, answer2;

                    discriminant=sqrt(discriminant);

                    answer1=(-varB+discriminant)/(2*varA);
                    answer2=(-varB-discriminant)/(2*varA);

                    printf("\n\nReal Roots - Answers:\t%.2f & %.2f",answer1,answer2);
                    fprintf(fp,"\n\nReal Roots - Answers:\t%.2f & %.2f",answer1,answer2);

                }

			else if(discriminant<0)
                {
                //If the solutions are complex roots:
                    double realPart, imagPart;

                    realPart=-varB/(2*varA);
                    imagPart=sqrt(-discriminant)/(2*varA);

                    printf("\n\nComplex Roots - Answers:\t%.2f + j%.2f & %.2f - j%.2f",realPart,imagPart,realPart,imagPart);
                    fprintf(fp,"\n\nComplex Roots - Answers:\t%.2f + j%.2f & %.2f -j%.2f",realPart,imagPart,realPart,imagPart);

                }
                else
                {
                //If the discriminant is 0, we have a single solution:
                    double answer;

                    answer=-varB/(2*varA);

                    printf("\n\nRepeated Roots - Answer:\t%.2f",answer);
                    fprintf(fp,"\n\nRepeated Roots - Answer:\t%.2f",answer);

                }

		fclose(fp);
        return 0;

	}

