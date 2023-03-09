#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

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

pair<string, string> split(string report)
{
    istringstream iss(report);
    string reporter, reportee;

    iss >> reporter >> reportee;

    return {reporter, reportee};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    size_t size = id_list.size();
    vector<int> answer(size);
    unordered_set<string> report_unique;
    unordered_map<string, unsigned> user_id, report_count;

    for (int i = 0; i < size; ++i)
        user_id[id_list[i]] = i;

    for (string& rpt : report)
    {
        if (report_unique.find(rpt) == report_unique.end())
        {
            pair<string, string> info = split(rpt);

            report_unique.emplace(rpt);
            ++report_count[info.second];
        }
    }

    for (string rpt : report_unique)
    {
        pair<string, string> info = split(rpt);

        if (k <= report_count[info.second])
            ++answer[user_id[info.first]];
    }

    return answer;
}
