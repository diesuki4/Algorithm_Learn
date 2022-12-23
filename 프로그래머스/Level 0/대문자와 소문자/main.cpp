#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("cccCCC") << endl;
	cout << solution("abCdEfghIJ") << endl;

	return 0;
}

string solution(string my_string)
{
	transform(my_string.begin(), my_string.end(), my_string.begin(), [](char c) { return islower(c) ? toupper(c) : tolower(c); });

    return my_string;
}
