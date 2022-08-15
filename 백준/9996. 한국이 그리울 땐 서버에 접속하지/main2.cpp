#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	// 패턴이 ( ab*cd ) 일 때, ( ^ab.*cd$ ) 로 변경된다.
	string pattern;

	cin >> n >> pattern;

	pattern = regex_replace(pattern, regex("\\*"), ".*");
	pattern = "^" + pattern + "$";

	for (int i = 0; i < n; ++i)
	{
		string fileName;

		cin >> fileName;

		// regex_search 는 부분 문자열 (Substring) 의 일치도 확인하기 때문에
		// ^ 을 통해 시작을, $ 를 통해 끝을 명시해주어야 한다.
		if (regex_search(fileName, regex(pattern)))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
