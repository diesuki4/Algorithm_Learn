#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> players, vector<string> callings);

int main(int argc, char* argv[])
{
    print(solution({"mumu", "soe", "poe", "kai", "mine"}, {"kai", "kai", "mine", "mine"}));

    return 0;
}

void print(vector<string> result)
{
    for (string e : result)
        cout << e << ", ";

    cout << endl;
}

vector<string> solution(vector<string> players, vector<string> callings)
{
    unordered_map<string, int> umap;

    for (int i = 0; i < players.size(); ++i)
        umap[players[i]] = i;

    for (string calling : callings)
    {
        string& p1 = players[umap[calling] - 1];
        string& p2 = players[umap[calling]];

        swap(umap[p1], umap[p2]);
        swap(p1, p2);
    }

    return players;
}
