/*Justin Newman
Quiz 17 ECE270
11/24/14*/
#include<stdio.h>
#include <iostream>
using namespace std;

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

    cout << "\nPlease enter the height of your Rectangle");
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

    cout << "\nPlease enter the height of your Rectangle");
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
	fprintf(fp,"\n    <rect x = '%f' y = '%f' width = '%f' height = '%f'", xCorner, yCorner, width, height);
    fprintf(fp," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}
