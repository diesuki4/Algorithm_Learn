#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic);

int main(int argc, char* argv[])
{
    cout << solution({"p", "o", "s"}, {"sod", "eocd", "qixm", "adio", "soo"}) << endl;
    cout << solution({"z", "d", "x"}, {"def", "dww", "dzx", "loveaw"}) << endl;
    cout << solution({"s", "o", "m", "d"}, {"moos", "dzx", "smm", "sunmmo", "som"}) << endl;
}

int solution(vector<string> spell, vector<string> dic)
{
    for (string word : dic)
    {
        bool bFound = true;

        for (string alpha : spell)
        {
            if (word.find(alpha) == string::npos)
            {
                bFound = false;
                break;
            }
        }

        if (bFound)
            return 1;
    }       

    return 2;
}
