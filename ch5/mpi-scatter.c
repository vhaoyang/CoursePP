#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>   
#define N 2
int main(void) {
	int i, rank, size;
	int *send_buff;
	int *recv_buff;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	recv_buff = malloc(N*sizeof(int));
	send_buff = malloc(size*N*sizeof(int));
	if (rank == 0)
	{
	    for (i = 0; i < size * N; i++)
	    {
	        send_buff[i] = i + 10;
	        printf("rank %d, send_buff[%d] = %d\n", rank, i, send_buff[i]);
	    }
	    printf("\n");
	}
	MPI_Scatter(send_buff, N, MPI_INT,
			    recv_buff, N, MPI_INT,0, MPI_COMM_WORLD);

	for (i = 0; i < N; i++)
	{
	    printf("rank %d, recv_buff[%d] = %d\n", rank, i, recv_buff[i]);
	}

	free(recv_buff);
	free(send_buff);
	
	MPI_Finalize();
	return 0;
}
