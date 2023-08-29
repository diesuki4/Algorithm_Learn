#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(vector<string> result);
struct Plan;
vector<string> solution(vector<vector<string>> plans);

int main(int argc, char* argv[])
{
    print(solution({{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}}));
    print(solution({{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}}));
    print(solution({{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

struct Plan
{
    string name;
    int start;
    int playtime;

    Plan() : name(""), start(0), playtime(0) {}

    Plan(vector<string>& plan)
    {
        name = plan[0];
        start = 60 * stoi(plan[1].substr(0, 2)) + stoi(plan[1].substr(3));
        playtime = stoi(plan[2]);
    }

    friend bool operator < (const Plan& A, const Plan& B) { return A.start > B.start; }
};

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    priority_queue<Plan> prQue;
    stack<Plan> pending;

    for (vector<string>& plan : plans)
        prQue.emplace(plan);

    while (!prQue.empty())
    {
        Plan current = prQue.top(); prQue.pop();

        if (prQue.empty())
        {
            answer.emplace_back(current.name);
            break;
        }

        int current_endtime = current.start + current.playtime;
        Plan next = prQue.top();

        if (current_endtime <= next.start)
        {
            answer.emplace_back(current.name);

            int remain = next.start - current_endtime;

            while (!pending.empty() && (0 < remain))
            {
                int t_playtime = pending.top().playtime;

                pending.top().playtime -= remain;
                remain -= t_playtime;

                if (pending.top().playtime <= 0)
                    answer.emplace_back(pending.top().name),
                    pending.pop();
            }
        }
        else
        {
            current.playtime = current_endtime - next.start;
            pending.emplace(current);
        }
    }

    while (!pending.empty())
        answer.emplace_back(pending.top().name),
        pending.pop();

    return answer;
}
