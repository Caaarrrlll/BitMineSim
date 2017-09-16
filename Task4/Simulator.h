#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Transaction.h"
#include "Block.h"
#include "Miner.h"

class Simulator
{
public:
    Simulator(string txfile, string minerNames[], int numMiners);
    ~Simulator();
    void run(int maxIters=300);
       
private:    
    Transaction** pool;
    Block** blockchain;
    Miner** miners;
    
    int numBlocks;
    int numTx;
    int numMiners;
    const string MINING_TARGET = "00";
    
    void loadTxPool(string filename);
    void initBlockchain();
    void initMiners(string names[]);
    void removeMinedTxFromPool();
    int getUnminedTxCount();
    bool checkHash(string hash);
            
};

#endif // SIMULATOR_H
