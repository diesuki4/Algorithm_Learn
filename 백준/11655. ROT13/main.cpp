#include <iostream>
#include <string>

using namespace std;

string operator >> (string s, int n)
{
	int length = s.length();

	for (int i = 0; i < length; ++i)
	{
		unsigned char uch = s[i] + n;

		if ('N' <= uch)
			 s[i] = (uch <= 'Z') || (('n' <= uch) && (uch <= 'z')) ?
						uch : uch - 26;
	}

	return s;
}

int main(int argc, char* argv[])
{
	string s;

	getline(cin, s);

	cout << (s >> 13);

	return 0;
}
