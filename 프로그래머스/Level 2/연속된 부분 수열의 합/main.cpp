// 이 풀이는 시간 초과가 발생한다.
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
    map<int, set<vector<int>>> mp;
    size_t size = sequence.size();

    for (int i = 0; i < size; ++i)
    {
        int sum = 0;

        for (int j = i; j < size; ++j)
        {
            sum += sequence[j];

            if (sum == k)
                mp[j - i].emplace(vector<int> {i, j});

            if (k <= sum)
                break;
        }
    }

    return *mp.begin()->second.begin();
}
