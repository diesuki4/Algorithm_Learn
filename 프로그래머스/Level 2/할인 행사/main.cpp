#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount);

int main(int argc, char* argv[])
{
    cout << solution({"banana", "apple", "rice", "pork", "pot"}, {3, 2, 2, 2, 1},
                     {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"}) << endl;
    
    cout << solution({"apple"}, {10},
                     {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"}) << endl;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    size_t nDiscount = discount.size(), nWant = want.size();
    unordered_map<string, vector<int>> umap;

    for (int i = 1; i <= nDiscount; ++i)
    {
        string& item = discount[i - 1];

        if (umap.find(item) == umap.end())
            umap[item] = vector<int>(nDiscount + 1, 0);

        for (auto& pr : umap)
            pr.second[i] = pr.second[i - 1];

        ++umap[item][i];
    }

    for (int i = 0; i <= nDiscount - 10; ++i)
    {
        bool bSuccess = true;

        for (int j = 0; j < nWant; ++j)
        {
            string& item = want[j];

            if (umap.find(item) == umap.end() ||
                umap[item][i + 10] - umap[item][i] != number[j])
            {
                bSuccess = false;
                break;
            }
        }

        if (bSuccess)
            ++answer;
    }

    return answer;
}
