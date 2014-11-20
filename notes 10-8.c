/*Justin  Newman
ECE270 notes
10/8/14
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int numGrades(int [], int , int , int ); 

int main()
{
/*
steps for plotting y=2^x
1) choose plot parameters - xmin xmax step size (delta-x)
2) construct sequence of samples of the x-axis from xmin-xmax in steps of delta-x X: xmin, xmin+delta-x,xmin+2delta-x,...,xmax
3) for each x-sample, evaulate the function. eg:yi=f(xi), i=0,1,...n-1 //create table of x values and corresponding y values
4) plot each sample point (xi,yi) in the plane
5) connect dots (interpolate between sample points)
6) lable axes

note: sampling is incredible, because the incredible amount of data reduction


-3,3  step size of .01 = 600 samples
float X[601], y[601], xMin=3.0, xMax=3.0, step=0.01;
 int i =(int)(xMax-xMin)/step+1;
 
 for (i=0;i<n;i++)
 {
 	x[i]=-xMin+step*(float)i;
	 y[i]=pow(2.0,x[i]); 
 }
*/ 

	int i, grades[8]={82,71,94,61,100,75}, int numOfGrades[5], min, max;
	
	printf("grade counter\nEnter the minimum percentage you want to count: ");
	scanf("\n%d",&min);
	printf("\nEnter the maximum percentage you want to count: ");
	scanf("\n%d",&max);
	int aGrades[8];
	for(i=0;i<5;i++)
	{
		numOfGrades[i]=numGrades(grades,8,90,100);
	
		if(grades[i]>=90)
		{
			aGrades[i]=grades[i];
		}
		
	
	
	
	
	
	
	
	//aGrades=numGrades(grades,8,90,100);
	//bGrades=numGrades(grades,8,80,89);
	//cGrades=numGrades(grades,8,70,79);
	//dGrades=numGrades(grades,8,60,69);
	//eGrades=numGrades(grades,8,0,50);
	}

return 0;
}

int numGrades(int gradeArray[], int n, int minGrade, int maxGrade)
{
		int count=0;
		for(i=0;i<8;i++)
	{
		if ((gradeArray[i]>=minGrade)&&(gradeArray[i]<=maxGrade))
		{
			count=count+1;
		}
	}
	
return(count);
}