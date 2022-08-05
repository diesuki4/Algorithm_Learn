#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string operator >> (string &s, int n)
{
	char new_s[101] = {0};
	int length = s.length();

	strncpy(new_s, s.c_str(), length);

	for (int i = 0; i < length; ++i)
	{
		char ch = s[i];
		unsigned char new_uch = ch + n;

		if ('A' <= ch && ch <= 'Z')
			new_s[i] = ('Z' < new_uch) ? (new_uch - 26) : (new_uch);
		else if ('a' <= ch && ch <= 'z')
			new_s[i] = ('z' < new_uch) ? (new_uch - 26) : (new_uch);
	}

	return string(new_s);
}

int main(int argc, char* argv[])
{
	string s;

	getline(cin, s);

	cout << (s >> 13);

	return 0;
}
