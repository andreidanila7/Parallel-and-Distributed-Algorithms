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

	int n, i, v[];

	cin >> n;
	for (i=1, i<=n, i++)
		cin >> v[i];







	MPI_Finalize();

}
