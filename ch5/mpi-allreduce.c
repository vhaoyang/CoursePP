#include <stdio.h>
#include <mpi.h>   
int main(void) {
	int rank, size, send_buff, recv_buff;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	send_buff=rank+10;
	recv_buff=0;
	MPI_Allreduce(&send_buff, &recv_buff, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	printf("process %d, total: %d\n",rank,recv_buff);

	MPI_Finalize();
	return 0;
}
