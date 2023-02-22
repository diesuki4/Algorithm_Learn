#include <iostream>
#include <vector>

using namespace std;
using vsIterator = vector<string>::iterator;

string rDFS(vsIterator vsIt1, vsIterator vsIt2, vsIterator vsItGoal,
            vsIterator vsIt1End, vsIterator vsIt2End, vsIterator vsItGoalEnd);
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal);

int main(int argc, char* argv[])
{
    cout << solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl;
    cout << solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl;

    return 0;
}

string rDFS(vsIterator vsIt1, vsIterator vsIt2, vsIterator vsItGoal,
            vsIterator vsIt1End, vsIterator vsIt2End, vsIterator vsItGoalEnd)
{
    if (vsItGoal == vsItGoalEnd)
        return "Yes";

    if (vsIt1 != vsIt1End && *vsIt1 == *vsItGoal)
        return rDFS(++vsIt1, vsIt2, ++vsItGoal, vsIt1End, vsIt2End, vsItGoalEnd);
    else if (vsIt2 != vsIt2End && *vsIt2 == *vsItGoal)
        return rDFS(vsIt1, ++vsIt2, ++vsItGoal, vsIt1End, vsIt2End, vsItGoalEnd);
    else
        return "No";
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    return rDFS(cards1.begin(), cards2.begin(), goal.begin(),
                cards1.end(), cards2.end(), goal.end());
}
