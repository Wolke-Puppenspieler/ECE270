#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
	{
		FILE *fp;
		fp=fopen("data.txt","w");
		
		float a,b,c;
		
		printf("\nPlease enter a:");
		scanf("\n%f",&a);
		
		fprintf(fp,"Please enter A:%f",a);
		
		fclose(fp);
		
		return 0;
		
	}