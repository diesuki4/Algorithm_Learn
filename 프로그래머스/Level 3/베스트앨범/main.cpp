#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> genres, vector<int> plays);

int main(int argc, char* argv[])
{
    print(solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    size_t N = genres.size();
    unordered_map<string, int> u1;
    unordered_map<string, vector<pair<int, int>>> u2;

    for (int i = 0; i < N; ++i)
    {
        u1[genres[i]] += plays[i];
        u2[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> v1(u1.begin(), u1.end());
    sort(v1.begin(), v1.end(), [](auto& pr1, auto& pr2) { return pr1.second > pr2.second; });
    
    for (auto& v2 : u2)
        sort(v2.second.begin(), v2.second.end(), [](auto& pr1, auto& pr2) { return pr1.first > pr2.first; });

    for (auto& pr : v1)
    {
        string& genre = pr.first;

        answer.emplace_back(u2[genre][0].second);

        if (2 <= u2[genre].size())
            answer.emplace_back(u2[genre][1].second);
    }

    return answer;
}
