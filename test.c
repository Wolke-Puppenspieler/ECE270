//complex.cpp
//class       //method    //arg list
Complex::Complex(float x_in,float y_in) //constructor, can only be called once
{
	x=x_in;
	y=y_in;
}

void Complex::display()
{
	printf("\n Complex object");
	printf("\n	x: %f",x);
	printf("\n	y: %f",y);
}

void Complex::setXY(float x_in,float y_in)
{
	x=x_in;
	y=y_in;
}

Complex Complex::add(Complex z)
{
	Complex sum;
	sum.x=x+z.x; //may nmot work
	sum.y=y+z.y; //may not work
	
	sum.setX(x+z.getX());
	sum.setY(x+z.setY());
	
	
	return(sum);


}
