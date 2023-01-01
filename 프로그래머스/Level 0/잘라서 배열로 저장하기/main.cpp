#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> result);
vector<string> solution(string my_str, int n);

int main(int argc, char* argv[])
{
	print(solution("abc1Addfggg4556b", 6));
	print(solution("abcdef123", 3));

	return 0;
}

void print(vector<string> result)
{
	for (string s : result)
		cout << s << ' ';
	cout << endl;
}

vector<string> solution(string my_str, int n)
{
	vector<string> answer;
	string::iterator itbegin = my_str.begin();
	string::iterator itend = my_str.end();

	for (string::iterator it = itbegin; it < itend; it += n)
		answer.emplace_back(string(it, min(it + n, itend)));

    return answer;
}
