#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> emergency);

int main(int argc, char* argv[])
{
	print(solution({3, 76, 24}));
	print(solution({1, 2, 3, 4, 5, 6, 7}));
	print(solution({30, 10, 23, 6, 100}));
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << ' ';
	cout << endl;
}

vector<int> solution(vector<int> emergency)
{
	vector<int> answer;
	vector<int> v(emergency);

	sort(v.begin(), v.end());

	for (int e : emergency)
		answer.emplace_back(find(v.rbegin(), v.rend(), e) - v.rbegin() + 1);

	return answer;
}
