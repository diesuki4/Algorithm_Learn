#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int numAlpha[26] = {0};
	bool isPredaja = true;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;

		cin >> s;

		++numAlpha[s[0] - 'a'];
	}

	for (int i = 0; i < 26; ++i) {
		if (5 <= numAlpha[i]) {
			cout << static_cast<char>('a' + i);
			isPredaja = false;
		}
	}

	if (isPredaja)
		cout << "PREDAJA";

	return 0;
}
