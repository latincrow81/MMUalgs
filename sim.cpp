/** 
 * Sistemas Operativos 2018/1
 * Mauricio Escudero Restrepo
 * mescude1@eafit.edu.co
 * 201619407010
 * 
 * https://github.com/latincrow81/MMUalgs
 * 
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <iterator>


using namespace std;

int main(int argc, char* argv[])
{
    int addrBits, pageSize, frames, algorithm, pageNumber, escalarA, escalar;

    unsigned int pageBase;
    unsigned int * pageTable; // array with all pageBases
    unsigned int * frameArray;
    
    vector <unsigned int> request;
    vector <unsigned int> matchedPages;
    
    string requestFile;
    string page;

    vector<string>::iterator it;

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

    string algorithmName [] {"FIFO", "LRU", "OPTIMAL"};

    escalarA = log2 (pageSize);
    escalar = addrBits - escalarA;
    pageNumber = pow(2, escalar); // number of available pages
    
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
            // save base address as pageName
            pageBase = i*pageSize;
            pageTable[i] = pageBase;
            // print pages base address
            cout << "Page # " << dec << i << " Base @ " << hex << pageTable[i] << endl;
        }

    }

    istringstream ssReq(argv[5]);

    if (!(ssReq >> requestFile)) {
        cerr << "Invalid input " << argv[5] << '\n';
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }
    

    // process request file and store addresses

    ifstream namefile(requestFile);
    
    if (namefile.is_open())
    {
        while ( getline (namefile, page) )
        {
            unsigned int pageNumber = stoul(page,nullptr,0);
            request.push_back(pageNumber);

            cout << "page " << page << " registered" << '\n';
        }
        namefile.close();
    }else{ 
        cerr << "Unable to open file"; 
        return 1;
    }
    
    for(it = request.begin(); it != request.end(); it++ ){
        cout << "Address " << *it << endl;
    }

    /* translate addresses to pages

    for(int it = *request.begin(); it != *request.end(); it++ ){

        unsigned int addressToMatch = it;
        
        cout << "started matching.." << endl;
        
        for(int i = 0; i <= pageNumber; i++)
        {
            unsigned int lower = pageTable[i];
            unsigned int upper = pageTable[i++];

            if(it >= lower && it < upper){ // address matched on pageTable
                matchedPages.push_back(lower);
                cout << "pushed" << lower << "to matched vector, on position " << i << endl;
            }            
        }
    
    }*/
    

    istringstream ssFrames(argv[3]);

    if (!(ssFrames >> frames)) {
        cerr << "Invalid number " << argv[1] << '\n';
        cerr << "Usage: " << argv[0] << " [bits of address] [page size (bytes)] [frames] [algorithm] [access sequence]" << std::endl;
        return 1;
    }



    frameArray = new (nothrow) unsigned int[frames];

    
    // simulate using FIFO
    if (algorithm == 0){

        
    }

    // simulate using LRU
    if (algorithm == 1){

    }

    // simulate using OPTIMAL
    if (algorithm == 2){

    }

    delete[] pageTable;
    delete[] frameArray;
    return 0;
}