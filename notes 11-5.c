

// *(A+i*m+j) for matrix pointer
//char *poem[{MAX_NUM_LINES] - requires malloc for every line
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAX_NUM_LINES 100
#define MAX_STR_LEN 501

int main();
{
	char poem[MAX_NUM_LINES][MAX_STR_LEN];
	int i,j,n,numlines;
	strcpy(poem[0],"To be or not to be");
	strcpy(poem[1],"That is the Question");
	strcpy(poem[2],"Whether 'tis Nobler");
	
	for(i=0;i<numLines;i++)
	{
		n=strlen(poem[i]);
		printf("\nLine %d: ",i+1);
		for j=0;j<n;j++)
		{
			printf("%c",poem[i][j]);
		}
	}

		FILE *fp;
		//char str[MAX_STR_LEN];
		char poem[10][MAX_STR_LEN];
		fp=fopen("poem.txt","r");
		//fgets(str,MAX_STR_LEN,fp);
		for(i=0;i<10;i++)
		{
			fgets(poem[i],MAX_STR_LEN,fp);
		}
		
	
	
	
}

/*
read from file: fscanf
Note: fscanf returns EOF if no more data in file (EndOfFile)
otherwise returns #of items read in
ex: data.txt - 500 p

main()
{
	FILE *fp;
	int x;
	char c;
	fp=fopen("data.txt","r");
	fscanf(fp,"%d","%d",&x,&c);
	fclose(fp);
}


when using fscanf and scanf with strings, it will stop at first space or newline

fgets(char str[], int n, FILE*stream);
here: n is max #of characters to read in(should include \0)
can us stdin to read from keyboard or file pointer to read from a file
*/
/*
char str{MAX_STR_LEN];
fp=fopen("poem.txt","r");
fgets(str,MAX_STR_LEN,fp);
*/
