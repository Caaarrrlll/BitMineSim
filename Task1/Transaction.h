#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction{
	private:
		int id;
		float amount;
		string fromAddress;
		string toAddress;
		string signature;
		bool confirmed;
		bool removeFromPool;
		static int numTransactions;

	public:
		Transaction(string f, string t, string s, float a);
		Transaction(Transaction &other);
		int getId();
		float getAmount();
		string getRecipientAddress();
		string getSenderAddress();
		string getSignature();
		void confirm();
		bool isConfirmed();
		void setRemoveFromPool(bool r);
		bool shouldRemoveFromPool();
};

#endif
