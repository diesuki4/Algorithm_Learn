#include <iostream>
#include <string>

using namespace std;

// (문자열 >> 정수) 형식의 연산을 오버로딩 한다.
// string ROT13(string s, int n) 과 동일
string operator >> (string s, int n)
{
	int length = s.length();

	for (int i = 0; i < length; ++i)
	{
		char ch = s[i];

		// 13을 더했을 때 'z' 혹은 'Z' 를 넘지 않는 알파벳은 13을 더해주고
		// 넘어가면 13을 빼준다.
		if ('A' <= ch)
			 s[i] = (ch <= 'M') || (('a' <= ch) && (ch <= 'm')) ?
						ch + n : ch - n;
	}

	return s;
}

int main(int argc, char* argv[])
{
	string s;

	getline(cin, s);

	// ROT13 수행 후 출력
	cout << (s >> 13);

	return 0;
}
