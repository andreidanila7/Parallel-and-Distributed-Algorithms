#include <stdio.h>

#include <mpi.h>



using namespace std;



int main(int argc, char** argv0)

{

	MPI_Init(NULL, NULL);



	int nr_proc;

	MPI_Comm_size(MPI_COMM_WORLD, &nr_proc);



	int rank;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);



	char processor_name[MPI_MAX_PROCESSOR_NAME];

	int name_length;

	MPI_Get_processor_name(processor_name, name_length);



	int n, i, v[], x, sum = 0, k;



	if (rank == 0)

	{

		cin >> n;

		for (i = 1, i <= n, i++)

			cin >> v[i];


		int MPI_Comm_size(MPI_Comm comm, int *size)
		x = n / size ;   // arrays length/ number of processes

		for (k = 0; k <= x; k++)

			s = s + v[k];


		MPI_Recv(v, N / nr_proc, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

		s = s + v;


	else

		for (k = nr_proc * x; k <= (nr_proc + 1)*x; k++)

			sum = sum + v[k];

	MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD)

	}



	MPI_Finalize();



}
