/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include <iostream>
#include "./quiz17.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;

FILE *svg;
FILE *output;


Fill::Fill(int r_in, int g_in, int b_in, float a_in)
{
	red=r_in;
	green=g_in;
	blue=b_in;
	opacity=a_in;
}

Fill::Fill()
{
    cout << "\nPlease enter the desired amount of red for your shape's fill color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",red);

    cout << "\nPlease enter the desired amount of green for your shape's fill color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's fill color (0-255): %d",green);

    cout << "\nPlease enter the desired amount of blue for your shape's fill color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",blue);

    cout << "\nPlease enter the desired opacity of your shape's fill color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's fill color (0.0-1.0): %f",opacity);
}
void Fill::setFill()
{
    cout << "\nPlease enter the desired amount of red for your shape's fill color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",red);

    cout << "\nPlease enter the desired amount of green for your shape's fill color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's fill color (0-255): %d",green);

    cout << "\nPlease enter the desired amount of blue for your shape's fill color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",blue);

    cout << "\nPlease enter the desired opacity of your shape's fill color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's fill color (0.0-1.0): %f",opacity);
}

void Fill::setFill(int r_in, int g_in, int b_in, float a_in)
{
    red=r_in;
    green=g_in;
    blue=b_in;
    opacity=a_in;
}

Stroke::Stroke(int r_in, int g_in, int b_in, float a_in, int width_in)
{
	red=r_in;
	green=g_in;
	blue=b_in;
	opacity=a_in;
	width=width_in;
}

Stroke::Stroke()
{
    cout << "\nPlease enter the desired amount of red for your shape's Stroke color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",red);

    cout << "\nPlease enter the desired amount of green for your shape's Stroke color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's Stroke color (0-255): %d",green);

    cout << "\nPlease enter the desired amount of blue for your shape's Stroke color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",blue);

    cout << "\nPlease enter the desired opacity of your shape's Stroke color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's Stroke color (0.0-1.0): %.2f",opacity);

	cout << "\nPlease enter the desired width of your shape's Stroke";
    cin >> width;
    fprintf(output,"\nPlease enter the desired width of shape's Stroke: %d",width);
}

void Stroke::setStroke()
{
    cout << "\nPlease enter the desired amount of red for your shape's Stroke color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",red);

    cout << "\nPlease enter the desired amount of green for your shape's Stroke color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's Stroke color (0-255): %d",green);

    cout << "\nPlease enter the desired amount of blue for your shape's Stroke color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",blue);

    cout << "\nPlease enter the desired opacity of your shape's Stroke color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's Stroke color (0.0-1.0): %.2f",opacity);

	cout << "\nPlease enter the desired width of your shape's Stroke";
    cin >> width;
    fprintf(output,"\nPlease enter the desired width of shape's Stroke: %d",width);
}

void Stroke::setStroke(int r_in, int g_in, int b_in, float a_in, int width_in)
{
	red=r_in;
	green=g_in;
	blue=b_in;
	opacity=a_in;
	width=width_in;
}

Line::Line(float x1_in, float y1_in, float x2_in, float y2_in)
{
	x1=x1_in;
	y1=y1_in;
	x2=x2_in;
	y2=y2_in;
}

Line::Line()
{
	cout << "\nPlease enter the starting x-coordinate of your line";
    cin >> x1;
    fprintf(output,"\nPlease enter the starting x-coordinate of your line: %.2f",x1);

    cout << "\nPlease enter the starting y-coordinate of your line";
    cin >> y1;
    fprintf(output,"\nPlease enter the starting y-coordinate of your line: %.2f",y1);

    cout << "\nPlease enter the ending x-coordinate of your line";
	cin >> x2;
    fprintf(output,"\nPlease enter the ending x-coordinate of your line: %.2f",x2);

    cout << "\nPlease enter the ending y-coordinate of your line";
    cin >> y2;
    fprintf(output,"\nPlease enter the ending y-coordinate of your line: %.2f",y2);

    system("cls");
}

