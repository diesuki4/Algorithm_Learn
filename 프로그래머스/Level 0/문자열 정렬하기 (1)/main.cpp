#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(string my_string);

int main(int argc, char* argv[])
{
	print(solution("hi12392"));
	print(solution("p2o4i8gj2"));
	print(solution("abcde0"));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << ' ';
	cout << endl;
}

vector<int> solution(string my_string)
{
    multiset<int> answer;

	for_each(my_string.begin(), my_string.end(), [&answer](char c) { if (isdigit(c)) answer.insert(c - '0'); });

    return vector<int>(answer.begin(), answer.end());
}
