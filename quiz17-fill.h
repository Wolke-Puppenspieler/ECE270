/*Justin Newman
ECE270 Quiz 17
11/24/14*/

class Fill{
	public:
		int red;   //set red tone 0-255
		int green; //set green tone 0-255
		int blue;  //set blue tone 0-255
		float opacity; //set opacity 0.0-1.0
		Fill(int r_in, int g_in, int b_in, float a_in);
		Fill();
		void setFill(int r_in, int g_in, int b_in, float a_in);
		void display();
};
