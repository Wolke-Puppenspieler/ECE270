/*Justin Newman
ECE270 Quiz 17
11/24/14*/

class Circle{
	public:
		FILE *svg;
		FILE *output;
		float cx; //center x-coordinate
		float cy; //center y-coordinate
		float r;  //radius

		Circle(FILE *fp1, FILE *fp2, float cx_in, float cy_in, float r_in);
		void display();
		void setCircle(float cx_in, float cy_in, float r_in);
		void setCenter(float cx_in, float cy_in);
		void setRadius(float r_in);
		void drawCircle(Fill fill,Stroke stroke);
};