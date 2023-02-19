#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main(int argc, char* argv[])
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl;
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl;
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl;

    return 0;
}

string solution(vector<string> participant, vector<string> completion)
{
    char c[21] = {0};

    for (string s : participant)
        for (int i = 0; i < s.size(); ++i)
            c[i] ^= s[i];

    for (string s : completion)
        for (int i = 0; i < s.size(); ++i)
            c[i] ^= s[i];

    return string(c);
}
