#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <random>
#include <algorithm> 
#include "sha1.hpp"

using namespace std;

class Crypto {
	public:
		static string sha1hash(string s);
		static string sha1hash(int v);
		static string strtohex(string s, bool u = true);
		static string random_string(int l);
};

#endif