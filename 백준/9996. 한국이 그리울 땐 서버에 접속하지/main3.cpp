#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	// 패턴이 ( ab*cd ) 일 때, ( ab.*cd ) 로 변경된다.
	string pattern;

	cin >> n >> pattern;

	pattern = regex_replace(pattern, regex("\\*"), ".*");

	for (int i = 0; i < n; ++i)
	{
		string fileName;

		cin >> fileName;

		// regex_match 는 부분 문자열 (Substring) 에 대한 검사 없이
		// 전체 문자열에 대해서만 검사하므로
		// ( ab*cd ) 와 같이 사용해도 된다.
		if (regex_match(fileName, regex(pattern)))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
