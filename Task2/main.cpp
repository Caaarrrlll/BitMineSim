//#include "Transaction.h"
//#include "Block.h"
#include "Crypto.h"
#include "Wallet.h"

using namespace std;

int main(){
	/*//Transaction functions
	Transaction t1("6231765A68377A457539", "5A37567247326C53766F", "15b9888778e4e76fa834636762de081d3bbae747", 7.75519);
	Transaction t2("724D7137587846527438", "686B46675A7872554F6A", "be67ca4a6819069739df5ba2b9a5d250d670382a", 7.46612);
	Transaction t3("68695035416F66345234", "37714D61574D506A434F", "ce95c6a48cf6e8378120b3911d8a43c7b90001c6", 8.23504);
	Transaction t4("704E7A306B7A614F7676", "7948306D384B30564D30", "61f10ce7f72f6c63b2a0fd84bd1bd7536c840ffe", 6.75946);
	Transaction t5("4C413378564C34574C58", "6C665057616135456448", "d6404f88e971906c59ea82a738ff3c298004b09d", 0.998168);

	cout << "IDs" << endl;
	cout << t1.getId() << endl;
	cout << t2.getId() << endl;
	cout << t3.getId() << endl << endl;
	//cout << t4.getId() << endl << endl;

	cout << "getAmount" << endl;
	cout << t1.getAmount() << endl;
	cout << t2.getAmount() << endl;
	cout << t3.getAmount() << endl << endl;

	cout << "recipients" << endl;
	cout << t1.getRecipientAddress() << endl;
	cout << t2.getRecipientAddress() << endl;
	cout << t3.getRecipientAddress() << endl << endl;

	cout << "senders" << endl;
	cout << t1.getSenderAddress() << endl;
	cout << t2.getSenderAddress() << endl;
	cout << t3.getSenderAddress() << endl << endl;

	cout << "signatures" << endl;
	cout << t1.getSignature() << endl;
	cout << t2.getSignature() << endl;
	cout << t3.getSignature() << endl << endl;

	cout << "confirm" << endl;
	t1.confirm();
	cout << t1.isConfirmed() << endl;
	cout << t2.isConfirmed() << endl;
	cout << t3.isConfirmed() << endl << endl;

	cout << "should remove" << endl;
	t1.setRemoveFromPool(true);
	cout << t1.shouldRemoveFromPool() << endl;
	cout << t2.shouldRemoveFromPool() << endl;
	cout << t3.shouldRemoveFromPool() << endl << endl;
	
	//Block Functions
	Block b1(1, "5A747A716E386E705970", "Koos");
	b1.addTransaction(&t1);
	b1.addTransaction(&t2);
	b1.addTransaction(&t3);
	b1.addTransaction(&t4);
	b1.addTransaction(&t5);

	b1.printBlockSummary();

	Block b2(b1);
	b2.printBlockSummary();

	//block ids
	cout << endl << "block IDs" << endl;
	cout << b1.getId() << endl;
	cout << b2.getId() << endl;

	//canadd 
	cout << endl << "can add transacts" << endl;
	cout << b1.canAddTransaction() << endl;
	cout << b2.canAddTransaction() << endl;
	//b1.addTransaction(&t5);
	//b2.addTransaction(&t5);

	//numtransactions
	cout << endl << "get num transactions" << endl;
	cout << b1.getNumTransactions() << endl;
	cout << b2.getNumTransactions() << endl;

	//set block hash
	cout << endl << "set block hash to 1234567890" << endl;
	b1.setBlockHash("1234567890");
	cout << b1.getBlockHash() << endl;
	cout << b2.getBlockHash() << endl;*/

	//crypto class
	cout << "Crypto Class" << endl;
	srand(time(0));
	int random = 10;
	string s = "Random String";//52616E646F6D20537472696E67
	string h;
	Crypto c;

	//sha1hash(string use)
	cout << "Sha1(string use)" << endl;
	h = c.sha1hash(s);
	cout << h << endl;

	//sha1hash(int use)
	cout << endl << "Sha1(int use)" << endl;
	h = c.sha1hash(random);
	cout << h << endl;

	//caps hex Random String = 52616E646F6D20537472696E67
	cout << endl << "Caps hex of za" << endl;
	h = c.strtohex(s, true);
	cout << h << endl;

	//noncaps hex Random String = 52616e646f6d20537472696e67
	cout << endl << "Noncaps hex of za" << endl;
	h = c.strtohex(s, false);
	cout << h << endl;

	//random length string
	cout << endl << "length of your random string: ";
	cin >> random;
	h = c.random_string(random);
	cout << h << endl << endl;

	//wallet functions
	cout << "Wallet Functions" << endl;
	Wallet w;

	//deposit
	w.deposit(25.50);
	cout << "Balance: " << w.getBalance() << endl;
	w.withdraw(10.25);
	cout << "Balance: " << w.getBalance() << endl;

	//generate address
	//w.generateAddress();
	cout << endl << "Address: " << w.getAddress() << endl;

	//generate signature
	//w.generateSignature();
	cout << endl << "Signature: " << w.getSignature() << endl;

	/*cout << endl << "Crypto Fitch" << endl;
	cout << "sha1hash(string)" << endl;
	cout << Crypto::sha1hash("sample1") << endl;

	cout << endl << "sha1hash(int)" << endl;
	cout << Crypto::sha1hash(55) << endl;

	cout << endl << "string to hex" << endl;
	cout << Crypto::strtohex("sample1") << endl;

	cout << endl << "Random length" << endl;
	cout << Crypto::random_string(5) << endl;*/

	return 0;
}

//c573cc15887b92715a4dcd0e403f9b0a78c8d4c6
//D3E0028433D3E0028433
//BJ3K7XBZQY2WSC41YNMSBJ3K7XBZQY2WSC41YNMS
//9BDA59BDA5
//BACC560A1DBACC560A1D
//6133777064686A6F7871