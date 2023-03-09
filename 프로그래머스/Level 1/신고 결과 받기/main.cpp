#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct user;

void print(vector<int> result);
pair<string, string> split(string report);
vector<int> solution(vector<string> id_list, vector<string> report, int k);

int main(int argc, char* argv[])
{
    print(solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2));
    print(solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

struct user
{
    unordered_set<user*> reports;
    unordered_set<user*> reported;
    bool bSuspended;
};

pair<string, string> split(string report)
{
    size_t blank_pos = report.find(' ');

    return {report.substr(0, blank_pos), report.substr(blank_pos + 1)};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    size_t size = id_list.size();
    vector<int> answer(size);
    unordered_map<string, user> users;

    for (string id : id_list)
        users[id] = user{unordered_set<user*>(), unordered_set<user*>(), false};

    for (string rpt : report)
    {
        pair<string, string> pr = split(rpt);

        users[pr.first].reports.emplace(&users[pr.second]);
        users[pr.second].reported.emplace(&users[pr.first]);

        if (k <= users[pr.second].reported.size())
            users[pr.second].bSuspended = true;
    }

    for (int i = 0; i < size; ++i)
    {
        unordered_set<user*> reports = users[id_list[i]].reports;

        answer[i] = count_if(reports.begin(), reports.end(), [](user* u) { return u->bSuspended; });
    }

    return answer;
}
