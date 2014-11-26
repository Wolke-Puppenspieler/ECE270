/*Justin Newman
Quiz 17 ECE270
11/24/14*/
#include <iostream>
#include "./quiz17.h"

using namespace std;

Path::Path(int n_in, float *x_in, float *y_in)
{
	n=n_in;
	x=x_in;
	y=y_in;
	x=(float*)calloc(n_in*sizeof(float));
	y=(float*)calloc(n_in*sizeof(float));
}

Path::Path()
{
	int i;

	cout << "\nPlease enter the number of points in your path";
    cin >> n;
	fprintf(output,"\nPlease enter the number of points in your Path: %d",n);

	x=(float*)calloc(n*sizeof(float));
	y=(float*)calloc(n*sizeof(float));

	for(i=0;i<n;i++)
	{
		cout <<"\nPlease enter the x-coordinate for point #" << i << " of your path";
		cin >> x[i];
		fprintf(output,"\nPlease enter the x-coordinate for point #%d of your Path: %.2f",i,x[i]);

		cout <<"\nPlease enter the y-coordinate for point #" << i << " of your path";
		cin >> y[i];
		fprintf(output,"\nPlease enter the y-coordinate for point #%d of your Path: %.2f",i,y[i]);
	}

    system("cls");
}

void Path::display();
{
	for(i=0;i<n;i++)
	{
		cout <<"\nThe x-coordinate for point #" << i << " of your path is:" << x[i];
		fprintf(output,"\nThe x-coordinate for point #%d of your Path is: %.2f",i,x[i]);

		cout <<"\nThe y-coordinate for point #" << i << " of your path is" << y[i];
		fprintf(output,"\nThe y-coordinate for point #%d of your Path is: %.2f",i,y[i]);
	}
}

void Path::setPath()
{
	int i;

	cout << "\nPlease enter the number of points in your path";
    cin >> n;
	fprintf(output,"\nPlease enter the number of points in your Path: %d",n);

	x=(float*)calloc(n*sizeof(float));
	y=(float*)calloc(n*sizeof(float));

	for(i=0;i<n;i++)
	{
		cout <<"\nPlease enter the x-coordinate for point #" << i << " of your path";
		cin >> x[i];
		fprintf(output,"\nPlease enter the x-coordinate for point #%d of your Path: %.2f",i,x[i]);

		cout <<"\nPlease enter the y-coordinate for point #" << i << " of your path";
		cin >> y[i];
		fprintf(output,"\nPlease enter the y-coordinate for point #%d of your Path: %.2f",i,y[i]);
	}

    system("cls");
}

void Path::setPoint(int n_in, float x_in, float y_in)
{
	x[n]=x_in;
	y[n]=y_in;
}

void Path::drawPath(Fill fill,Stroke stroke)
{
	int i;

    fprintf(fp,"\n    <path d ='M%f %f ", x[0], y[0]);

    for(i=1;i<n;i++)
    {
        fprintf(fp,"L%f %f ", x[i], y[i]);
    }

    fprintf(fp,"z' fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}
