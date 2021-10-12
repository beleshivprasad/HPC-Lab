#include <mpi.h> 
#include <stdio.h> 
#include <stdlib.h>
 
int main(int argc, char* argv[])
{ 
 int np, pid;
 int a[]={1,2,3,4,5,6,7,8,9,10};
 MPI_Init(&argc, &argv); 
 MPI_Comm_rank(MPI_COMM_WORLD, &pid); 
 MPI_Comm_size(MPI_COMM_WORLD, &np); 
 int i_sum = 0; 
 if (pid == 0) 
 { 
	for(int i = 0; i < 5; i++) 
		i_sum += a[i]; 
 }
 else if (pid == 1)
 { 
	for(int i = 5; i < 10; i++) 
	i_sum += a[i]; 
 }  
 int sum; 
 MPI_Reduce(&i_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 
 if (pid == 0)
 {
 	printf("Sum of array is : %d\n", sum); 
 } 
 MPI_Finalize(); 
 return 0; 
}
