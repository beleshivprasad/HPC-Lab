#include<bits/stdc++.h>
#include <math.h>
#include <string.h>
#include<omp.h>
#define SEED 35791246

using namespace std;

int main()
{
   int niter=0;
   int count=0;

   cout << "Iteration Count for Estimating PI: " ;
   cin >> niter;

   srand(SEED);

   double x,y,z;

   #pragma omp parallel for  shared(niter) schedule(static,100) reduction(+: count)
   for (int i=0; i<niter; i++) {

      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;

      z = x*x+y*y;

      if (z<=1)
	  	count++;
    }
   double pi=(double)count/niter*4;
   cout << " Threads used " << omp_get_max_threads() << " pi: " << pi << endl;
}
