int main()
{
	char dnaArray[101], bases[]={'A','C','G','T'};
	int i, counts[4];
	setupRandDNASeq(100,dnaArray);
	
	printf("DNA: %s",dnaArray);
	for(i=0;i<4;i++)
	{
		counts[i]=getBaseCount(bases[i],dnaArray);
	}
	return 0;
}

void setupRandDNASeq(int n, char dnaStr[])
{
	int i,k;
	char bases[5]={'A','T','C','G'};
	
	for(i=0;i<n;i++)
	{
		k=rand()%4;
		dnaStr[i]=bases[k];
		
	}
	dnaStr[n]='\0';
}
int getBaseCount(char base, char dnaStr[])
{
	int i, count=0;
	for(i=0;i<strlen(dnaStr);i++)
	{
		if(dnaStr[i]==base)
		{
			count++;
		}
	}
	return(count);
}