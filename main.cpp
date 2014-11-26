#include <iostream>
#include <cstdlib>
#include "./quiz17.h"
#include "./quiz17-implementation.cpp"

char fileName[] = "image.svg";
int imWidth = 1000;  //image width (total)
int imHeight = 1000; //image height (total)

void writeSVGHeader(char [], int , int );
void writeSVGFooter();
void menu();
void draw();

using namespace std;

int main()
{
    output=fopen("quiz17.txt","w");

    writeSVGHeader(fileName, imWidth, imHeight);

    draw();

    writeSVGFooter();

    return 0;
}

void writeSVGHeader(char fileName[], int width, int height)
{
    //Open file for writing
    svg = fopen(fileName,"w");

    //Setup SVG header
    fprintf(svg,"<?xml version='1.0' standalone='no'?>");
    fprintf(svg,"\n<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' version='1.1' width = '%d' height = '%d'>", width, height);
}

void writeSVGFooter()
{
    //Closing SVG tag and close file
    fprintf(svg,"\n</svg>");
    fclose(svg);
}

void draw()
{
	Line line(0,0,0,0);
	Circle circle(0,0,0);
	Rectangle rect(0,0,0,0);
	Stroke stroke(0,0,0,0,0);
	Fill fill(0,0,0,0);
	Path path(0,0,0);
	char selection=0;

	menu();

	do
    {
		cin >> selection;

		switch(selection)
		{
			case 'L':case 'l':
				system("cls");
                stroke.setStroke();
				line.setLine();
				line.drawLine(stroke);
				menu();
			break;
			case 'C':case 'c':
				system("cls");
				fill.setFill();
                stroke.setStroke();
				circle.setCircle();
                circle.drawCircle(fill,stroke);
                menu();
			break;
			case 'R':case 'r':
				system("cls");
                fill.setFill();
                stroke.setStroke();
				rect.setRect();
				rect.drawRect(fill,stroke);
				menu();
			break;
			case 'P':case 'p':
				system("cls");
				fill.setFill();
                stroke.setStroke();
                path.setPath();
                path.drawPath(fill,stroke);
                menu();
			break;
			case 'Q':case 'q':
				system("cls");
				cout << "\nProgram terminating...\nenjoy your drawing";
				fprintf(output,"\nProgram terminating...\nenjoy your drawing");

				cout << "\nYour drawing can be found in image.svg in the same folder as this program";
				fprintf(output,"\nYour drawing can be found in image.svg in the same folder as this program");
			break;
			default :
				system("cls");
				cout << "\nPlease make a valid selection from the following menu:\n";
				fprintf(output,"\nPlease make a valid selection from the following menu:\n");
				menu();
			}
	}while(selection!='Q'&&selection!='q');
}

void menu()
{
    cout << "\nWelcome to Justin Newman's ECE270 Quiz #17 C++ SVG drawing program";
    fprintf(output,"\nWelcome to Justin Newman's ECE270 Quiz #15 SVG drawing program");

    cout << "\n\nPlease make your selection from the following menu:";
    fprintf(output,"\n\nPlease make your selection from the following menu:");

    cout << "\n\nL:\tDraw a line";
    fprintf(output,"\n\nL:\tDraw a line");

    cout << "\nC:\tDraw a circle";
    fprintf(output,"\nC:\tDraw a circle");

    cout << "\nR:\tDraw a rectangle";
    fprintf(output,"\nR:\tDraw a rectangle");

    cout << "\nP:\tDefine your own shape";
    fprintf(output,"\nP:\tDefine your own shape");

    cout << "\nQ:\tTo stop drawing";
    fprintf(output,"\nQ:\tTo stop drawing");

    cout << "\n\nPlease enter your selection now:";
    fprintf(output,"\n\nPlease enter your selection now:");
}
