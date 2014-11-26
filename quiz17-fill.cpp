/*Justin Newman
ECE270 Quiz 17
11/24/14*/

#include <iostream>

Fill::Fill(int r_in, int g_in, int b_in, float a_in)
{
	red=r_in;
	green=g_in;
	blue=b_in;
	opacity=a_in;
}

Fill::Fill()
{
    cout << "\nPlease enter the desired amount of red for your shape's fill color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",red);
    
    cout << "\nPlease enter the desired amount of green for your shape's fill color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's fill color (0-255): %d",green);
    
    cout << "\nPlease enter the desired amount of blue for your shape's fill color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",blue);
    
    cout << "\nPlease enter the desired opacity of your shape's fill color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's fill color (0.0-1.0): %f",opacity);
}
Fill::setFill()
{
    cout << "\nPlease enter the desired amount of red for your shape's fill color (0-255)";
	cin >> red;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",red);
    
    cout << "\nPlease enter the desired amount of green for your shape's fill color (0-255)";
    cin >> green;
    fprintf(output,"\nPlease enter the desired amount of green for your shape's fill color (0-255): %d",green);
    
    cout << "\nPlease enter the desired amount of blue for your shape's fill color (0-255)";
    cin >> blue;
    fprintf(output,"\nPlease enter the desired amount of red for your shape's fill color (0-255): %d",blue);
    
    cout << "\nPlease enter the desired opacity of your shape's fill color (0.0-1.0)";
    cin >> opacity;
    fprintf(output,"\nPlease enter the desired opacity of shape's fill color (0.0-1.0): %f",opacity);
}
	