#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void print(vector<string> result);
vector<string> rDFS(string city, vector<string> answer, unordered_map<string, multiset<string>> graph, int nUsed, int nTickets);
vector<string> solution(vector<vector<string>> tickets);

int main(int argc, char* argv[])
{
    print(solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}));
    print(solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> rDFS(string city, vector<string> answer, unordered_map<string, multiset<string>> graph, int nUsed, int nTickets)
{
    answer.emplace_back(city);

    if (nTickets <= nUsed)
        return answer;

    for (string dest : graph[city])
    {
        unordered_map<string, multiset<string>> grp(graph);
        grp[city].erase(grp[city].find(dest));

        vector<string> result = rDFS(dest, answer, grp, nUsed + 1, nTickets);

        if (!result.empty())
            return result;
    }

    return {};
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    unordered_map<string, multiset<string>> graph;

    for (vector<string>& ticket : tickets)
        graph[ticket[0]].emplace(ticket[1]);

    return rDFS("ICN", answer, graph, 0, tickets.size());
}
