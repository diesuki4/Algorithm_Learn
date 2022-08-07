#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	string s, revers_s;
	int length, diff = 0;

	cin >> s;
	length = s.length();

	revers_s = s;
	reverse(revers_s.begin(), revers_s.end());

	for (int i = 0; i < length; ++i)
		diff += (s[i] != revers_s[i]);

	cout << (diff / 2);

	return 0;
}
