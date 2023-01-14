#include <iostream>

using namespace std;

int solution(string A, string B);

int main()
{
	cout << solution("hello", "ohell") << endl;
	cout << solution("apple", "elppa") << endl;
	cout << solution("atat", "tata") << endl;
	cout << solution("abc", "abc") << endl;
}

int solution(string A, string B)
{
	return (B + B).find(A);
}
