#include <iostream>
#include <vector>
#include <unordered_set>

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
    unordered_multiset<string> umset(participant.begin(), participant.end());

    for (string& s : completion)
        umset.erase(umset.find(s));

    return *umset.begin();
}
