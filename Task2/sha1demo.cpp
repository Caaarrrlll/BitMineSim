#include <iostream>
#include <random>
#include <algorithm>  //for std::generate_n
#include "sha1.hpp"

using namespace std;

string to_hex(const string&);
string random_string( size_t );

int main()
{
	srand(0);
	
    string input = "sample text";

	//SHA-1 demo
    SHA1 checksum;
    checksum.update(input);
    const string hash = checksum.final();
    cout << "The SHA-1 of \"" << input << "\" is: " << hash << endl;
	
	//converting an ASCII string to its hexadecimal equivalent
	string hex_string = to_hex(input);
	cout << "The hexadecimal value of \"" << input << "\" is: " << hex_string << endl;
	
	//generating a random string
	cout << "Generating a random string: " << random_string(5) << endl;

    return 0;
}


//source: https://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
string to_hex(const string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}


//source: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
string random_string( size_t length )
{
	auto randchar = []() -> char
	{
		const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[ rand() % max_index ];
	};
	string str(length,0);
	generate_n( str.begin(), length, randchar );
	return str;
}