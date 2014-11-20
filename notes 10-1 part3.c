#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
	{
		srand(time(NULL));
		
		int grades[20], i=0;
		
		for (i=0;i<20;i++)
			{
				grades[i]=rand()%101;
			}
		
		i=0;
			
		for (i=0;i<20;i++)
			{
				if (i%5==0)
					{
						printf("\n");
					}
				printf("%3d",grades[i]);
			}
	
	return 0;
	}