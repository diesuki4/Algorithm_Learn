#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter);

int main(int argc, char* argv[])
{
	cout << solution("abcdef", "f") << endl;
	cout << solution("BCBdbe", "B") << endl;

	return 0;
}

string solution(string my_string, string letter)
{
	string answer = "";

    for_each(my_string.begin(), my_string.end(), [letter, &answer](char c) { if (c != letter[0]) answer += c; });

    return answer;
}
