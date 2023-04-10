#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes);

int main(int argc, char* argv[])
{
    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    cout << solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;

    return 0;
}

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> umap;

    for (vector<string> clothe : clothes)
        ++umap[clothe[1]];

    for (auto& pr : umap)
        answer *= pr.second + 1;

    return answer - 1;
}
