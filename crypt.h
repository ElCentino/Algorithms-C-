#pragma once
#include <iostream>
#include <string>

using namespace std;

class crypt
{
public:
	crypt();
	~crypt();
	int BruteForkey(string, string, int, int, int, int);
	string XOR(string, char[]);
	string IXOR(string, int);

private:

	
	
	void BruteForKey(string, int, int, bool);
	

};

