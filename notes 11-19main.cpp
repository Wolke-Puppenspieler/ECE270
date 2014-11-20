//main.cpp
#include "./include/Complex.h"

main()
{
	Complex z(10.1,20.0); //z is a complex object
	Complex f(3.0,4.6);
	Complex g(0.0,0.0);
	z.display();
	z.setX(5.0);
	z.setY(7.0);
	z.display();
	g=z.add(f);
	
