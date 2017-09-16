#ifndef WALLET_H
#define WALLET_H

#include <iostream>

using namespace std;

class Wallet{
    private: 
        float balance;
        string address;
        string signature;
    
    public:
        Wallet();
        string getAddress();
        string getSignature();
        void deposit(float v);
        void withdraw(float v);
        float getBalance();
        void generateAddress();
        void generateSignature();
};

#endif