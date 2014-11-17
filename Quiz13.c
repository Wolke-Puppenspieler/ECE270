#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct cd{
	char artistName[];
	char albumName[];
	int year;
	char genre[];
	float rating;
	char studentName[];
};
char parseEntry(FILE *,int ,int );
int main()
{
	int x;
	struct cd cdList[200];
	FILE *fp;
	fp=fopen("MasterCDList.txt","r");
	fgets(char 
	for(i=0;i<numLines;i++)
	{
		for(j=0;j<6;j++)
		{
			switch(j)
			{
				case 0:
					strcpy(parseEntry(fp,j,i),cdList[i].artistName);
				break;
				case 1:
					strcpy(parseEntry(fp,j,i),cdList[i].albumName);
				break;
				case 2:
					cdList[i].year=(int)parseEntry(fp,j,i);
				break;
				case 3:
					strcpy(parseEntry(fp,j,i),cdList[i].genre);
				break;
				case 4:
					cdList[i].rating=(float)parseEntry(fp,j,i);
				break;
				case 5:
					strcpy(parseEntry(fp,j,i),cdList[i].studentName);
				break ;
				
				
				
				
//for(i=0;i<n;i++) where n is number of lines to skip
					
					
					
					
					
					
					
					
					
					
					
//write function to skip number of commas passed in: eg. n=0 would return 1st entry in line, n=1 would skip up to 1st comma and read next entry
