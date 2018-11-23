#include<stdio.h>
#include<omp.h>
#include <math.h>

double flux(double f)
{
return 0.5*f*f;
}


int main(int argc, char ** argv)
{
float t_max[4] = {0.0,0.5,1.0,2.0};
int N;
float delta_x,L;
L       = 4.0;
delta_x = 0.05;
N       = (L/delta_x+1);
printf("f***iu");
float x[N];
float u[N];
printf("f***iu");
for(int i=0;i<N;i++)
{
 x[i]=i*L/N;
 if(x[i]<2)
  {
  u[i]=1.0;
  }else{u[i]=0;}
}

#pragma omp parallel
{
int thread_id = omp_get_thread_num();
int thread_count = omp_get_num_threads();
printf("f***iu");

float t_max   = 0.45;
float delta_t = 0.015;
float delta   = 5.0;
float copiaU[N];
float Flujo[N];
int N_t = (t_max/delta_t);

for(int o=0; o<N; o++)
	{
	copiaU[o] = u[o];
	}

void print(float *x, int n_points){
  int i;
  for(i = 0 ; i < n_points ; i++){
    fprintf(stdout, "%f\n", x[i]);
  }
}
for(int i=0; i<N_t; i++)
 {
	for(int j=0; j<N; j++)
	{
	  Flujo[j] = flux(u[j]);
	}

	for(int k=0;k<(N-2); k++)
	{
	copiaU[k+1] = 0.5*(u[k+2]+u[k]);
	copiaU[k+1] -= (0.5*delta_t/delta)*(Flujo[k+2]-Flujo[k]);
	}

	for(int l=0; l<N; l++)
	{
	   u[l] = copiaU[l];
	}
 }
print(copiaU,N);

}



return 0;
}
