#include <iostream>
#include <vector>
#include <algorithm>

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
    size_t size = completion.size();

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < size; ++i)
        if (participant[i] != completion[i])
            return participant[i];

    return participant[0];
}
