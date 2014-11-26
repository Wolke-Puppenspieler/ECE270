/*Justin Newman
ECE270 Quiz 17
11/24/14*/
#ifndef QUIZ17_H
#define QUIZ17_H

class Fill{
	public:
		int red;   //set red tone 0-255
		int green; //set green tone 0-255
		int blue;  //set blue tone 0-255
		float opacity; //set opacity 0.0-1.0

		Fill(int r_in, int g_in, int b_in, float a_in);
		Fill();
		void setFill();
		void display();
};

class Stroke{
	public:
		int red;   //set red tone 0-255
		int green; //set green tone 0-255
		int blue;  //set blue tone 0-255
		float opacity; //set opacity 0.0-1.0
		int width; //set width

		Stroke(int r_in,int g_in, int b_in, float a_in, float width_in);
		Stroke();
		void setStroke();
};

 class Line{
	public:
		float x1; //x-coord of line start
		float y1; //y-coord of line start
		float x2; //x-coord of line end
		float y2; //y-coord of line end

		Line(float x1_in, float y1_in, float x2_in, float y2_in);
		Line();
		void display();
		void setLine();
		void setStart(float x1_in, float y1_in);
		void setEnd(float x2_in, float y2_in);
		void drawLine(Stroke stroke);
};

class Circle{
	public:
		float cx; //center x-coordinate
		float cy; //center y-coordinate
		float r;  //radius

		Circle(float cx_in, float cy_in, float r_in);
		Circle();
		void display();
		void setCircle();
		void setCenter(float cx_in, float cy_in);
		void setRadius(float r_in);
		void drawCircle(Fill fill,Stroke stroke);
};


class Rectangle{
	public:
		float xCorner; //x-coord of upper-left corner of rectangle
		float yCorner; //y-coord of upper-left corner of rectangle
		float width;   //horizontal size of rectangle
		float height;  //vertical size of rectangle

		Rectangle(float x1_in, float y1_in, float width_in, float height_in);
		Rectangle();
		void display();
		void setRect();
		void setCorner(float x_in, float y_in);
		void setDimensions(float width_in, float height_in);
		void drawRect(Fill fill, Stroke stroke);
};


class Path{
	public:
		int n;     //number of points in path
		float *x; //array of x-coordinates
		float *y; //array of y-coordinates

		Path(int n, float *x_in, float *y_in);
		Path();
		void display();
		void setPath();
		void setPoint(int n_in, float x_in, float y_in);
		void drawPath(Fill fill,Stroke stroke);
};
#endif
