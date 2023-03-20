#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> record);

int main(int argc, char* argv[])
{
    print(solution({"Enter uid1234 Muzi",
                    "Enter uid4567 Prodo",
                    "Leave uid1234",
                    "Enter uid1234 Prodo",
                    "Change uid4567 Ryan"}));

    return 0;
}

void print(vector<string> result)
{
    for (string s : result)
        cout << s << endl;

    cout << endl;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<pair<char, string>> op_uid;
    unordered_map<string, string> uid_name;

    for (string rec : record)
    {
        string op, uid, name;
        istringstream iss(rec);

        iss >> op >> uid >> name;

        switch (op[0])
        {
        case 'E':
        {
            uid_name[uid] = name;
            op_uid.emplace_back(pair<char, string>('E', uid));

            break;
        }
        case 'L':
        {
            op_uid.emplace_back(pair<char, string>('L', uid));

            break;
        }
        case 'C':
        {
            uid_name[uid] = name;

            break;
        }
        }
    }

    for (pair<char, string>& pr : op_uid)
        answer.emplace_back(uid_name[pr.second] + "님이 " +
                            (pr.first == 'E' ? "들어왔" : "나갔") + "습니다.");

    return answer;
}
