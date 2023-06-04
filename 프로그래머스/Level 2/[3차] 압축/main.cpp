#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

void print(vector<int> result);
vector<int> solution(string msg);

int main(int argc, char* argv[])
{
    print(solution("KAKAO"));
    print(solution("TOBEORNOTTOBEORTOBEORNOT"));
    print(solution("ABABABABABABABAB"));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(string msg)
{
    vector<int> answer;
    int cur = 1;
    unordered_map<string, int> dict;
    deque<char> Msg(msg.begin(), msg.end());

    for (char c = 'A'; c <= 'Z'; ++c)
        dict[string(1, c)] = cur++;

    while (!Msg.empty())
    {
        string s(1, Msg.front()); Msg.pop_front();
        
        while (!Msg.empty() && dict[s + Msg.front()])
            s += Msg.front(), Msg.pop_front();

        answer.emplace_back(dict[s]);

        if (!Msg.empty())
            dict[s + Msg.front()] = cur++;
    }

    return answer;
}
