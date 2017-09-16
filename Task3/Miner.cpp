#include "Miner.h"

using namespace std;

Miner::Miner(){
    name = "";
    blockReward = 0;
    currentBlock = nullptr;
    wallet = new Wallet();
}

Miner::Miner(string s){
    name = s;
    blockReward = 0;
    currentBlock = nullptr;
    wallet = new Wallet();
}

Miner::~Miner(){
    deleteBlock();
    delete wallet;
    wallet = nullptr;
}

void Miner::setName(string n){
    name = n;
}

string Miner::getName(){
    string result = this->name;
    return result;
}

void Miner::createBlock(Transaction** p, Block* prev, float reward){
    int i = 0;
    blockReward = reward;

    if(currentBlock != nullptr){
        delete currentBlock;
        currentBlock = nullptr;
    }
    
    if(prev != nullptr){
        currentBlock = new Block(prev->getId() + 1, prev->getBlockHash(), prev->getMinerName());
        if(p[i] != nullptr){
            while(currentBlock->canAddTransaction()){
                if(i == 0){
                    Transaction* t = new Transaction("", Crypto::random_string(20), Crypto::random_string(40), reward);
                    currentBlock->addTransaction(t);
                    i++;
                }
                else{
                    currentBlock->addTransaction(p[i]);
                    p[i]->setRemoveFromPool(true);
                    i++;
                }
            }    
        }
    }
    else if(prev == nullptr){
        currentBlock = new Block(1, "", "");
        if(p[i] != nullptr){
            while(currentBlock->canAddTransaction()){
                currentBlock->addTransaction(p[i]);
                p[i]->setRemoveFromPool(true);
                i++;
            }    
        }
    }
}

Block* Miner::getBlock(){
    Block* result = currentBlock;
    return result;
}

void Miner::deleteBlock(){
    delete currentBlock;
    currentBlock = nullptr;
}

void Miner::confirmBlock(){
    currentBlock->confirm();
    wallet->deposit(blockReward);
}

Wallet* Miner::getWallet(){
    Wallet* result = wallet;
    return result;
}

string Miner::mine(int nonce){
    string result = "";

    for(int i = 0; i < currentBlock->getNumTransactions(); i++){
        result += Crypto::sha1hash(currentBlock->getTransaction(i)->getId());
        result += "-";
    }

    result += currentBlock->getPreviousBlockHash();
    result += "-";
    result += to_string(nonce);
    

    currentBlock->setBlockHash(result);

    result = Crypto::sha1hash(result);

    return result;
}