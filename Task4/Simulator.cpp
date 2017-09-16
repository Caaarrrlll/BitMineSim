#include "Simulator.h"
#include "Block.h"
#include <fstream>
#include <sstream>

Simulator::Simulator(string txfile, string minerNames[], int nMiners)
{
    pool = nullptr;
    miners = nullptr;
    blockchain = nullptr;
    
    numTx = 0;
    numBlocks = 0;
    numMiners = nMiners;
    
    loadTxPool(txfile);
    initMiners(minerNames);
    initBlockchain();
}

Simulator::~Simulator()
{
    if (pool){
        for(int i=0; i < numTx; i++)
            delete pool[i];
        delete [] pool;
        pool = nullptr;
    }
    
    if (miners) {
        for (int i=0; i < numMiners; i++)
            delete miners[i];
        delete [] miners;
        miners = nullptr;
    }
    
    if (blockchain) {
        for (int i=0; i < numBlocks; i++)
            delete blockchain[i];
        delete [] blockchain;
        blockchain = nullptr;
    }
}

void Simulator::loadTxPool(string filename)
{
    ifstream file(filename);
    string line, fromAddress, toAddress, signature;
    float amount;
    
    int i=0;
    if (file)        
    {     
        //first line of the file contains the number of transactions
        getline(file, line);
        istringstream ss(line);
        ss >> numTx;

        //initialize the Transaction pool dynamic array
        pool = new Transaction*[numTx];
        
        //read the rest of the lines and create corresponding Transaction objects
        getline(file, line);
        while (file)
        {
            istringstream ss(line);
            ss >> fromAddress >> amount >> toAddress >> signature;           
            pool[i] = new Transaction(fromAddress, toAddress, signature, amount);
            
            i++;
            getline(file, line);
        }    
    }
    file.close();
}

void Simulator::initBlockchain()
{
    //Write code to initialize the blockchain dynamic array
    //Determine the number of blocks based on the number of transactions in the pool
    //(i.e. how many blocks will it require to store all these transactions?)
    //Hint: Don't forget to count the miner reward transactions in your block calculation
    
}

void Simulator::initMiners(string names[])
{
    //Write code to initialize the miners dynamic array and 
    // instantiate the dynamic Miner objects
    
}

void Simulator::removeMinedTxFromPool()
{
    //check if transactions have been marked for removal from pool, if so
    //deallocate the memory of the affected transactions
    
}

int Simulator::getUnminedTxCount()
{
    //get the number of transactions in the pool that have not been removed from the pool
    //(still un-mined/unprocessed)
    int count = 0;
       
    return count;    
}

bool Simulator::checkHash(string hash)
{
    //check if the first 2 characters of the hash are the same as the target
    //and return true if that's the case
    bool targetMet = false;
    
    
    return targetMet;
}

void Simulator::run(int maxIters)
{
    //follow the instructions in the assignment to complete this function    
        
}