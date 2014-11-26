/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include "./quiz17-stroke.h"
#include "./quiz17-fill.h"


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
