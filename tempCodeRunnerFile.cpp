#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    // Initialize MPI
    int rc, rank, num_ranks;
    rc = MPI_Init(&argc, &argv);
    rc |= MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    rc |= MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
    if (rc != 0)
    {
        std::cerr << "Error initializing MPI" << std::endl;
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    char mpi_hostname[MPI_MAX_PROCESSOR_NAME];
    int mpi_hostname_length;
    MPI_Get_processor_name(mpi_hostname, &mpi_hostname_length);
    std::cout << "[Rank " << rank << " / " << num_ranks << "] mpi_host = " << mpi_hostname << std::endl;

    MPI_Finalize();

    return 0;
}

mpicxx -std=c++14 -o mpi_hello mpi_hello.cpp