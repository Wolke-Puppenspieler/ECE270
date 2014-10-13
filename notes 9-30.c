applications of loops:
computing sequences
counting
computing sums
I/O

exercise

int i=0;

for (i=0;i<15;i++)
	{
		printf("\nx[%d: %d]",i,i);
	}
	
//store these grades and count # of A grades
int grades[7]={72,81,97,52,90,100,85}, count=0, i=0;

for (i=1;i<7;i++)
	{
		if (grades[i]>=90)
			{
				count++;
			}
	}
return 0;