void Line::display()
{
	cout << "\nx1:" << x1;
	cout << "\ny1:" << y1;
	cout << "\nx2:" << x2;
	cout << "\ny2:" << y2;
}

void Line::setLine()
{
	cout <<"\nPlease enter the starting x-coordinate of your line";
    cin >> x1;
    fprintf(output,"\nPlease enter the starting x-coordinate of your line: %.2f",x1);

    cout << "\nPlease enter the starting y-coordinate of your line";
    cin >> y1;
    fprintf(output,"\nPlease enter the starting y-coordinate of your line: %.2f",y1);

    cout <<"\nPlease enter the ending x-coordinate of your line";
	cin >> x2;
    fprintf(output,"\nPlease enter the ending x-coordinate of your line: %.2f",x2);

    cout << "\nPlease enter the ending y-coordinate of your line";
    cin >> y2;
    fprintf(output,"\nPlease enter the ending y-coordinate of your line: %.2f",y2);

    system("cls");
}

void Line::setStart(float x1_in, float y1_in)
{
	x1=x1_in;
	y1=y1_in;

}

void Line::setEnd(float x2_in, float y2_in)
{
	x2=x2_in;
	y2=y2_in;
}

void Line::drawLine(Stroke stroke)
{
	fprintf(svg,"\n    <line x1 = '%f' y1 = '%f' x2 = '%f' y2 = '%f'", x1, y1, x2, y2);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}

Circle::Circle(float cx_in, float cy_in, float r_in)
{
	cx=cx_in;
	cy=cy_in;
	r=r_in;
}

Circle::Circle()
{
	cout <<"\nPlease enter the center x-coordinate of your circle";
    cin >> cx;
    fprintf(output,"\nPlease enter the center x-coordinate of your circle: %.2f",cx);

    cout << "\nPlease enter the center y-coordinate of your circle";
    cin >> cy;
    fprintf(output,"\nPlease enter the center y-coordinate of your circle: %.2f",cy);

    cout <<"\nPlease enter the radius of your circle";
	cin >> r;
    fprintf(output,"\nPlease enter the radius of your circle: %.2f",r);

    system("cls");
}

void Circle::display()
{
	cout << "\ncx:" << cx;
	cout << "\ncy:" << cy;
	cout << "\nr:" << r;
}

void Circle::setCircle()
{
	cout <<"\nPlease enter the center x-coordinate of your circle";
    cin >> cx;
    fprintf(output,"\nPlease enter the center x-coordinate of your circle: %.2f",cx);

    cout << "\nPlease enter the center y-coordinate of your circle";
    cin >> cy;
    fprintf(output,"\nPlease enter the center y-coordinate of your circle: %.2f",cy);

    cout <<"\nPlease enter the radius of your circle";
	cin >> r;
    fprintf(output,"\nPlease enter the radius of your circle: %.2f",r);

    system("cls");
}

void Circle::setCenter(float cx_in, float cy_in)
{
	cx=cx_in;
	cy=cy_in;
}

void Circle::setRadius(float r_in)
{
	r=r_in;
}

