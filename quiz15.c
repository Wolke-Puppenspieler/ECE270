#include<stdio.h>
#include<stdlib.h>

//START snippet of SVG code on canvas
//Global Variables ............................
FILE *fp;            //File pointer for svg image
FILE *output;

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

struct Path{
	int n;     //number of points in path
	float x[10]; //array of x-coordinates
	float y[10]; //array of y-coordinates
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

//I'll just declare these down here so the program actually knows what's up
//Replaces stroke and fill element declarations from canvas code
struct Fill fill;
struct Stroke stroke;

//Prototypes for functions from canvas SVG code
float rand_float();
void setFill();
void setStroke();
void drawLine(struct Line );
void drawCircle(struct Circle );
void drawRectangle(struct Rectangle );
void drawPath(struct Path );
void writeSVGHeader(char [], int , int );
void writeSVGFooter();
void draw();
void menu();
struct Line setLine();
struct Circle setCircle();
struct Rectangle setRectangle();
struct Path setPath();

/*  MAIN  */

int main()
{
    srand(time(NULL));
    output=fopen("quiz15.txt","w");

    writeSVGHeader(fileName, imWidth, imHeight);

    menu();

    draw();

    writeSVGFooter();

    fclose(output);

    return 0;
}

/*  RAND FLOAT  */

float rand_float()
{
    return((float) rand() / (float) RAND_MAX);
}

/*  SET FILL  */

void setFill()
{
    //fill.red = red_in;
    printf("Please enter the desired amount of red for your shape's fill color (0-255)");
    scanf("\n%d",&fill.red);
    fprintf(output,"Please enter the desired amount of red for your shape's fill color (0-255): %d",fill.red);
    //fill.green = green_in;
    printf("Please enter the desired amount of green for your shape's fill color (0-255)");
    scanf("\n%d",&fill.green);
    fprintf(output,"Please enter the desired amount of green for your shape's fill color (0-255): %d",fill.green);
    //fill.blue = blue_in;
    printf("Please enter the desired amount of blue for your shape's fill color (0-255)");
    scanf("\n%d",&fill.blue);
    fprintf(output,"Please enter the desired amount of red for your shape's fill color (0-255): %d",fill.blue);
    //fill.opacity = opacity_in;
    printf("Please enter the desired opacity of your shape's fill color (0.0-1.0)");
    scanf("\n%f",&fill.opacity);
    fprintf(output,"Please enter the desired opacity of shape's fill color (0.0-1.0): %f",fill.opacity);
}

/*  SET STROKE  */

void setStroke()
{
    //stroke.red = red_in;
    printf("Please enter the desired amount of red for your shape's stroke color (0-255)");
    scanf("\n%d",&stroke.red);
    fprintf(output,"Please enter the desired amount of red for your shape's stroke color (0-255): %d",stroke.red);
    //stroke.green = green_in;
    printf("Please enter the desired amount of green for your shape's stroke color (0-255)");
    scanf("\n%d",&stroke.green);
    fprintf(output,"Please enter the desired amount of green for your shape's stroke color (0-255): %d",stroke.green);
    //stroke.blue = blue_in;
    printf("Please enter the desired amount of blue for your shape's stroke color (0-255)");
    scanf("\n%d",&stroke.blue);
    fprintf(output,"Please enter the desired amount of blue for your shape's stroke color (0-255): %d",stroke.blue);
    //stroke.opacity = opacity_in;
    printf("Please enter the desired opacity of your shape's stroke color (0.0-1.0)");
    scanf("\n%f",&stroke.opacity);
    fprintf(output,"Please enter the desired opacity of shape's stroke color (0.0-1.0): %f",stroke.opacity);
    //stroke.width = width_in;
    printf("Please enter the desired width of your shape's stroke");
    scanf("\n%f",&stroke.width);
    fprintf(output,"Please enter the desired width of shape's stroke: %f",stroke.width);
}

/*  DRAW LINE  */

void drawLine(struct Line line)
{
    fprintf(fp,"\n    <line x1 = '%f' y1 = '%f' x2 = '%f' y2 = '%f'", line.x1, line.y1, line.x2, line.y2);
    fprintf(fp," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(fp," stroke-width = '%d' />", stroke.width);
}


/*  DRAW CIRCLE  */

void drawCircle(struct Circle circle)
{
    fprintf(fp,"\n    <circle cx = '%f' cy = '%f' r = '%f'", circle.cx, circle.cy, circle.r);
    fprintf(fp," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
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
	struct Line line;
	struct Circle circle;
	struct Rectangle rect;
	struct Path path;
	char selection;

	do
    {
		scanf("\n%c",&selection);

		switch(selection)
		{
			case 'L':case 'l':
				system("cls");
				setFill();
                setStroke();
				line=setLine();
				drawLine(line);
				menu();
			break;
			case 'C':case 'c':
				system("cls");
				setFill();
                setStroke();
				circle=setCircle();
                drawCircle(circle);
                menu();
			break;
			case 'R':case 'r':
				system("cls");
                setFill();
                setStroke();
				rect=setRectangle();
				drawRectangle(rect);
				menu();
			break;
			case 'P':case 'p':
				system("cls");
				setFill();
                setStroke();
				path=setPath();
				drawPath(path);
				menu();
			break;
			case 'Q':case 'q':
				system("cls");
				printf("\nProgram terminating...\nenjoy your drawing");
				fprintf(output,"\nProgram terminating...\nenjoy your drawing");

				printf("\nYour drawing can be found in image.svg in the same folder as this program");
				fprintf(output,"\nYour drawing can be found in image.svg in the same folder as this program");
			break;
			default :
				system("cls");
				printf("\nPlease make a valid selection from the following menu:\n");
				fprintf(output,"\nPlease make a valid selection from the following menu:\n");
				menu();
			}
	}while(selection!='Q'&&selection!='q');
}

void menu()
{
    //Displays function selection menu
    printf("\nWelcome to Justin Newman's ECE270 Quiz #15 SVG drawing program");
    fprintf(output,"\nWelcome to Justin Newman's ECE270 Quiz #15 SVG drawing program");

    printf("\n\nPlease make your selection from the following menu:");
    fprintf(output,"\n\nPlease make your selection from the following menu:");

    printf("\n\nL:\tDraw a line");
    fprintf(output,"\n\nL:\tDraw a line");

    printf("\nC:\tDraw a circle");
    fprintf(output,"\nC:\tDraw a circle");

    printf("\nR:\tDraw a rectangle");
    fprintf(output,"\nR:\tDraw a rectangle");

    printf("\nP:\tDefine your own 1-10 pointed shape");
    fprintf(output,"\nP:\tDefine your own 1-10 pointed shape");

    printf("\nQ:\tTo stop drawing");
    fprintf(output,"\nQ:\tTo stop drawing");

    printf("\n\nPlease enter your selection now:");
    fprintf(output,"\n\nPlease enter your selection now:");
}

//allows the user to set the paramters of a line to be drawn
struct Line setLine()
{
    struct Line line;

    printf("Please enter the starting x-coordinate of your line");
    scanf("\n%f",&line.x1);
    fprintf(output,"Please enter the starting x-coordinate of your line: %.2f",line.x1);

    printf("Please enter the starting y-coordinate of your line");
    scanf("\n%f",&line.y1);
    fprintf(output,"Please enter the starting y-coordinate of your line: %.2f",line.y1);

    printf("Please enter the ending x-coordinate of your line");
    scanf("\n%f",&line.x2);
    fprintf(output,"Please enter the ending x-coordinate of your line: %.2f",line.x2);

    printf("Please enter the ending y-coordinate of your line");
    scanf("\n%f",&line.y2);
    fprintf(output,"Please enter the ending y-coordinate of your line: %.2f",line.y2);

    system("cls");

    return(line);
};
//allows the user to set the paramters of a circle to be drawn
struct Circle setCircle()
{
    struct Circle circle;
    printf("Please enter the center x-coordinate of your circle");
    scanf("\n%f",&circle.cx);
    fprintf(output,"Please enter the center x-coordinate of your line: %.2f",circle.cx);

    printf("Please enter the center y-coordinate of your line");
    scanf("\n%f",&circle.cy);
    fprintf(output,"Please enter the center y-coordinate of your line: %.2f",circle.cy);

    printf("Please enter the radius of your circle");
    scanf("\n%f",&circle.r);
    fprintf(output,"Please enter the radius of your circle: %.2f",circle.r);

    system("cls");

};

//allows the user to set the paramters of a rectangle to be drawn
struct Rectangle setRectangle()
{
    struct Rectangle rect;

    printf("Please enter the x-coordinate of the upper left corner of your rectangle");
    scanf("\n%f",&rect.xCorner);
    fprintf(output,"Please enter the x-coordinate of the upper left corner of your rectangle%.2f",rect.xCorner);

    printf("Please enter the y-coordinate of the upper left corner of your rectangle");
    scanf("\n%f",&rect.yCorner);
    fprintf(output,"Please enter the y-coordinate of the upper left corner of your rectangle%.2f",rect.yCorner);

    printf("Please enter the width of your rectangle");
    scanf("\n%f",&rect.width);
    fprintf(output,"Please enter the width of your rectangle%.2f",rect.width);

    printf("Please enter the height of your rectangle");
    scanf("\n%f",&rect.height);
    fprintf(output,"Please enter the height of your rectangle%.2f",rect.height);

    system("cls");

};




//allows the user to set the paramters of a path to be drawn
struct Path setPath()
{
    struct Path path;
    int i,n;

    printf("Please enter the number of corners your shape will have (1-10)");
    scanf("\n%d",&n);
    fprintf(output,"Please enter the number of corners your shape will have: %d",n);

    float x[n];
    float y[n];

    for(i=0;i<n;i++)
    {
        printf("Please enter the x-coordinate for point #%d of your shape",i);
        scanf("\n%d",*(x+i));
        fprintf(output,"Please enter the center x-coordinate of your line: %.2f",x[i]);
    }

    path.n=n;

    for(i=0;i<n;i++)
    {
        path.x[i]=x[i];
        path.y[i]=y[i];
    }

    system("cls");
};
