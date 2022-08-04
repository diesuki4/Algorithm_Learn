#include <iostream>

#define NUM_OF_ALPHABETS ('z' - 'a' + 1)

int main(int argc, char* argv[])
{
	std::string str;
	int numEachAlphabet[NUM_OF_ALPHABETS] = {0};

	std::cin >> str;

	for (char alphabet : str)
		++numEachAlphabet[alphabet - 'a'];

	for (int i = 0; i < NUM_OF_ALPHABETS; ++i)
		std::cout << numEachAlphabet[i] << " ";

	return 0;
}
