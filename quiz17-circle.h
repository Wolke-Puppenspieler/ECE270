/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include "./quiz17-stroke.h"
#include "./quiz17-fill.h"

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
