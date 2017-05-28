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
		MPI_Send(&senddata, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Rank %d sent message %d with tag 1\n", rank, senddata);
	}
	else if(2==rank)
	{
		senddata=88;
		MPI_Send(&senddata, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Rank %d sent message %d with tag 1\n", rank, senddata);
		sleep(5);
		MPI_Send(&senddata, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);
		printf("Rank %d sent message %d with tag 2\n", rank, senddata);
	}
	else if(1==rank)
	{
		int flag = 1;
		while(flag)
		{
		    MPI_Recv(&recvdata, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		    switch(status.MPI_TAG)
		    {
				case 1: printf("Rank %d got message %d with tag 1\n", rank, recvdata);break;
				case 2: printf("Rank %d got message %d with tag 2\n", rank, recvdata);flag=0;break;
			}
		}
	}
	MPI_Finalize();
	return 0;
}
