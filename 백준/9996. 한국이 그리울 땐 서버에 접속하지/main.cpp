#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	string pattern;
	string ptrnBegin, ptrnEnd;

	cin >> n >> pattern;
	pattern = regex_replace(pattern, regex("\\*"), ".*");

	ptrnBegin = "^" + pattern;
	ptrnEnd = pattern + "$";

	for (int i = 0; i < n; ++i)
	{
		string fileName;

		cin >> fileName;

		if (regex_search(fileName, regex(ptrnBegin)) &&
			regex_search(fileName, regex(ptrnEnd)))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}
