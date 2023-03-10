#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Personality;

string solution(vector<string> survey, vector<int> choices);

int main(int argc, char* argv[])
{
    cout << solution({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5}) << endl;
    cout << solution({"TR", "RT", "TR"}, {7, 1, 3}) << endl;

    return 0;
}

class Personality
{
    int scores[4] = {0};

public:
    Personality() {}

    bool isReversed(string& survey)
    {
        return (survey[0] == 'T') || (survey[0] == 'F') ||
               (survey[0] == 'M') || (survey[0] == 'N');
    }

    int& operator [] (string& survey)
    {
        const char* c_string = survey.c_str();

        if (strchr(c_string, 'R'))
            return scores[0];
        else if (strchr(c_string, 'C'))
            return scores[1];
        else if (strchr(c_string, 'J'))
            return scores[2];
        else if (strchr(c_string, 'A'))
            return scores[3];
    }

    string operator * ()
    {
        string s = "";

        s += (scores[0] <= 0) ? 'R' : 'T';
        s += (scores[1] <= 0) ? 'C' : 'F';
        s += (scores[2] <= 0) ? 'J' : 'M';
        s += (scores[3] <= 0) ? 'A' : 'N';

        return s;
    }
};

string solution(vector<string> survey, vector<int> choices)
{
    size_t size = survey.size();
    Personality personality;

    for (int i = 0; i < size; ++i)
        personality[survey[i]] += personality.isReversed(survey[i]) ? -(choices[i] - 4) : (choices[i] - 4);

    return *personality;
}
