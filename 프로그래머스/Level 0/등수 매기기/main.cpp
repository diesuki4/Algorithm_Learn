#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<float> vec1, vec2;

	for (const vector<int>& v : score)
		vec1.emplace_back((v[0] + v[1]) * 0.5);

	vec2 = vec1;
	sort(vec2.rbegin(), vec2.rend());

	for (const float& average : vec1)
		answer.emplace_back(find(vec2.begin(), vec2.end(), average) - vec2.begin() + 1);

	return answer;
}
