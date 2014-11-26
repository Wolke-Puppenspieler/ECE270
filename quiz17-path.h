/*Justin Newman
ECE270 Quiz 17
11/24/14*/

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