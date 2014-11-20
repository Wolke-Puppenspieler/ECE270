complex
+x:float	//member
+y:float	//variables
//c++ class
+Complex(x_in:float,y_in:float)		//
+display():void									//|
+setXY(x_in:float,y_in:float):void	//|
+getMagnitude():float					  // ^ METHODS	
+conjugate():void
+add(z:Complex):Complex


Complex.h: class definition
complex.cpp: implementation
main.cpp : has main function, where we create objects of our class

note - member variables and methods can be declared as "public" "private" "protected""
UML - 
public: +
private: -
protected: #

these are w/ respect to outside the class
if a method or variable is declared as public, it can be accessed directly from outside the class
if declared as private, not accessable from outside teh class

CASE 1:
suppose x and y are declared as public:
main()
{
	Complex z(10.0,20.0);
	z.x=5.0; //cna do because x and y are declared as public '+'
	z.y=-7.0;
}

if PRIVATE

main()
{
	Complex z(10.0,20.2);
	
	z.x=5.0 //will cause compiler error, cannot change value because declared private '-'
}

good practice: 
1.) declare member variables as private
2.) include getter&setter methods to allow ser to change variable
//continuation of above UML
+setX(x_in:foat):void
+getX():float
+setY(y_in:float):void
+getY():void
//change above x and y to private
//why even bother? - prevent variable from getting corrupted - dummy-proof code
1.) prevent illegal values for variables
2.) consistency

call:
z.setx(5.0);



  