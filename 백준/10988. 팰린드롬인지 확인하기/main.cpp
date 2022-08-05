#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	string s, reverse_s;

	cin >> s;

	reverse_s = s;
	reverse(reverse_s.begin(), reverse_s.end());
	
	cout << (s == reverse_s);

	return 0;
}
