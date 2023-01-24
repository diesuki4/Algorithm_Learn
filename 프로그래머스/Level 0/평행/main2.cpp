#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<vector<int>> dots);

int main(int argc, char* argv[])
{
	cout << solution({{1, 4}, {9, 2}, {3, 8}, {11, 6}}) << endl;
	cout << solution({{3, 5}, {4, 1}, {2, 4}, {5, 10}}) << endl;

	return 0;
}

int solution(vector<vector<int>> dots)
{
	unordered_set<float> grad;
	int occur = dots.size() * (dots.size() - 1) / 2;

	for (auto it = dots.begin(); it < dots.end() - 1; ++it)
	{
		for (auto jt = it + 1; jt < dots.end(); ++jt)
		{
			float x1 = (*it)[0], y1 = (*it)[1];
			float x2 = (*jt)[0], y2 = (*jt)[1];

			grad.emplace((y2 - y1) / (x2 - x1));
		}
	}

	return grad.size() != occur;
}
