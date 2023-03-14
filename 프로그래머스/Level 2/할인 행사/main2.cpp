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
    unordered_map<string, int> umap;

    for (int i = 0; i < 9; ++i)
        ++umap[discount[i]];

    for (int i = 9; i < nDiscount; ++i)
    {
        bool bSuccess = true;

        ++umap[discount[i]];

        for (int j = 0; j < nWant; ++j)
        {
            if (umap[want[j]] != number[j])
            {
                bSuccess = false;
                break;
            }
        }

        if (bSuccess)
            ++answer;

        --umap[discount[i - 9]];
    }

    return answer;
}
