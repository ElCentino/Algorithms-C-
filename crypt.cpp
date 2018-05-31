#include "crypt.h"

static int bruteIteration;
static string appended;
static string ciphertext;
static string deciphertext;
static int key;

crypt::crypt()
{

	bruteIteration = 0;
	appended = "";
	ciphertext = "";
	deciphertext = "";
}

crypt::~crypt()
{

}

string crypt::XOR(string data, char key[])
{
	string xorstring = data;

	for (int i = 0; i < xorstring.size(); i++) {
		xorstring[i] = data[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}

	return xorstring;
}

string crypt::IXOR(string data, int key)
{
	string xorstring = data;

	for (int i = 0; i < xorstring.size(); i++) {
		xorstring[i] = data[i] ^ key;
	}

	return xorstring;
}

void crypt::BruteForKey(string text, int left, int right, bool uCheck)
{
	if (left >= right)
	{
		return;
	}

	bruteIteration++;

	char lalpha[43] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '"', ',', '.', '?', ':', ';' };

	char ualpha[43] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '"', ',', '.', '?', ':', ';' };

	string ciphertext = "";
	string deciphertext = "";

	for (int i = left; i < text.size(); i++)
	{
		if (appended == text)
		{
			return;
		}

		for (int j = 0; j < 27; j++)
		{
			if (lalpha[j] == text[i])
			{
				left++;
				appended += lalpha[j];

				BruteForKey(text, left, right, uCheck);

				break;
			}

			if (uCheck)
			{
				if (ualpha[j] == text[i])
				{
					left++;
					appended += ualpha[j];

					BruteForKey(text, left, right, uCheck);

					break;
				}
			}

			std::cout << "At iteration : " << bruteIteration << endl;

			bruteIteration++;
		}
	}

	cout << "Key used is " << bruteIteration << endl;

	if (appended == text)
	{
		std::cout << "Encrypting text" << endl;

		ciphertext = IXOR(appended, bruteIteration);

		std::cout << "Text encrypted" << endl;

		std::cout << endl;

		//std::cout << "Plain text is : " << text << endl;
		std::cout << "Ciphertext is : " << ciphertext << endl;

		deciphertext = IXOR(ciphertext, bruteIteration);

		std::cout << "Key is : " << bruteIteration << endl;

		std::cout << "Decrypted text is : " << deciphertext << endl;

		ciphertext = ciphertext;
		deciphertext = deciphertext;
	}

	else
	{
		cout << "Problem somewhere" << endl;
		left = right + 1;
		return;
	}


}

int crypt::BruteForkey(string originalText, string ciphertext, int tempkey, int tempRange = 100, 
						int possibleKeyRange = 100, int keyStart = 0)
{
	static int posibleRange;
	static int posibleKey = tempkey;
	static bool keyFound = false;

	string decryptedText = "";

	for (int i = keyStart; i < possibleKeyRange; i++)
	{
		if (!keyFound && possibleKeyRange > tempRange)
		{
			int newKeyRange = possibleKeyRange += 200;

			return BruteForkey(originalText, ciphertext, tempkey, tempRange, newKeyRange, newKeyRange - 200);

		}

		else if (possibleKeyRange >= 210)
		{
			cout << "Cant continue key not found at this point" << endl;
			return -1;
		}

		else
		{
			cout << "Trying key : " << posibleKey << endl;

			decryptedText = IXOR(ciphertext, posibleKey);

			if (originalText == decryptedText)
			{
				cout << "Key Found : " << posibleKey << endl;

				cout << "The text is : " << decryptedText << endl;

				return posibleKey;

			}

			else
			{
				cout << posibleKey << " Failed!!!, trying new one" << endl;

				return BruteForkey(originalText, ciphertext, posibleKey++);
			}
		}
	}
}