void Circle::drawCircle(Fill fill,Stroke stroke)
{
	fprintf(svg,"\n    <circle cx = '%f' cy = '%f' r = '%f'", cx, cy, r);
    fprintf(svg," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}

Rectangle::Rectangle(float x_in, float y_in, float width_in, float height_in)
{
	xCorner=x_in;
	yCorner=y_in;
	width=width_in;
	height=height_in;
}

Rectangle::Rectangle()
{
	cout <<"\nPlease enter the x-coordinate for the upper left corner of your Rectangle";
    cin >> xCorner;
    fprintf(output,"\nPlease enter the x-coordinate for the upper left corner of your Rectangle: %.2f",xCorner);

    cout << "\nPlease enter the y-coordinate for the upper left corner of your Rectangle";
    cin >> yCorner;
    fprintf(output,"\nPlease enter the y-coordinate for the upper left corner of your Rectangle: %.2f",yCorner);

    cout <<"\nPlease enter the width of your Rectangle";
	cin >> width;
    fprintf(output,"\nPlease enter the width of your Rectangle: %.2f",width);

    cout << "\nPlease enter the height of your Rectangle";
    cin >> height;
    fprintf(output,"\nPlease enter the height of your Rectangle: %.2f",height);

    system("cls");
}

void Rectangle::display()
{
	cout << "\nx corner:" << xCorner;
	cout << "\ny corner:" << yCorner;
	cout << "\nwidth:" << width;
	cout << "\nheight:" << height;
}

void Rectangle::setRect()
{
	cout <<"\nPlease enter the x-coordinate for the upper left corner of your Rectangle";
    cin >> xCorner;
    fprintf(output,"\nPlease enter the x-coordinate for the upper left corner of your Rectangle: %.2f",xCorner);

    cout << "\nPlease enter the y-coordinate for the upper left corner of your Rectangle";
    cin >> yCorner;
    fprintf(output,"\nPlease enter the y-coordinate for the upper left corner of your Rectangle: %.2f",yCorner);

    cout <<"\nPlease enter the width of your Rectangle";
	cin >> width;
    fprintf(output,"\nPlease enter the width of your Rectangle: %.2f",width);

    cout << "\nPlease enter the height of your Rectangle";
    cin >> height;
    fprintf(output,"\nPlease enter the height of your Rectangle: %.2f",height);

    system("cls");
}

void Rectangle::setCorner(float x_in, float y_in)
{
	xCorner=x_in;
	yCorner=y_in;
}

void Rectangle::setDimensions(float width_in, float height_in)
{
	width=width_in;
	height=height_in;
}

void Rectangle::drawRect(Fill fill,Stroke stroke)
{
	fprintf(svg,"\n    <rect x = '%f' y = '%f' width = '%f' height = '%f'", xCorner, yCorner, width, height);
    fprintf(svg," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}

Path::Path(int n_in, float *x_in, float *y_in)
{
	n=n_in;
	x=x_in;
	y=y_in;
	x=(float*)calloc(n_in,sizeof(float));
	y=(float*)calloc(n_in,sizeof(float));
}

Path::Path()
{
	int i;

	cout << "\nPlease enter the number of points in your path";
    cin >> n;
	fprintf(output,"\nPlease enter the number of points in your Path: %d",n);

	x=(float*)calloc(n,sizeof(float));
	y=(float*)calloc(n,sizeof(float));

	for(i=0;i<n;i++)
	{
		cout <<"\nPlease enter the x-coordinate for point #" << i << " of your path\n";
		cin >> x[i];
		fprintf(output,"\nPlease enter the x-coordinate for point #%d of your Path: %.2f",i,x[i]);

		cout <<"\nPlease enter the y-coordinate for point #" << i << " of your path\n";
		cin >> y[i];
		fprintf(output,"\nPlease enter the y-coordinate for point #%d of your Path: %.2f",i,y[i]);
	}

    system("cls");
}

void Path::display()
{
    int i;
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

	x=(float*)calloc(n,sizeof(float));
	y=(float*)calloc(n,sizeof(float));

	for(i=0;i<n;i++)
	{
		cout <<"\nPlease enter the x-coordinate for point #" << i << " of your path\n";
		cin >> x[i];
		fprintf(output,"\nPlease enter the x-coordinate for point #%d of your Path: %.2f",i,x[i]);

		cout <<"\nPlease enter the y-coordinate for point #" << i << " of your path\n";
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

    fprintf(svg,"\n    <path d ='M%f %f ", x[0], y[0]);

    for(i=1;i<n;i++)
    {
        fprintf(svg,"L%f %f ", x[i], y[i]);
    }

    fprintf(svg,"z' fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}
