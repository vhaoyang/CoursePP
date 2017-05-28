#include <stdio.h>
#include <mpi.h>   
int main(void) {
	int rank, size;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int total=0;
	MPI_Reduce(&rank, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Bcast(&total, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("process %d, total: %d\n",rank, total);

	MPI_Finalize();
	return 0;
}
