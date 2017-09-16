#include "Crypto.h"

using namespace std;

string Crypto::sha1hash(string s){
	SHA1 converter;

	converter.update(s);
	string result = converter.final();

	return result;
}

string Crypto::sha1hash(int v){
	string result = "";

	result = to_string(v);
	result = sha1hash(result);

	return result;
}

string Crypto::strtohex(string s, bool u){
	ostringstream str;

	if(u){
		for(unsigned int i = 0; i < s.length(); i++)
			str << hex << uppercase << (int)s[i];
	}
	else{
		for(unsigned int i = 0; i < s.length(); i++)
			str << hex << nouppercase << (int)s[i];
	}

	return str.str();
}

string Crypto::random_string(int l){
	/*string data = "ABCDEFGHIJKLMNOPQRSTUVWXYX0123456789abcdefghijklmnopqrstuvwxyz";
	string result = "";
	int r;

	for(int i = 0; i < l; i++){
		r = rand() % 62;
		result += data[r];
	}*/

	auto randchar = []() -> char
	{
		const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
		const int size = (sizeof(charset) - 1);
		return charset[ rand() % size ];
	};
	string result(l,0);
	generate_n( result.begin(), l, randchar );

	return result;
}