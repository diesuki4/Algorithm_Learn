#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& result);
vector<int> solution(vector<vector<int>> score);

int main(int argc, char* argv[])
{
	print(solution({{80, 70}, {90, 50}, {40, 70}, {50, 80}}));
	print(solution({{80, 70}, {70, 80}, {30, 50}, {90, 100}, {100, 90}, {100, 100}, {10, 30}}));

	return 0;
}

void print(const vector<int>& result)
{
	for (const int& e : result)
		cout << e << ' ';
	cout << endl;
}

vector<int> solution(vector<vector<int>> score)
{
	vector<int> answer;
	vector<int> vec;

	for (vector<int>& v : score)
		vec.emplace_back(v[0] + v[1]);

	for (const int& e1 : vec)
	{
		int count = 0;

		for (const int& e2 : vec)
			count += (e1 < e2);

		answer.emplace_back(++count);
	}

	return answer;
}
