#include <stdio.h>
#include <string.h>
#include "mpi.h"

main(int argc, char *argv[])
{
        int ret, rank, size, i, tag;
        MPI_Status status;
        int a = 0;

        MPI_Init(&argc, &argv);
        ret = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        ret = MPI_Comm_size(MPI_COMM_WORLD, &size);
        tag=100;

        if (rank == 0)
        {
                ret = MPI_Send(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
                a++;
                MPI_Recv(&a, 1, MPI_INT, 3, tag, MPI_COMM_WORLD, &status);
                
        }
        if (rank == 1)
        {
                ret = MPI_Send(&a, 1, MPI_INT, 2, tag, MPI_COMM_WORLD);
                a++;
                MPI_Recv(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
                
        }
        if (rank == 2)
        {
                ret = MPI_Send(&a, 1, MPI_INT, 3, tag, MPI_COMM_WORLD);
                a++;
                MPI_Recv(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
                
        }
        if (rank == 3)
        {
                ret = MPI_Send(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
                a++;
                MPI_Recv(&a, 1, MPI_INT, 2, tag, MPI_COMM_WORLD, &status);
                
        }
        else

        MPI_Finalize();
}

