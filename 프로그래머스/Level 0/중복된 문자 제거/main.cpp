#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("people") << endl;
	cout << solution("We are the world") << endl;

	return 0;
}

string solution(string my_string)
{
    string answer = "";

	for_each(my_string.begin(), my_string.end(), [&answer](char c) { if (answer.find(c) == string::npos) answer += c; });

    return answer;
}
