#include <stdio.h>
#include <unistd.h>
#include "mpi.h"
int main(void)
{
	int rank, size;
	int senddata,recvdata;
	MPI_Status status;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("I'm rank %d\n",rank);
	if(0==rank)
	{
		senddata=66;
		sleep(20);
		MPI_Send(&senddata, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Rank %d sent message %d\n", rank, senddata);
	}
	else if(2==rank)
	{
		senddata=88;
		MPI_Send(&senddata, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Rank %d sent message %d\n", rank, senddata);
	}
	else if(1==rank)
	{
		MPI_Recv(&recvdata, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
		printf("Rank %d got message %d\n", rank, recvdata);
		MPI_Recv(&recvdata, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
		printf("Rank %d got message %d\n", rank, recvdata);
	}
	MPI_Finalize();
	return 0;
}
