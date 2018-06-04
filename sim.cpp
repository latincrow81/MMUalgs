#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    int addrBits, pageSize, frames, algorithm;
    unsigned long int request;

    // Check the number of parameters
    if (argc < 5) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " [bits of address] [page size] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }

    istringstream ss(argv[4]);
    
    if (!(ss >> algorithm)) {
        cerr << "Invalid number " << argv[4] << '\n';
        return 1;
    }
    
    string algorithmName [] {"FIFO", "LRU", "OPTIMO"};
    
    // Print the simulation parameters:
    cout << argv[1] << " bits address, " << argv[2] << " bytes pages, " << argv[3] << " frames, "<< " Using: " << algorithmName[algorithm] << std::endl;
    
    return 0;
}