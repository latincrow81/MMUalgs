#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    int addrBits, pageSize, frames, algorithm, pageNumber, escalarA, escalar;

    unsigned int pageBase;
    unsigned int * pageTable;
    
    vector <unsigned int> request;

    // Check the number of parameters
    if (argc < 5) {
        // Tell the user how to run the program
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }

    istringstream ssAlgo(argv[4]);
    
    if (!(ssAlgo >> algorithm)) {
        cerr << "Invalid number " << argv[4] << '\n';
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }
    
    istringstream ssAddr(argv[1]);

    if (!(ssAddr >> addrBits)) {
        cerr << "Invalid number " << argv[1] << '\n';
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }

    istringstream ssPage(argv[2]);

    if (!(ssPage >> pageSize)) {
        cerr << "Invalid number " << argv[2] << '\n';
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }

    string algorithmName [] {"FIFO", "LRU", "OPTIMO"};

    escalarA = log2 (pageSize);
    escalar = addrBits - escalarA;
    pageNumber = pow(2, escalar); 
    
    // Print the simulation parameters:
    cout << argv[1] << " bits address, " << argv[2] << " bytes pages, " << argv[3] << " frames, "<< " Using: " << algorithmName[algorithm] << std::endl;
    cout << pageNumber << " pages available" << endl;

    //Create pageTable
    pageTable = new (nothrow) unsigned int[pageNumber];

    if (pageTable == nullptr){
        cout << "Error: memory could not be allocated";
        return 1;
    }else{

        for(int i = 0; i <= pageNumber; i++)
        {
            /* save base address as pageName */
            pageBase = i*pageSize;
            pageTable[i] = pageBase;
        }

        // print pages base address
        for(int i = 0; i <= pageNumber; i++)
        {
            /* print page # and base */
            cout << "Page # " << dec << i << " Base @ " << hex << pageTable[i] << endl;
            i++;
        }

        delete[] pageTable;
        cout << "Page table cleared from memory" << endl;

    }
    
    return 0;
}