// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<bool>> get_comb(int n, int r);
long long solution(vector<int> weights);

int main(int argc, char* argv[])
{
    cout << solution({100, 180, 360, 100, 270}) << endl;

    return 0;
}

vector<vector<bool>> get_comb(int n, int r)
{
    vector<vector<bool>> result;
    vector<bool> comb(n, 0);

    fill_n(comb.rbegin(), r, 1);

    do
        result.emplace_back(comb);
    while (next_permutation(comb.begin(), comb.end()));

    return result;
}

long long solution(vector<int> weights)
{
    long long answer = 0;
    size_t n = weights.size();
    vector<vector<int>> newtons(n);

    for (int i = 0; i < n; ++i)
    {
        newtons[i].emplace_back(weights[i] * 2);
        newtons[i].emplace_back(weights[i] * 3);
        newtons[i].emplace_back(weights[i] * 4);
    }

    for (vector<bool>& comb : get_comb(n, 2))
    {
        set<int> st;

        for (int i = 0; i < n; ++i)
        {
            if (comb[i])
            {
                st.emplace(newtons[i][0]);
                st.emplace(newtons[i][1]);
                st.emplace(newtons[i][2]);
            }
        }

        answer += (st.size() < 6);
    }

    return answer;
}
