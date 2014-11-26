/*Justin Newman
ECE270 Quiz 17
11/24/14*/

class Path{
	public:
		FILE *svg;
		FILE *output;
		int n;     //number of points in path
		float *x; //array of x-coordinates
		float *y; //array of y-coordinates
		
		Path(FILE *fp1, FILE *fp2, int n, float *x_in, float *y_in);
		Path(FILE *fp1, FILE *fp2);
		void display();
		void setPath();
		void setPoint(int n_in, float x_in, float y_in);
		void drawPath(Fill fill,Stroke stroke);
};