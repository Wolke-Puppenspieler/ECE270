/*Justin Newman
ECE270 10/15/14
Notes*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
	


float cx[200], cy[200], r[200];
int i, j, k, n, numIntersect;

	cx[0]]=imageWidth/2;
	cy[0]=imageHeight/2;
	r[0]=20.0*rand_float();
	n=1;

for(i=0;i<200;i++)
{
	candidate_x=1000.0*rand_float();
	candidate_y=1000.0*rand_float();
	candidate_r=50.0*rand_float();

	for(j=0;j<n;j++)
	{
		numIntersect+=circleIntersect(cx[j],cy[j],r[j],candidate_x,candidate_y,candidate_r);
	}
	
	if(numIntersect==0)
	{
		cx[n]=candidate_x;
		cy[n]=candidate_y;
		r[n]=candidate_r;
		n++;
	}


for(k=0;k<n;k++0
{
		
		setStroke(0,0,0,1.0,1);
		setFill(rand()%256,rand()%256
		drawCircle(ck[k],cy[k],r[k]);
		

}
//check to see if it intersects
//if not - put candidate in array

n++;

//loop	
	
}

