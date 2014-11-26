/*Justin Newman
Quiz 17 ECE270
11/24/14*/

#include <iostream>
#include <stdio.h>
#include "./quiz17.h"

using namespace std;

Line::Line(float x1_in, float y1_in, float x2_in, float y2_in)
{
    FILE *svg;
    FILE *output;
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

void Line::drawLine(Fill fill,Stroke stroke)
{
	fprintf(svg,"\n    <line x1 = '%f' y1 = '%f' x2 = '%f' y2 = '%f'", x1, y1, x2, y2);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}
