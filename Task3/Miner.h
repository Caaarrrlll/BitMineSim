#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "Block.h"
#include "Wallet.h"
#include "Crypto.h"

class Miner{
    private: 
        string name;
        Block* currentBlock;
        Wallet* wallet;
        float blockReward;

    public:
        Miner();
        Miner(string s);
        ~Miner();
        void setName(string n);
        string getName();
        void createBlock(Transaction** p, Block* prev, float reward);
        Block* getBlock();
        void deleteBlock();
        void confirmBlock();
        Wallet* getWallet();
        string mine(int nonce);
};

#endif