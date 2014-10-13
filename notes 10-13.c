/*Justin Newman
ECE270 10/13/14
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void setupRandArray(int , int[], int , int );
int getMax(int , int []);
void printArray(int , int [], char []);

int main()
{
	srand(time(NULL));
	
	int maxVal, minVal, i, max;
	
	printf("please eenter your desired array size: ");
	scanf("\n%d",&i);
	int randNumArray[i];
	printf("\nPlease enter the desired maximum number to be generated");
	scanf("\n&d",&maxVal);
	printf("\nPlease enter the desired minimum number to be generated");
	scanf("\n%d",&minVal);
	
	setupRandArray(i, randNumArray,maxVal,minVal);
	
	getMax(i, randNumArray);
	
	printArray(i, randNumArray, "Values");
	
	
	/*for(i=0;i<19;i++) //becomes setupRandArray function
	{
		randNumArray[i]=(rand()%201)-100;
	}*/
	
	/*max=randNumArray[0];  //becomes getMax function
	for(i=0;i<19;i++)
	{
		if(randNumArray[i]>max)
		{
			max=randNumArray[i];
		}
	}*/
	
	printf("the largest number generated is %d",max);
	
	return 0;
}

void setupRandArray(int n, int randNumArray[],int max,int min)
{
	int i;
	for(i=0;i<n;i++)
	{
		randNumArray[i]=(rand()%(max-min+1)-min;
	}
}
int getMax(int n, int randNumArray[])
{
	max=randNumArray[0];
	for(i=0;i<n;i++)
	{
		if(randNumArray[i]>max)
		{
			max=randNumArray[i];
		}
	}
return max;
	}
	
void printArray(int n, int randNumArray[], char label[]);
{
	int i;
	printf("%s:",label);
	for(i=0;i<n;i++)
	{
		printf("%d",randNumArray[i]);
		