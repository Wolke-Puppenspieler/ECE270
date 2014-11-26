/*Justin Newman
ECE270 Quiz 17
11/24/14*/

class Rectangle{
	public:
		FILE *svg;
		FILE *output;
		float xCorner; //x-coord of upper-left corner of rectangle
		float yCorner; //y-coord of upper-left corner of rectangle
		float width;   //horizontal size of rectangle
		float height;  //vertical size of rectangle
		
		Rectangle(float x_in, float y_in, float width_in, float height_in);
		void display();
		void setRect(float x_in, float y_in, float width_in, float height_in);
		void setCorner(float x_in, float y_in);
		void setDimensions(float width_in, float height_in);
		void drawRect(Fill fill, Stroke stroke);
};