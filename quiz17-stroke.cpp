/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include <iostream>

Stroke::Stroke(int r_in, int g_in, int b_in, float a_in, float width_in)
{
	red=r_in;
	green=g_in;
	blue=b_in;
	opacity=a_in;
	width=width_in;
}

Stroke::Stroke()
{
    cout << "\nPlease enter the desired amount of red for your shape's Stroke color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",red);
    
    cout << "\nPlease enter the desired amount of green for your shape's Stroke color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's Stroke color (0-255): %d",green);
    
    cout << "\nPlease enter the desired amount of blue for your shape's Stroke color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",blue);
    
    cout << "\nPlease enter the desired opacity of your shape's Stroke color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's Stroke color (0.0-1.0): %f",opacity);
	
	cout << "\nPlease enter the desired width of your shape's Stroke";
    cin >> width;
    fprintf(output,"\nPlease enter the desired width of shape's Stroke: %f",width);
}
Stroke::setStroke()
{
    cout << "\nPlease enter the desired amount of red for your shape's Stroke color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",red);
    
    cout << "\nPlease enter the desired amount of green for your shape's Stroke color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's Stroke color (0-255): %d",green);
    
    cout << "\nPlease enter the desired amount of blue for your shape's Stroke color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's Stroke color (0-255): %d",blue);
    
    cout << "\nPlease enter the desired opacity of your shape's Stroke color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's Stroke color (0.0-1.0): %f",opacity);
	
	cout << "\nPlease enter the desired width of your shape's Stroke";
    cin >> width;
    fprintf(output,"\nPlease enter the desired width of shape's Stroke: %f",width);
}