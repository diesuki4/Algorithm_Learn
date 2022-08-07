#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int asteriskPos;
	string pattern;
	string subBegin, reverseEnd;
	
	cin >> n >> pattern;
	asteriskPos = pattern.find('*');

	subBegin = pattern.substr(0, asteriskPos);
	
	reverseEnd = pattern.substr(asteriskPos + 1);
	reverse(reverseEnd.begin(), reverseEnd.end());

	for (int i = 0; i < n; ++i)
	{
		string fileName, reverseName;

		cin >> fileName;

		reverseName = fileName;
		reverse(reverseName.begin(), reverseName.end());

		if (!fileName.find(subBegin) && !reverseName.find(reverseEnd) &&
				(subBegin + reverseEnd).length() <= fileName.length())
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
