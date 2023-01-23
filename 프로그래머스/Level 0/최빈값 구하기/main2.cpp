#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array);

int main(int main, char* argv[])
{
	cout << solution({1, 2, 3, 3, 3, 4}) << endl;
	cout << solution({1, 1, 2, 2}) << endl;
	cout << solution({1}) << endl;
}

int solution(vector<int> array)
{
	int answer = 0, maxCount = 0;
	unordered_map<int, int> umap;

	for (int num : array)
		++umap[num];

	for (pair<int, int> pr : umap)
	{
		if (pr.second == maxCount)
		{
			answer = -1;
		}
		else if (maxCount < pr.second)
		{
			maxCount = pr.second;
			answer = pr.first;
		}
	}

	return answer;
}
