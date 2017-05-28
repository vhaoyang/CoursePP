#include <stdio.h>
#include <mpi.h>   
int main(void) {
	int rank, size;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int n=0;
	if (0 == rank)
	{
		printf("Enter n:\n");
		scanf("%d", &n);
	}
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d got %d\n", rank, n);

	MPI_Finalize();
	return 0;
}
