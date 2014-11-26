/*Justin Newman
Quiz 17 ECE270
11/24/14*/

Circle::Circle(FILE *fp1, FILE *fp2, float cx_in, float cy_in, float r_in)
{
	svg=fp1;
	output=fp2
	cx=cx_in;
	cy=cy_in;
	r=r_in;	
}

Circle::Circle(FILE *fp);
{
	svg=fp1;
	output=fp2;
	
	cout <<"\nPlease enter the center x-coordinate of your circle";
    cin >> cx;
    fprintf(output,"\nPlease enter the center x-coordinate of your circle: %.2f",cx);

    cout << "\nPlease enter the center y-coordinate of your circle";
    cin >> cy;
    fprintf(output,"\nPlease enter the center y-coordinate of your circle: %.2f",cy);

    cout <<"\nPlease enter the radius of your circle";
	cin >> r;
    fprintf(output,"\nPlease enter the radius of your circle: %d",r);

    system("cls");
}

void Circle::Display();
{
	cout << "\ncx:" << cx;
	cout << "\ncy:" << cy;
	cout << "\nr:" << r;
}

void Circle::setCircle(float cx_in, float cy_in, float r_in)
{
	cx=cx_in;
	cy=cy_in;
	r=r_in;
}

void Circle::setCenter(float cx_in, float cy_in)
{
	cx=cx_in;
	cy=cy_in;
}

void Circle::setRadius(float r_in)
{
	r=r_in;
}

void Circle::drawCircle(Fill fill,Stroke stroke)
{
	fprintf(svg,"\n    <circle cx = '%f' cy = '%f' r = '%f'", circle.cx, circle.cy, circle.r);
    fprintf(svg," fill = 'rgb(%d, %d, %d)' fill-opacity = '%f'", fill.red, fill.green, fill.blue, fill.opacity);
    fprintf(svg," stroke = 'rgb(%d, %d, %d)' stroke-opacity = '%f'", stroke.red, stroke.green, stroke.blue, stroke.opacity);
    fprintf(svg," stroke-width = '%d' />", stroke.width);
}