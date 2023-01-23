#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
	int answer = 0;
	unordered_map<int, int> umap;

	for (int num : array)
		++umap[num];

	unordered_map<int, int>::iterator maxIt = max_element(umap.begin(), umap.end(), [](auto& a, auto& b) { return a.second < b.second; });

	return count_if(umap.begin(), umap.end(), [maxIt](auto& a) { return a.second == maxIt->second; }) == 1 ? maxIt->first : -1;
}
