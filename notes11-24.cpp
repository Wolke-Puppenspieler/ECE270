/*def:
signature of method - list of types in arg list
ex. int getSum(int num1, int nums[])
	signature: int ,int [] 
	//return type is not part of signature //must be in same order
	
method overloading: you can reuse method names as long as they have a unique signature

in c: int abs(int x), float fabs(float x), long labs(long x)
in c++: all can be called abs and compiler will figure out which to call
error:
float getMagnitude(float x,float y)
int getMagnitute(float r, float theta)

both have same signature, thus compiles cannot differentiate - ERROR 

*the constructor 
-is a method w/ same name as class
-called only once - when object is created
-no return type (not even void)
-purpose is the help initialize object
// if you do not supply a constructor in your code, the compiler will create an empty noarg constructor for you:*/
Complex::Complex()
{
}
//constructor can be overloaded
Complex::Complex()
{
		x=0;
		y=0;
}
Complex(float x_in, float y_in)
{
		x=x_in;
		y=y_in;
}
//--------------------------------------------
main()
{
	Complex z;
	z.display(); //x=0 y=0
	Complex p(10.0,20.0);
	p.display(); //x=10.0 y=20.0
}

//arrays of objects
/*must have noarg constructor
need method to initialize proper values*/
int main()
{
	Complex z[];
	for(i=0;i<10;i++)
	{
		z[i].setXY(...,...);
	}
}
int main()
{
	Fill greyscale[256];
	for(i=0;i<256;i++)
	{
		grescale[i].setFill(i,i,i,1.0);
	}
}

/* in c++:
 -2 types of  variables
 	-regular objects
 	-pointer objects
 	main()
 	{
 		complex z;
 		Complex *zptr;
 	}
 	
2 ways to initialize zptr
	-set to address  of existing variable
	-use "new" operator //works like malloc
	
*/

main()
{
	complex *zptr;
	complex z(10.0,20.0);
	zptr=&z;
}
//method #2
main()
{
	Complex *zptr;
	zptr=new Complex(10.0,20.0);
}
 /* accessing member variables and methods via pointer
 (*zptr).x same as zptr->x*/
 
 main()
 {
 	Complex *zptr;
 	zptr=new Complex(10.0,20.0);
 	zptr->display();
 	zptr->setX(5.0);
 	zptr->display();
 }
 
/* printing to screen: cout function

 main()
 {
 	cout<<"Hello World";
 	int x=5;
 	float y=10.5;
 	cout<<"\nx:"<<x<<y:"<<y<
 }
 */
  string class:
  #include<string>
  
   =,==,!=,<,> work as expected
   string s1, s2, s;
   s1="Hello";
   s2="There";
   
    s=s1+" "+s2; //Hello There
    if(s1==s2)  printf("same");
    else printf("different");
    
  //String Methods
  1. length()
  2 c_str()
  3 at(i)
  4 substr(i,n)
  5 insert(i,"hi")
  6 find("hi",10)
  