#include <iostream>
#include <string>

#define NUM_OF_ALPHABETS 26

int main(int argc, char *argv[])
{
	std::string s;
	int arrNumEachAlphabet[NUM_OF_ALPHABETS] = {0};

	std::cin >> s;

	for (int i = 0; i < s.length(); ++i)
		++arrNumEachAlphabet[s[i] - 'a'];

	for (int i = 0; i < NUM_OF_ALPHABETS; ++i)
		std::cout << arrNumEachAlphabet[i] << " ";

	return 0;
}
