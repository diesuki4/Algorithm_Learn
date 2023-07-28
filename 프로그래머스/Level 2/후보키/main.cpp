#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <bitset>

using namespace std;
using bset = bitset<8>;

vector<vector<bool>> get_comb(int n, int r);
bset to_bitset(vector<bool>& v);
bool satisfy_minimality(vector<bset>& candidates, vector<bool>& comb);
bool is_candidate(vector<vector<string>>& relation, vector<bool>& comb);
int solution(vector<vector<string>> relation);

int main(int argc, char* argv[])
{
    cout << solution({{"100",  "ryan",   "music",    "2"},
                      {"200",  "apeach", "math",     "2"},
                      {"300",  "tube",   "computer", "3"},
                      {"400",  "con",    "computer", "4"},
                      {"500",  "muzi",   "music",    "3"},
                      {"600",  "apeach", "music",    "2"}});

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

bset to_bitset(vector<bool>& v)
{
    bset bs;

    for (int i = 0; i < v.size(); ++i)
        bs.set(i, v[i]);

    return bs;
}

bool satisfy_minimality(vector<bset>& candidates, vector<bool>& comb)
{
    bset bsA = to_bitset(comb);

    for (bset& bsB : candidates)
        if ((bsA & bsB) == bsB)
            return false;

    return true;
}

bool is_candidate(vector<vector<string>>& relation, vector<bool>& comb)
{
    unordered_set<size_t> uset;
    hash<string> hashFunc;

    for (vector<string>& record : relation)
    {
        string hashKey;

        for (int i = 0; i < comb.size(); ++i)
            hashKey += (comb[i]) ? record[i] : "";

        uset.emplace(hashFunc(hashKey));
    }

    return uset.size() == relation.size();
}

int solution(vector<vector<string>> relation)
{
    const int ROW = relation.size(), COL = relation.front().size();
    vector<bset> candidates;

    for (int r = 1; r <= COL; ++r)
        for (vector<bool>& comb : get_comb(COL, r))
            if (satisfy_minimality(candidates, comb) && is_candidate(relation, comb))
                candidates.emplace_back(to_bitset(comb));

    return candidates.size();
}
