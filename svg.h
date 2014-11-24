//in svg.h
class Svg
{
	public:
		char filename[MAX_STR_LEN]
		int inWidth;
		int inHeight;
		FILE *fp;
		Svg(char fileName_in[],int inWidth,int inHeight);
		void drawCircle(Circle C, Fill f, Stroke s);
}