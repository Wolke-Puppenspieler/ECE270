/*Justin Newman
ECE270 Quiz 17
11/24/14*/

 class Line{
	private:
		float x1; //x-coord of line start
		float y1; //y-coord of line start
		float x2; //x-coord of line end
		float y2; //y-coord of line end
	public:
		Line(float x1_in, float y1_in, float x2_in, float y2_in);
		void display();
		void setLine(float x1_in, float y1_in, float x2_in, float y2_in);
		void setStart(float x1_in, float y1_in);
		void setEnd(float x2_in, float y2_in);
};

class Circle{
	private:
		float cx; //center x-coordinate
		float cy; //center y-coordinate
		float r;  //radius
	public:
		Circle(float cx_in, float cy_in, float r_in);
		void display();
		void setCircle(float cx_in, float cy_in, float r_in);
		void setCenter(float cx_in, float cy_in);
		void setRadius(float r_in);
};

class Rectangle{
	private:
		float xCorner; //x-coord of upper-left corner of rectangle
		float yCorner; //y-coord of upper-left corner of rectangle
		float width;   //horizontal size of rectangle
		float height;  //vertical size of rectangle
	public:
		Rectangle(float x_in, float y_in, float width_in, float height_in);
		void display();
		void setRect(float x_in, float y_in, float width_in, float height_in);
		void setCorner(float x_in, float y_in);
		void setDimensions(float width_in, float height_in);
};

