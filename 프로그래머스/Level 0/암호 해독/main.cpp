#include <iostream>

using namespace std;

string solution(string cipher, int code);

int main(int argc, char* argv[])
{
	cout << solution("dfjardstddetckdaccccdegk", 4) << endl;
	cout << solution("pfqallllabwaoclk", 2) << endl;

	return 0;
}

string solution(string cipher, int code)
{
    string answer = "";

	for (string::iterator it = cipher.begin() + code - 1; it < cipher.end(); it += code)
		answer += *it;

    return answer;
}
