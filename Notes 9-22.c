/*Justin Newman
ECE270 9/22/14
Notes*/


//rand() review

int r;
r=1+rand()%100;
//range from 1-100

//rand 3->10
r=3+rand()%8

float f;
f=(float)rand()/(float)RAND_MAX;


if statement


//////////////
//compute d

if (d==0) //repeated roots

if (d>0) //real roots
 
if (d<0) //complex roots


//nested if statements
scanf ("\n%d",&grade);
if (grade<100)

/*for quiz 3 print output to a file:

WRITE	TO	FILE

main()
	{
		FILE *fp; //file pointer variable
		fp=fopen("data.txt","w");
		fprintf(fp,"n:%d",n);
		fclose(fp);
		
	}


QUIZ 3

for loop
int i;
for(i=0;i<10;i++)


use while for when you don't know in advance how many time you need to loop

flag variable - is used wto indicate when a condition is met
counter variable - is used to keep track of a count