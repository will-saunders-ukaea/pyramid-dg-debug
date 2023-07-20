#include <iostream>
#include <mpi.h>
#include <memory>
#include <LibUtilities/BasicUtils/SessionReader.h>
#include <MultiRegions/ContField.h>
#include <MultiRegions/DisContField.h>


using namespace Nektar;

int main(int argc, char **argv) {

  int thread_level_provided;
  if (MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED,
                      &thread_level_provided) != MPI_SUCCESS) {
    std::cout << "ERROR: MPI_Init != MPI_SUCCESS" << std::endl;
    return -1;
  }


  LibUtilities::SessionReaderSharedPtr session;
  SpatialDomains::MeshGraphSharedPtr graph;
  // Create session reader.
  session = LibUtilities::SessionReader::CreateInstance(argc, argv);
  graph = SpatialDomains::MeshGraph::Read(session);

  auto field = std::make_shared<MultiRegions::DisContField>(session, graph, "u");


  if (MPI_Finalize() != MPI_SUCCESS) {
    std::cout << "ERROR: MPI_Finalize != MPI_SUCCESS" << std::endl;
    return -1;
  }

  return 0;
}
