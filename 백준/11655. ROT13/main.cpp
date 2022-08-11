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
		// char (-128 ~ 127) 범위를 넘어가는 문자가 있으므로 unsigned
		unsigned char uch = s[i] + n;

		// 더해서 'z' 혹은 'Z' 를 넘어가면 26을 빼주고
		// 넘어가지 않으면 그냥 대입한다.
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

	// ROT13 수행 후 출력
	cout << (s >> 13);

	return 0;
}
