#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::string str;

	std::cin >> str;

	for (char alphabet = 'a'; alphabet <= 'z'; ++alphabet)
		std::cout << count(str.begin(), str.end(), alphabet) << " ";

	return 0;
}
