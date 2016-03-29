/*character matricies
to be or not to be //poem[0]
that is the question //poem[1]
whether 'tis nobler to... //poem[2]
*/
#define MAX_NUM_LINES 100
#define MAX_STR_LEN 501
/*
Int main()
{
	int i,j;
	char poem[MAX_NUM_LINES][MAX_STR_LEN];
	strcpy(poem[0],"to be or not to be");
	strcpy(poem[1],"that is the question");
	strcpy(poem[2],"whether 'tis nobler to...");
	int numLines=3;
	for(i=0;i<numLines;i++)
	{
		printf("\nLine %d: %s",i+1,poem[i]);
	}
	
*/

char poem[MAX_NUM_LINES][MAX_STR_LEN];
int count, readflag,k;
fp=fopen("poem.txt","r");
count=0;
readFlag=1;
while(readFlag==1)
{
	k=fgets(poem[count],MAX_STR_LEN,fp);
}
while(readFlag==1)
{
		k=fgets(poem[count],MAX_STR_LEN,fp);
		if (k==EOF)
		{
			readFlag=0;
		}
		else
		{
			count+=1;
		)
}
}