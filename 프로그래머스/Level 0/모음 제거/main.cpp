#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("bus") << endl;
	cout << solution("nice to meet you") << endl;

	return 0;
}

string solution(string my_string)
{
	string vowels = "aeiou";
    string answer = "";

	for_each(my_string.begin(), my_string.end(), [vowels, &answer](char c) { if (vowels.find(c) == string::npos) answer += c; });

    return answer;
}
