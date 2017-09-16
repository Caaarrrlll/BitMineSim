#include "Wallet.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Wallet::Wallet(){
    balance = 0;
    generateAddress();
    generateSignature();
}

string Wallet::getAddress(){
    string result = address;
    return result;
}

string Wallet::getSignature(){
    string result = signature;
    return result;
}

void Wallet::deposit(float v){
    balance += v;
}

void Wallet::withdraw(float v){
    balance -= v;
}

float Wallet::getBalance(){
    float result = balance;
    return result;
}

void Wallet::generateAddress(){
    srand(time(0));
    static string data = "0123456789ABCDEF";
    int r;
    
    for(int i = 0; i < 20; i++){
        r = rand() % 16;
        address += data[r];
    }
}

void Wallet::generateSignature(){
    srand(time(0));
    static string data = "0123456789abcdefghijklmnopqrstuvwxyz";
    int r;
    
    for(int i = 0; i < 40; i++){
        r = rand() % 36;
        signature += data[r];
    }
}