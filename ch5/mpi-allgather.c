#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>   
#define N 1
int main(void) {
	int i, rank, size;
	int send_buff;
	int *recv_buff;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	recv_buff = malloc(size*N*sizeof(int));
	send_buff = rank+10; 
	MPI_Allgather(&send_buff,N,MPI_INT,recv_buff,N,MPI_INT,MPI_COMM_WORLD);
	for (i = 0; i < size*N; i++)
	{
    	printf("rank %d, recv_buff[%d] = %d\n", rank, i, recv_buff[i]);
	}
	free(recv_buff);
	
	MPI_Finalize();
	return 0;
}
