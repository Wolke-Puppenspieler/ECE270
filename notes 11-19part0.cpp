/*notes 11-19

#define MAX_NUM_PTS 100
struct Path{
	int n;
	float x[MAX_NUM_PTS];
	float y[MAX_NUM_PTS];
};
PROBLEM Usually won't need 100 elements, going beyond 100 will crash program
professionally:
struct Path{
	int n;
	float *x;
	float *y;
};
dynamic allocation - use malloc

void setPath( struct Path *path, int n_in, float x_in[],float y_in[]);
{
	path->n=n_in;
	path->x=(float*)malloc(n_in*sizeof(float));
	path->y=(float*)malloc(n_in*sizeof(float));
	for(i=0;i<n_in;i++)
	{
		path->x[i]=x_in[i];
		
	}
	
/