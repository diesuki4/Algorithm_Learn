#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	// * 의 위치
	int asteriskPos;
	// 패턴이 ( ab*bc ) 일 때
	string pattern;
	// ( ab ), ( cb ) 를 저장한다.
	string subBegin, reverseEnd;
	
	cin >> n >> pattern;
	asteriskPos = pattern.find('*');

	subBegin = pattern.substr(0, asteriskPos);
	
	reverseEnd = pattern.substr(asteriskPos + 1);
	reverse(reverseEnd.begin(), reverseEnd.end());

	for (int i = 0; i < n; ++i)
	{
		// 파일 이름, 역순으로 뒤집은 파일 이름
		string fileName, reverseName;

		cin >> fileName;

		reverseName = fileName;
		reverse(reverseName.begin(), reverseName.end());

		// 파일 이름이 ab 로 시작하고
		// 역순 파일 이름이 cb 로 시작하고
		// 문자열 내에서 패턴이 겹치지 않으면
		// [ab]ooo[bc]	(O)
		// [a[b]c]		(X)
		if (!fileName.find(subBegin) && !reverseName.find(reverseEnd) &&
				(subBegin + reverseEnd).length() <= fileName.length())
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
