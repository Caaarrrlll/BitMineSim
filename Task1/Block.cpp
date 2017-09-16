#include "Block.h"

using namespace std;

Block::Block(int i, string prevh, string n){
	id = i;
	txCount = 0;
	txList = new Transaction*[MAX_TX];
	/*for(int i = 0; i < MAX_TX; i++)
		txList[i] = nullptr;*/
	blockHash = "";
	prevBlockHash = prevh;
	minerName = n;
	confirmed = false;
}

Block::Block(Block &other){
	id = other.getId();
	txCount = other.getNumTransactions();
	txList = new Transaction*[MAX_TX];
	for(int i = 0; i < other.txCount; i++){
		Transaction * tnew = new Transaction(*(other.getTransaction(i)));
		txList[i] = tnew;
		//txList[i].confirm();
	}
	blockHash = other.getBlockHash();
	prevBlockHash = other.getPreviousBlockHash();
	minerName = other.getMinerName();
	confirmed = other.isConfirmed();
}

Block::~Block(){
	/*for(int i = 0; i < MAX_TX; i++)
		delete txList[i];*/
	delete [] txList;
	txList = NULL;
}

int Block::getId(){
	int result = this->id;
	return result;
}

bool Block::canAddTransaction(){
	if(txCount >= MAX_TX)
		return false;
	else 
		return true;
}

void Block::addTransaction(Transaction* t){
	if(canAddTransaction()){
		Transaction * temp = new Transaction(*t);
		txList[txCount] = temp;
		txCount++;
	}
	else{
		cout << "Maximum entries of transactions reached. The block cannot accept any more transactions.\n";
	}
}

void Block::addTransaction(string f, string t, string s, float a){
	if(canAddTransaction()){
		Transaction *newT = new Transaction(f,t,s,a);
		txList[txCount] = newT;
		txCount++;
	}
	else{
		cout << "Maximum entries of transactions reached. The block cannot accept any more transactions.\n";
	}
}

Transaction* Block::getTransaction(int i){
	if((i < 0)||(i > txCount)){
		cout << "Block transaction retrieval unsuccessful: index out of bounds.\n";
		return nullptr;
	}
	else{
		return txList[i];
	}
}

int Block::getNumTransactions(){
	int result = this->txCount;
	return result;
}

void Block::setBlockHash(string h){
	blockHash = h;
}

string Block::getBlockHash(){
	string result = this->blockHash;
	return result;
}

string Block::getPreviousBlockHash(){
	string result = this->prevBlockHash;
	return result;
}

string Block::getMinerName(){
	string result = this->minerName;
	return result;
}

void Block::confirm(){
	confirmed = true;
	for(int j = 0; j < txCount; j++){
		txList[j]->confirm();
	}
}

bool Block::isConfirmed(){
	bool result = this->confirmed;
	return result;
}

void Block::printBlockSummary(){
	//cout << ;
	cout << "Block Summary (ID: " << getId() << ")\n--------------------------------------------------------\n";
	cout << left << setw(6) << setfill(' ') << "TxID" 
		 << left << setw(8) << setfill(' ') << "Amount" 
		 << left << setw(22) << setfill(' ') << "From"
		 << left << setw(22) << setfill(' ') << "To" << endl;
	cout << "--------------------------------------------------------" << endl;
	for(int i = 0; i < txCount; i++){
		cout << fixed << setprecision(3) << left << setw(6) << setfill(' ') << txList[i]->getId() 
			 << left << setw(8) << setfill(' ') << txList[i]->getAmount() 
			 << left << setw(22) << setfill(' ') << txList[i]->getSenderAddress() 
			 << left << setw(22) << setfill(' ') << txList[i]->getRecipientAddress() << endl;
	}
}
