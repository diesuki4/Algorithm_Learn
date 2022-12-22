#include <iostream>
#include <numeric>

using namespace std;

int solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("aAb1B2cC34oOp") << endl;
	cout << solution("1a2b3c4d123") << endl;

	return 0;
}

int solution(string my_string)
{
    return accumulate(my_string.begin(), my_string.end(), 0, [](int a, char b) { return isdigit(b) ? a + b - '0' : a; });
}
