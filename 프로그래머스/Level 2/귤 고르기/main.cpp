#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine);

int main(int argc, char* argv[])
{
    cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << endl;
    cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << endl;
    cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << endl;

    return 0;
}

int solution(int k, vector<int> tangerine)
{
    int answer;
    unordered_map<int, int> umap;

    for (int e : tangerine)
        ++umap[e];

    vector<pair<int, int>> vec(umap.begin(), umap.end());
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a.second > b.second; });

    for (answer = 0; 0 < k; ++answer)
        k -= vec[answer].second;

    return answer;
}
