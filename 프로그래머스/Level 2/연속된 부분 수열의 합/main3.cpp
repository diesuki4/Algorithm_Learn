#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> sequence, int k);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 4, 5}, 7));
    print(solution({1, 1, 1, 2, 3, 4, 5}, 5));
    print(solution({2, 2, 2, 2, 2}, 6));
    print(solution({3, 3, 3, 3}, 3));
    print(solution({7, 5, 5, 1, 1, 50, 50}, 100));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> sequence, int k)
{
    int l = 0, r = -1;
    int sum = 0;
    size_t size = sequence.size();
    map<int, set<vector<int>>> mp;

    do
    {
        if (sum < k && ++r < size)
            sum += sequence[r];
        else
            sum -= sequence[l++];

        if (sum == k)
            mp[r - l].emplace(vector<int> {l, r});
    }
    while (r < size && l < size);

    return *mp.begin()->second.begin();
}
