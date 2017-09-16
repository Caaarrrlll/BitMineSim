#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <iomanip>
#include "Transaction.h"

using namespace std;

class Block {
	private:
		int id;
		int txCount;
		const int MAX_TX = 5;
		Transaction** txList;
		string blockHash;
		string prevBlockHash;
		string minerName;
		bool confirmed;
	
	public:
		Block(int i, string prevh, string n);
		Block(Block &other);
		~Block();
		int getId();
		bool canAddTransaction();
		void addTransaction(Transaction* t);
		void addTransaction(string f, string t, string s, float a);
		Transaction* getTransaction(int i);
		int getNumTransactions();
		void setBlockHash(string h);
		string getBlockHash();
		string getPreviousBlockHash();
		string getMinerName();
		void confirm();
		bool isConfirmed();
		void printBlockSummary();
};

#endif