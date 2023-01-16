#include <iostream>
#include <algorithm>

using namespace std;

int solution(string A, string B);

int main(int argc, char* argv[])
{
	cout << solution("hello", "ohell") << endl;
	cout << solution("apple", "elppa") << endl;
	cout << solution("atat", "tata") << endl;
	cout << solution("abc", "abc") << endl;
}

int solution(string A, string B)
{
	int length = A.length();

	for (int i = 0; i < length; ++i, rotate(A.begin(), A.end() - 1, A.end()))
		if (A == B) return i;

	return -1;
}
