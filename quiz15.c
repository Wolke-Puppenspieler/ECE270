#include<stdio.h>
#include<stdlib.h>

//START snippet of SVG code on canvas
//Global Variables ............................
FILE *fp;            //File pointer for svg image

char fileName[] = "image.svg";

int imWidth = 1000;  //image width (total)
int imHeight = 1000; //image height (total)
//..............................................
//END snippet of SVG code from canvas

struct Line{
	float x1; //x-coord of line start
	float y1; //y-coord of line start
	float x2; //x-coord of line end
	float y2; //y-coord of line end
};

struct Circle{
	float cx; //center x-coordinate
	float cy; //center y-coordinate
	float r;  //radius
};

struct Rectangle{
	float xCorner; //x-coord of upper-left corner of rectangle
	float yCorner; //y-coord of upper-left corner of rectangle
	float width;   //horizontal size of rectangle
	float height;  //vertical size of rectangle
};

struct Fill{
	int red;   //set red tone 0-255
	int green; //set green tone 0-255
	int blue;  //set blue tone 0-255
	float opacity; //set opacity 0.0-1.0
};

struct Stroke{
	int red;   //set red tone 0-255
	int green; //set green tone 0-255
	int blue;  //set blue tone 0-255
	float opacity; //set opacity 0.0-1.0
	int width; //set opacity 0.0-1.0
};

struct Path{
	int n;     //number of points in path
	float x[10]; //array of x-coordinates
	float y[10]; //array of y-coordinates
};

//I'll just declare these down here so the program actually knows what's up
//Replaces stroke and fill element declarations from canvas code
struct Fill fill;
struct Stroke stroke;

//Prototypes for functions from canvas SVG code
float rand_float();
void setFill(int , int , int ,float );
void setStroke(int , int , int ,float ,int );
void drawCircle(struct Circle );
void drawLine(struct Line );
void drawRectangle(struct Rectangle );
void drawPath(struct Path );
void writeSVGHeader(char [], int , int );
void writeSVGFooter();
void draw();

/*  MAIN  */

int main()
{
    srand(time(NULL));

    writeSVGHeader(fileName, imWidth, imHeight);

    draw();

    writeSVGFooter();

    return 0;
}

/*  RAND FLOAT  */

float rand_float()
{
    return((float) rand() / (float) RAND_MAX);
}

/*  SET FILL  */

void setFill(int red_in, int green_in, int blue_in, float opacity_in)
{
    fill.red = red_in;
    fill.green = green_in;
    fill.blue = blue_in;
    fill.opacity = opacity_in;
}

/*  SET STROKE  */

void setStroke(int red_in, int green_in, int blue_in, float opacity_in, int width_in)
{
    stroke.red = red_in;
    stroke.green = green_in;
    stroke.blue = blue_in;
    stroke.opacity = opacity_in;
    stroke.width = width_in;
}

/*  DRAW CIRCLE  */

void drawCircle(struct Circle circle)
{
    fprintf(fp,"\n    <circle cx = '%f' cy = '%f' r = '%f'", circle.cx, circle.cy, circle.r);
    fprintf(fp," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}

/*  DRAW LINE  */

void drawLine(struct Line line)
{
    fprintf(fp,"\n    <line x1 = '%f' y1 = '%f' x2 = '%f' y2 = '%f'", line.x1, line.y1, line.x2, line.y2);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}

/*  DRAW RECTANGLE  */

void drawRectangle(struct Rectangle rectangle)
{
    fprintf(fp,"\n    <rect x = '%f' y = '%f' width = '%f' height = '%f'", rectangle.xCorner, rectangle.yCorner, rectangle.width, rectangle.height);
    fprintf(fp," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}

/*  DRAW PATH  */

void drawPath(struct Path path)
{
    int i;

    fprintf(fp,"\n    <path d ='M%f %f ", path.x[0], path.y[0]);

    for(i=1;i<path.n;i++)
    {
        fprintf(fp,"L%f %f ", path.x[i], path.y[i]);
    }

    fprintf(fp,"z' fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}

/*  WRITE SVG HEADER  */

void writeSVGHeader(char fileName[], int width, int height)
{
    //Open file for writing
    fp = fopen(fileName,"w");

    //Setup SVG header
    fprintf(fp,"<?xml version='1.0' standalone='no'?>");
    fprintf(fp,"\n<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' version='1.1' width = '%d' height = '%d'>", width, height);
}

/*  WRITE SVG FOOTER  */

void writeSVGFooter()
{
    //Closing SVG tag and close file
    fprintf(fp,"\n</svg>");
    fclose(fp);
}

/*  DRAW  */

void draw()
{
	struct Path path;
	struct Circle circle;
	struct Rectangle rect;
	struct Line line;
	char yn='y';
	do{

	}while(yn!='n');
    int i,n=3;
    setFill(255, 0, 0, 1.0);
    setStroke(0, 0, 0, 1.0, 2);

	circle.cx=300;
	circle.cy=300;
	circle.r=100;

	drawCircle(circle);

    float x[3] = {50.0, 20.0, 100.0};
    float y[3] = {100.0, 40.0, 30.0};
	path.n=n;

    for(i=0;i<n;i++)
    {
        path.x[i]=x[i];
        path.y[i]=y[i];
    }

	drawPath(path);
}
