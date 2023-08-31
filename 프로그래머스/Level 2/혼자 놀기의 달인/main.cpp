#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findRep(vector<int>& rep, int i, int& depth);
int solution(vector<int> cards);

int main(int argc, char* argv[])
{
    cout << solution({1, 2}) << endl;
    cout << solution({8, 6, 3, 7, 2, 5, 1, 4}) << endl;

    return 0;
}

int findRep(vector<int>& rep, int i, int& depth)
{
    if (rep[i] == i)
    {
        depth = max(1, depth);

        return i;
    }

    ++depth;

    int next = rep[i];
    rep[i] = i;

    return rep[i] = findRep(rep, next, depth);
}

int solution(vector<int> cards)
{
    size_t n = cards.size() + 1;
    vector<int> rep(n, 0), numbers;
    unordered_map<int, bool> group;

    copy(cards.begin(), cards.end(), rep.begin() + 1);

    for (int i = 1; i < n; ++i)
    {
        if (group[rep[i]] == false)
        {
            int nNum = 0;

            group[findRep(rep, i, nNum)] = true;
            numbers.emplace_back(nNum);
        }
    }

    sort(numbers.rbegin(), numbers.rend());

    return (numbers.size() <= 1) ? 0 : numbers[0] * numbers[1];
}
