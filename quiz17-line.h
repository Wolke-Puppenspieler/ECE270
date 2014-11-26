/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include "./quiz17-stroke.h"
#include "./quiz17-fill.h"

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
		void drawLine(Fill fill,Stroke stroke);
};









