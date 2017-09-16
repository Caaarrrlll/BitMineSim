#include "Transaction.h"

using namespace std;

int Transaction::numTransactions = 0;

Transaction::Transaction(string f, string t, string s, float a){
	numTransactions++;
	id = numTransactions;
	amount = a;
	fromAddress = f;
	toAddress = t;
	signature = s;
	confirmed = false;
	removeFromPool = false;
}

Transaction::Transaction(Transaction &other){
	//numTransactions++;
	id = other.getId();
	amount = other.getAmount();
	fromAddress = other.getSenderAddress();
	toAddress = other.getRecipientAddress();
	signature = other.getSignature();
	confirmed = other.isConfirmed();
	removeFromPool = other.shouldRemoveFromPool();
}

int Transaction::getId(){
	int result = this->id;
	return result;
}

float Transaction::getAmount(){
	float result = this->amount;
	return result;
}

string Transaction::getRecipientAddress(){
	string result = this->toAddress;
	return result;
}

string Transaction::getSenderAddress(){
	string result = this->fromAddress;
	return result;
}

string Transaction::getSignature(){
	string result = this->signature;
	return result;
}

void Transaction::confirm(){
	this->confirmed = true;
}

bool Transaction::isConfirmed(){
	bool result = this->confirmed;
	return result;
}

void Transaction::setRemoveFromPool(bool r){
	this->removeFromPool = r;
}

bool Transaction::shouldRemoveFromPool(){
	bool result = this->removeFromPool;
	return result;
}