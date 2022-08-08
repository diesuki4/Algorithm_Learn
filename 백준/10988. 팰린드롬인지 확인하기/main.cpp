#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	string s, reverse_s; // 뒤집은 문자열

	// 문자열 입력
	cin >> s;

	reverse_s = s;

	// 입력된 문자열을 뒤집는다.
	reverse(reverse_s.begin(), reverse_s.end());
	
	// 같으면 true(1), 다르면 (0) 을 출력한다.
	cout << (s == reverse_s);

	return 0;
}
