#include "stdafx.h"
#include <math.h>
#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"

int min(int a, int b) 
{
	if (a > b)
		return b;
	else
		return a;
}

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int rank;
	int INF = 9999;
	int n = 5, k, i, j;
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int a[5][5] = { { 0, 2, INF, 2, INF },
					{ 2, 0, 3, INF, INF },
					{ INF, 3, 0, 1, 8 },
					{ 10, INF, 1, 0, INF },
					{ INF, INF, 8, INF, 0 } };

	int temp_a[5][5];

	MPI_Bcast(a, 25, MPI_INT, 0, MPI_COMM_WORLD);

		for (j = 0; j < n; j++) 
			a[rank][j] = min(a[rank][j], a[rank][k]) + a[k][j]);
		
	MPI_Send(&a, 25, MPI_INT, 0, q, MPI_COMM_WORLD);


	if (rank == 0)
	{
		for (k = 1; k < n; k++) 
			for (i = 0; i < n; i++) 
			{
				MPI_Recv(&temp_a, 25, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				for (j = 0; j < n; j++) 
					if (temp_a[i][j] > a[i][j])
						a[i][j] = temp_a[i][j];
				
			}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				printf("%d ", a[i][j]);

			printf("\n");
		}
		
		MPI_Finalize;

	}
