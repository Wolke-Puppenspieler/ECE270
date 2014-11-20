//writing class (C++)
//Complex.h

class Complex
{
	private:
		float x;
		float y;
	public:
		Complex(float x_in,float y_in);
		void display();
		void setXY(float x_in,float y_in);
		float getMagnitude();
		void conjugate();
		Complex add(Complex z);
		void setX(float x_in);
		void setY(float y_in);
		float getX();
		float getY();
}; //end of class definition