#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int asteriskPos;
	string pattern;
	string subBegin, subEnd;

	cin >> n >> pattern;
	asteriskPos = pattern.find('*');

	subBegin = pattern.substr(0, asteriskPos);
	subEnd = pattern.substr(asteriskPos + 1);

	for (int i = 0; i < n; ++i)
	{
		string fileName;

		cin >> fileName;

		if (regex_match(fileName, regex(subBegin + ".*" + subEnd)))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
