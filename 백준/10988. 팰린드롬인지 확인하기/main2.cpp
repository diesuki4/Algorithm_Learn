#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int i;
	int length, middle;
	string s;

	cin >> s;

	length = s.length();
	middle = length / 2;

	for (i = 0; (i < middle) && (s[i] == s[--length]); ++i);

	cout << (i == middle);

	return 0;
}
