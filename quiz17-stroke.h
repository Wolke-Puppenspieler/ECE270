/*Justin Newman
ECE270 Quiz 17
11/24/14*/

class Stroke{
	public:
		int red;   //set red tone 0-255
		int green; //set green tone 0-255
		int blue;  //set blue tone 0-255
		float opacity; //set opacity 0.0-1.0
		int width; //set width
		Stroke(int r_in,int g_in, int b_in, float a_in, float width_in);
		Stroke();
		void setStroke(int r_in,int g_in, int b_in, float a_in, float width_in);
};
