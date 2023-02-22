#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal);

int main(int argc, char* argv[])
{
    cout << solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl;
    cout << solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl;

    return 0;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int i = 0, j = 0;
    size_t nGoal = goal.size();
    size_t nCards1 = cards1.size(), nCards2 = cards2.size();

    while (i + j < nGoal)
        if (i < nCards1 && cards1[i] == goal[i + j])
            ++i;
        else if (j < nCards2 && cards2[j] == goal[i + j])
            ++j;
        else
            return "No";

    return "Yes";
}
