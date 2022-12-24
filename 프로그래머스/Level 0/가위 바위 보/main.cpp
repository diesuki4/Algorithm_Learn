#include <iostream>
#include <algorithm>

using namespace std;

string solution(string rsp);

int main(int argc, char* argv[])
{
	cout << solution("2") << endl;
	cout << solution("205") << endl;

	return 0;
}

string solution(string rsp)
{
    transform(rsp.begin(), rsp.end(), rsp.begin(), [](char c) { return (c == '2') ? '0' : (c == '0') ? '5' : '2'; });

	return rsp;
}
