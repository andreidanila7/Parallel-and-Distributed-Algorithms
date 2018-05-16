#include <mpi.h>
#include <iostream>
using namespace std;
float A[50][50];
int n, i, j;
#define PInfinit 1000

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

	if (rank == 0)
	{
		cin >> n;
		for (int q = 1; q <= n; q++)
			for (int q1 = 1; q1 <= n; q1++)
				cin >> A[q][q1];
		int Nod_Initial = 4;
		int Nod_Final = 2;
		MPI_Send(&Nod_Initial, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(&Nod_Final, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);	
	}
	
	if (rank == 1)
	{
		MPI_Recv(&Nod_Initial, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Recv(&Nod_Final, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

		if (A[Nod_Initial][Nod_Final] < PInfinit)
		{
			cout << " Drumul de la " << Nod_Initial << " la " << Nod_Final << " are lungimea " << A[Nod_Initial][Nod_Final] << "\n";
			cout << Nod_Initial << " ";
			Drum(Nod_Initial, Nod_Final);
		}
		else
			cout << "Nu exista drum de la " << Nod_Initial << " la " << Nod_Final;

		
		void Drum(int i, int j)
		{
			int k = 1, gasit = 0;
			while ((k <= n) && !gasit)
			{
				if (i != k && j != k && A[i][j] == A[i][k] + A[k][j])
				{
					Drum(i, k);
					Drum(k, j);
					gasit = 1;
				}
				k++;
			}
			if (!gasit)
				cout << j << " ";
		}
	}
		
			
		if (rank==2)
		{
		int i, j, k;
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if (A[i][j]>A[i][k] + A[k][j])
						A[i][j] = A[i][k] + A[k][j];

		}
	
	

MPI_Finalize();
}